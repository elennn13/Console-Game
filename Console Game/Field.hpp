#pragma once
#include <vector>


class Field { // класс карта

private:
	std::vector<std::vector<char>> data;
	unsigned start_x;
	unsigned start_y;

public:
	Field(unsigned width, unsigned height, unsigned offsetWidth = 0, unsigned offsetHeight = 0);
	void printField() const; // выводим поле в консоль
	// установка иконки на карте по переданным кооридинатам
	void setCell(unsigned x, unsigned y, char icon);

	// Установка иконки на карте  по переданным координатам
	char getCell(unsigned x, unsigned y) const;
	// геттеры для ширины и высоты
	size_t getWidth() const;
	size_t getHeight() const;
	unsigned getStartX() const;
	unsigned getStartY() const;
};

