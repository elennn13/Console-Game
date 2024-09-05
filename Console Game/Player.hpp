#pragma once
#include "Creature.hpp"


class Player : public Creature { // класс игрок

private:
	unsigned x, y;   // координата местоположения игрока на карте
	unsigned direction; // направление движения  по карте
	unsigned max_hp; // уровень здоровья, до которого восстонавливается игрок после боя
	unsigned lvl;    // уровень  игрока. повышается после боя
	unsigned round;  // игровой раунд. повышвается при прохождении всего круга карты
	
public:
	Player(); // конструктор по умолчанию

	void print_stats() const override;




};

