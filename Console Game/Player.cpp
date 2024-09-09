#include "Player.hpp"
#include "Toolbox.hpp"
#include "EnemiesStats.hpp"
#include <string>

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
	tb::place_text(x, 1, std::string ("Health points: ") + std::to_string(health_points));
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
		// TODO: battle();
	}
	field.setCell(x, y, ' ');
	tb::place_text(x, y, ' ');


	switch (direction) {
	case UP:    y -= 1; break;
	case RIGHT: x += 2; break;
	case DOWN:  y += 1; break;
	case LEFT:  x -= 2; break;
	default:    throw std::exception("invalid player directoin");
	}
	field.setCell(x, y, icon);
	tb::place_text(x, y, icon);

	if (x == field.getStartX() && y == field.getStartY()) {
		next_round();
		tb::place_cursor(0, 0);
		field.printField();
		print_stats();
	}

	tb::place_cursor(0, 0);
}

void Player::battle() {

}
