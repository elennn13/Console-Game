#include <iostream>
#include <Windows.h>
#include "Toolbox.hpp"
#include "Field.hpp"
#include "Player.hpp"


#define GAME_SPEED 350 // задержка между шагами в мсек. чем меньше, тем быстрее

Field field(6, 5, 3, 3);
Player player;


int main(){

    

    player.startPlace(field);
    field.printField();
    player.print_stats();

    try {
        while (true) { // TODO поменять условие
            player.move();
            Sleep(GAME_SPEED);

        }

    }
    catch (const std::exception& ex) {
        // TODO
    }





    tb::place_cursor(0, field.getHeight() + 3); //  перемещения курсора вниз



    return 0;
}

