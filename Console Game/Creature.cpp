#include "Creature.hpp"
#include "Toolbox.hpp"

Creature::Creature(){ // конструктор по умолчанию
    health_points = 1;
    damage_min = damage_max = 1;// минимальный и макимальный урон равны 1
    dodge_chance = 0;
    crit_chance = 0;
    icon = ' ';
}

unsigned Creature::hit(Creature& target) const { // функция проверка промоха и критического удара
   if (tb::chance(target.dodge_chance))  // вероятность промаха противника
       return 0;
    unsigned damage = damage_min == damage_max ? damage_min : tb::rand(damage_min, damage_max + 1); // генер. случ число отвечающее за урон. по этому 
        if (damage == 0)
            return 0;

        if (tb::chance(crit_chance)) // проверка критического удара
            damage *= 2; // увеличиваем урон на 2
        target.take_damage(damage); // противник получает урон
        return damage;
}

void Creature::take_damage(unsigned damage){
    health_points -= damage > health_points ? health_points : damage; 
}

unsigned Creature::getHP() const {
    return health_points;
}
