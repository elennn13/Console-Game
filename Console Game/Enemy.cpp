#include "Enemy.hpp"

Enemy::Enemy(char icon){ 
    this->icon = icon;
}

Enemy::Enemy(unsigned health_points, 
    unsigned damage_min, unsigned dodge_chance, 
    unsigned crit_chance, char icon, std::string name) {
    this->health_points = health_points;
    this->damage_min = damage_min;
    this->damage_max = damage_max;
    this->dodge_chance = dodge_chance;
    this->crit_chance = crit_chance;
    this->icon = icon;
    this->name = name;
}

void Enemy::print_stats() const { // рисвание в консоли
    // TODO осуществить вывод характеристик
}

char Enemy::getIcon() const {

    return icon;
}

const std::string& Enemy::getName() const {

    return name;
}
