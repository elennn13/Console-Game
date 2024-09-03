#include "Creature.hpp"


Creature::Creature(){ // конструктор по умолчанию
    health_points = 1;
    damage_min = damage_max = 1;// минимальный и макимальный урон равны 1
    dodge_chance = 0;
    crit_chance = 0;
}

unsigned Creature::hit(Creature& target) const { // функция проверка промоха и критического удара
    // TODO
        return 0;
}

void Creature::take_damage(unsigned damage){
    health_points -= damage > health_points ? health_points : damage; 
}
