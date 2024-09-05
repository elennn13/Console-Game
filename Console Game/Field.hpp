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


	// геттеры для ширины и высоты
	size_t getWidth() const;
	size_t getHeight() const;


};

