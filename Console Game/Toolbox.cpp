#include "Toolbox.hpp"
#include <random> // гениратор случайных чисел 
#include <Windows.h>
#include <string>


unsigned tb::rand(unsigned end) {
    return tb::rand(0,end);
}

unsigned tb::rand(unsigned begin, unsigned end){
    std::random_device rd; // типа устройства для генерации случ. числа
    std::mt19937 generator(rd()); // генератор случ. чисел
    std::uniform_int_distribution<> dist(begin, end - 1); // 
    return dist(generator);
}

bool tb::chance(unsigned percent){

    return tb::rand(101) <= percent; 
}

void tb::place_cursor(unsigned x, unsigned y){
    static HANDLE handler = GetStdHandle(STD_OUTPUT_HANDLE); // HANDLE-объект структуры//создаем объект для управления курсором // (STD_OUTPUT_HANDLE вывод)
    COORD coord{ x, y }; // координаты
    SetConsoleCursorPosition(handler, coord); // установить позицию курсора консоли//переместить курсор на координаты coord

}



void tb::place_timer(unsigned x, unsigned y, unsigned delay, const char* text) {
    for (unsigned s = delay; s > 0; --s) { // s- секунда
        std::string tmp = std::to_string(s);
        place_text(x, y, (tmp + "...").c_str());
        Sleep(1000); // останавливает прилоржение на секунду
    }
    tb::place_text(x, y, text);
}
