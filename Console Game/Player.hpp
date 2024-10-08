#pragma once
#include "Creature.hpp"
#include"Field.hpp"

// ��������� ��� �������������:

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3
#define START_PLAYER_HP 5




class Player : public Creature { // ����� �����

private:
	unsigned x, y;   // ���������� �������������� ������ �� �����
	unsigned direction; // ����������� ��������  �� �����: 0- �����, 1- ������, 2- ����, 3- �����.
	unsigned max_hp; // ������� ��������, �� �������� ����������������� ����� ����� ���
	unsigned lvl;    // �������  ������. ���������� ����� ���
	unsigned round;  // ������� �����. ����������� ��� ����������� ����� ����� �����
	// 
	char getRandomEnemyType() const;// ���������������� ���������� ����������

	// ��������� ������
	void next_round();
	// ��������� ������ ����� ����������
	char next_cell() const;
public:
	Player(); // ����������� �� ���������
	void print_stats() const override;
// ������������ ������ �� ������� ����
	void startPlace(Field& field); 
//	�������� ������ �� ��� ����
	void move();
// 
	void battle(char enemy_type);
	// 
	void upgrade(unsigned y);



};

