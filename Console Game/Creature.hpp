#pragma once


class Creature{

protected:
	unsigned health_points; // текущее количество очков здоровья
	unsigned damage_min;    // урон минимальный ущерб, который способно нанести существо своей атакой
	unsigned damage_max;    // урон максимальный ущерб, который способно нанести существо своей атакой
	unsigned dodge_chance;  // вероятность в процентах полнгостью увернуться от атаки противника
	unsigned crit_chance; // вероятность (в процентах) нанести при атаке двойной ущерб
public:
	
	Creature(); // конструктор по умолчанию.
	virtual unsigned hit(Creature& target) const; // метод атаки другого существа
	virtual void take_damage(unsigned damage); // метод получения ущерба 
	virtual void print_stats() const = 0; // метод выводит характеристики существа на экран. метод чисто вирутальный
};

