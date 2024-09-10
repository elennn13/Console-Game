#include "Player.hpp"
#include "Enemy.hpp"
#include "Toolbox.hpp"
#include "EnemiesStats.hpp"
#include "Upgrades.hpp"
#include <string>
#include <Windows.h>

#define BATTLE_SPEED 1000 // задержка между ударами в мсек чем меньше тем быстрее

extern Field field; // обявление переменной созданной в другом файле/подключаем


char Player::getRandomEnemyType() const {
	return es::types[tb::rand(es::types_number)];
}

void Player::next_round() {
	if (++round == 10) {
		// TODO: программа для босса
		return;
	}
	// Добавление противника слева
	unsigned tmp = tb::rand(2, field.getHeight() - 2);
	field.setCell(2, tmp, getRandomEnemyType()); // устан на карте точку

	// Добавление противника справа
	tmp = tb::rand(2, field.getHeight() - 2);
	field.setCell(field.getWidth() - 3, tmp, getRandomEnemyType());

	// Добавление противника вверху
	tmp = tb::rand(4, field.getWidth() - 3);
	if (tmp % 2) --tmp;
	field.setCell(tmp, 1, getRandomEnemyType());
}

char Player::next_cell() const {

	switch (direction) {
	case UP:    return field.getCell(x, y - 1);
	case RIGHT: return field.getCell(x + 2, y);
	case DOWN:  return field.getCell(x, y + 1);
	case LEFT:  return field.getCell(x - 2, y);
	default:    throw std::exception("invalid player directoin");
	}
}

Player::Player() {
	x = y = 0;
	direction = RIGHT;
	health_points = max_hp = START_PLAYER_HP;
	lvl = 1;
	round = 0;
	icon = 'H';
}

void Player::print_stats() const {
	unsigned x = field.getWidth() + 5;
	tb::place_text(x, 0, "--PLAYER-STATS--");
	tb::place_text(x, 1, std::string("Health points: ") + std::to_string(health_points));
	tb::place_text(
		x, 2, std::string("Damage: ") +
		(damage_min == damage_max ?
			std::to_string(damage_min) :
			(std::to_string(damage_min) + '-' + std::to_string(damage_max)))
	);
	tb::place_text(x, 3, std::string("Dodge chance: ") +
		std::to_string(dodge_chance));
	tb::place_text(x, 4, std::string("Crit chance: ")
		+ std::to_string(crit_chance));
	tb::place_text(x, 5, std::string("LVL: ")
		+ std::to_string(lvl));
	tb::place_text(x, 6, std::string("Round ")
		+ std::to_string(round));

}

void Player::startPlace(Field& field) {
	x = field.getStartX();
	y = field.getStartY();
	field.setCell(x, y, icon);
	next_round();
}

void Player::move() {
	if (next_cell() == '#') {
		if (direction == UP)
			direction = LEFT;
		else
			--direction;
	}
	if (next_cell() == 'B') {
		// TODo: bossFight();

	}
	else if (next_cell() != ' ') { // TODO: проверить на врага
		battle(next_cell());
		field.printField();
		print_stats();
	}

	field.setCell(x, y, ' ');
	tb::place_text(x, y + 1, ' ');


	switch (direction) {
	case UP:    y -= 1; break;
	case RIGHT: x += 2; break;
	case DOWN:  y += 1; break;
	case LEFT:  x -= 2; break;
	default:    throw std::exception("invalid player directoin");
	}

	field.setCell(x, y, icon);
	tb::place_text(x, y + 1, icon);

	if (x == field.getStartX() && y == field.getStartY()) {
		next_round();
		tb::place_cursor(0, 0);
		field.printField();
		print_stats();
	}

	tb::place_cursor(0, 0);
}

