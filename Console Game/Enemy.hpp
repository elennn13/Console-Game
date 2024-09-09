#pragma once
#include "Creature.hpp"
#include <string>


class Enemy : public Creature {

private:
	
	std::string name;

public:
	Enemy(char icon); // �����������
	Enemy(unsigned health_points, unsigned damage_min, // ��������������� ����������� ��������� ������ � �������� � �� 
		unsigned dodge_chance, unsigned crit_chance, 
		char icon, std::string name); 
	 // ����������� �����������
	void print_stats() const override;
	// ������� �������
	char getIcon() const;
	const std::string& getName() const;




};

