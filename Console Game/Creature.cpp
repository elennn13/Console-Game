#include "Creature.hpp"


Creature::Creature(){ // ����������� �� ���������
    health_points = 1;
    damage_min = damage_max = 1;// ����������� � ����������� ���� ����� 1
    dodge_chance = 0;
    crit_chance = 0;
}

unsigned Creature::hit(Creature& target) const { // ������� �������� ������� � ������������ �����
    // TODO
        return 0;
}

void Creature::take_damage(unsigned damage){
    health_points -= damage > health_points ? health_points : damage; 
}
