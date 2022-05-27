#include <iostream>
#include "gamemap.h"
#include "base_functions.h"

int main()
{
    srand(time(NULL));
    int input_height = int_value_checker("What map height would you like? Values must be between 5 and 25: ", 5, 25);
    int input_width = int_value_checker("What map width would you like? Values must be between 5 and 50: ", 5, 50);
    gamemap game(input_height, input_width);
    game.run_game();
}