#pragma once


namespace tb {
	// Возвращает случайное целое положительное число от 0 до end не включительно
	unsigned rand(unsigned end); 
	// Возвращает случайное целое положительное число отbegin до end не включительно
	unsigned rand(unsigned begin, unsigned end); 
	// Возвращает true с вероятностью в percent процентов 
	bool chance(unsigned percent); 
	// Перемещает курсор в консоли на координаты х и у
	void place_cursor(unsigned x, unsigned y);
	// Располагает текст в консоли на позиции х и у 
	void place_text(unsigned x, unsigned y, const char* text);
	//Располагает обратный отсчет с delay секунд до 0 секунд в консоли на позиции х и у.
	void place_timer(unsigned x, unsigned y, unsigned delay, const char* text = "0");
}