void Player::battle(char enemy_type) {
	system("cls"); // полность очищает консоль от какого либо действия
	tb::place_title(0, 0, "BATTLE", field.getWidth());
	print_stats();

	// создаем противника 
	Enemy enemy(next_cell(), lvl);
	enemy.print_stats();

	tb::place_title(0, 1, "Player vs " + enemy.getName(), field.getWidth());

	std::string status_bar;
	status_bar += icon;
	status_bar += "    ";
	status_bar += enemy.getIcon();
	tb::place_title(0, 3, status_bar, field.getWidth());

	unsigned log_y = 5; // координаты вывода отчетов о битве  
	bool player_turn = false;

	while (health_points > 0 && enemy.getHP() > 0) {
		if (player_turn) {
			status_bar.replace(2, 2, "->"); // если ход игрока
			tb::place_cursor(0, log_y++);
			std::cout << "Player hits: " << hit(enemy);
		}
		// если не ход игрока
		else {
			status_bar.replace(2, 2, "<-");
			tb::place_cursor(0, log_y++);
			std::cout << enemy.getName() << " hits: " << enemy.hit(*this);
		}
		tb::place_title(0, 3, status_bar, field.getWidth());
		player_turn = !player_turn;
		Sleep(BATTLE_SPEED); // усыпить программу

		print_stats();
		enemy.print_stats();

	}
	tb::place_cursor(0, log_y);

	if (health_points <= 0) { // если мало жизней 

		std::cout << enemy.getName() << "wins!";
		Sleep(BATTLE_SPEED * 3);
		system("cls");
		throw std::exception("defeat"); // TODO: реализорвать свой класс итогов игры
	}
	std::cout << "Player wins!";

	log_y += 2;
	upgrade(log_y);
	Sleep(BATTLE_SPEED * 3);
	system("cls");

}

void Player::upgrade(unsigned y) {
	tb::place_cursor(0, y);
	std::cout << "LVL UP! (" << ++lvl << ")\n";
	std::cout << "Chose power up:\n";

	// этап 1. случайная генерация улучшений

	unsigned up1, up2;
	bool done = false; // сгенерировано ли число

	do {
		up1 = tb::rand(up::ups_number);
		if (up1 == 3 && dodge_chance >= up::dodge_max)
			continue;
		if (up1 == 4 && crit_chance >= up::crit_max)
			continue;
		done = true;
	} while (!done);

	done = false;

	do {
		up2 = tb::rand(up::ups_number);
		if (up2 == up1)
			continue;
		if (up2 == 3 && dodge_chance >= up::dodge_max)
			continue;
		if (up2 == 4 && crit_chance >= up::crit_max)
			continue;
		done = true;
	} while (!done);

	std::cout << "1)" << up::upgrades[up1] << std::endl;
	std::cout << "2)" << up::upgrades[up2] << std::endl;

	// этап2. выбор улучшения пользователем

	std::string choice;
	do {
		std::cout << "Enter number -> ";
		std::getline(std::cin, choice);
		if (choice != "1" && choice != "2") {
			std::cout << "INCORRECT! TRY AGAIN.\n"; //некорректный ввод, попробуй еще раз.
		}
	} while (choice != "1" && choice != "2");

	// этап3. улучшение характеристик
	unsigned selected = choice == "1" ? up1 : up2;
	switch (selected) {
	case 0:
		std::cout << "Your max health increased from " << max_hp << " to " << max_hp + up::hp_up;
		max_hp += up::hp_up;
		break;
	case 1:
		if (damage_min >= damage_max) {
			std::cout << "You min damage equals\nmax damage. Max damage increased\nfrom " << damage_max << "to " <<
				damage_max + up::dmg_up;
			break;
		}
		std::cout << "Your min damage increased from " << damage_min << " to " << damage_min + up::dmg_up;
		damage_min += up::dmg_up;
		break;
	case 2:
		std::cout << "Your max damage increased from " << damage_max << " to " << damage_max + up::dmg_up;
		damage_max += up::dmg_up;
		break;
	case 3:
		std::cout << "Your dodge chance increased from " << dodge_chance << " to " << dodge_chance + up::dodge_up;
		dodge_chance += up::dodge_up;
		break;
	case 4:
		std::cout << "Your crit chance increased from " << crit_chance << " to " << crit_chance + up::crit_up;
		crit_chance += up::crit_up;
		break;
	default:
		throw std::exception("invalid upgrade number");
	}

	// Этап4. автоапгрейды
	std::cout << "\n AUTO UPGRADES:\n";
	std::cout << "Max health: " << max_hp << " -> " << max_hp + up::auto_hp_up << std::endl;
	max_hp += up::auto_hp_up;

	if (crit_chance < up::crit_max) {
		std::cout << "Crit chance: " << crit_chance << " -> " << crit_chance + up::auto_crit_up << std::endl;

		crit_chance += up::auto_crit_up;
	}

	health_points = max_hp;
}
