#pragma once
#include "Creature.hpp"
#include"Field.hpp"

// Директивы для интуитивности:

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3
#define START_PLAYER_HP 5




class Player : public Creature { // класс игрок

private:
	unsigned x, y;   // координата местоположения игрока на карте
	unsigned direction; // направление движения  по карте: 0- вверх, 1- вправо, 2- вниз, 3- влево.
	unsigned max_hp; // уровень здоровья, до которого восстонавливается игрок после боя
	unsigned lvl;    // уровень  игрока. повышается после боя
	unsigned round;  // игровой раунд. повышвается при прохождении всего круга карты
	// 
	char getRandomEnemyType() const;// функцияполучения случайного противника

	// повышение уровня
	void next_round();
	// получение ячейки перед персонажем
	char next_cell() const;
public:
	Player(); // конструктор по умолчанию
	void print_stats() const override;
// расположение игрока на игровом поле
	void startPlace(Field& field); 
//	движение игрока по игр полю
	void move();
// 
	void battle(char enemy_type);
	// 
	void upgrade(unsigned y);



};

