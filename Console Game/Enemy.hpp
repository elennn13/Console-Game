#pragma once
#include "Creature.hpp"
#include <string>


class Enemy : public Creature {

private:
	
	std::string name;

public:
	Enemy(char icon); // конструктор
	Enemy(unsigned health_points, unsigned damage_min, // параметрический конструктор принимает иконку и здоровье и тд 
		unsigned dodge_chance, unsigned crit_chance, 
		char icon, std::string name); 
	 // констурктор копирования
	void print_stats() const override;
	// сеттеры геттеры
	char getIcon() const;
	const std::string& getName() const;




};

