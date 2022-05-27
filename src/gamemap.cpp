#include "gamemap.h"
#include "base_functions.h"
#include "map_types.h"
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <conio.h>

gamemap::gamemap(int height_input, int width_input) : height(height_input), width(width_input)
{
    std::string template_message = "Which template would you like to use? \n1 for random tiles. \n2 for preset 1. \n";
    int template_num = int_value_checker(template_message, 1, 2);
    display_vector = generate_map(template_num, height, width, boundary);
}
void gamemap::run_game() //The main game loop.
{
    char input_auto_run = 'n';
    std::cout << "Would you like to manually control the turns? y for yes, otherwise no: ";
    std::cin >> input_auto_run;
    if((input_auto_run == 'y') || (input_auto_run == 'Y')){
        auto_run = false;
    }
    start_state = display_vector; //Saving the starting state so the game can be restarted.
    while(game_state == true){
        system("cls");
        display_map();
        if(auto_run == false){
            char input_turn = 'e';
            std::cout << "Next turn? y for yes, m for menu, any other key to quit: ";
            std::cin >> input_turn;
            if((input_turn == 'y') || (input_turn == 'Y')){
                calculate_state();
                display_vector = std::move(calculation_vector);
            }
            else if((input_turn == 'm') || (input_turn == 'M')){
                display_menu();
            }
            else{
                game_state = false;
            }
        }
        else{
            calculate_state();
            display_vector = std::move(calculation_vector);
            clock_t start = clock();
            while(((clock() - start) / CLOCKS_PER_SEC) <= 0.8){ //Game will run automatically until the user presses a key, at which point it displays the menu and waits for their input. The menu thus also functions as a pause.
                if(_kbhit()){
                    display_menu();
                }
            }
        }
    }
}
void gamemap::display_map() //All of the char() outputs in this function, with the exception of char(254), are setting up the outside box of the display.
{
    std::cout << char(218);
    for(int l = 0; l < width; l++){
        std::cout << char(196) << char(196);
    }
    std::cout << char(191) << std::endl;
    for(int i = 0; i < height; i++){
        std::cout << char(179);
        for(int k = 0; k < width; k++){
            if(display_vector[i+boundary][k+boundary] == true){ //Only a subset of the full map is shown, hence the +boundary modifications.
                std::cout << char(254) << " "; //Char(254) is a cube, which shows the alive cells.
            }
            else{
                std::cout << "  "; //Empty cells are just blank.
            }
        }
        std::cout << char(179) << std::endl;
    }
    std::cout << char(192);
    for(int l = 0; l < width; l++){
        std::cout << char(196) << char(196);
    }
    std::cout << char(217) << std::endl;
}
int gamemap::calculate_neighbours(int height, int width) //Calculates how many of a given tile's neighbours are alive.
{
    int neighbours = 0;
    for(int l = 0; l < 3; l++){
        for(int m = 0; m < 3; m++){
            if((l == 1) && (m == 1)){}
            else{
                if((display_vector[height-1+l][width-1+m] == true)){
                    neighbours++;
                }
            }
        }
    }
    return neighbours;
}
void gamemap::calculate_state() //Calculates the next iteration of the game, which will then be copied into the display vector.
{
    for(int i = 0; i < (height+(2*boundary)); i++){
        calculation_vector.push_back(std::vector<bool>());
        for(int k = 0; k < (width+(2*boundary)); k++){
            if((i == 0) || (i == ((height+(2*boundary))-1)) || (k == 0) || (k == ((width+(2*boundary))-1))){ //The outer edge tiles are set to false by default. These are seperated from the displayed area by the boundary.
                calculation_vector[i].push_back(false);
            }
            else{
                int neighbours = calculate_neighbours(i,k);
                if((display_vector[i][k] == true) && (neighbours > 1) && (neighbours < 4)){ //Implementing the rules of the game.
                    calculation_vector[i].push_back(true);
                }
                else if((display_vector[i][k] == false) && (neighbours == 3)){
                    calculation_vector[i].push_back(true);
                }
                else{
                    calculation_vector[i].push_back(false);
                }
            }
        }
    }
}
void gamemap::display_menu() //The menu output (doubles as a pause).
{
    std::cout << "Press r to restart." << std::endl;
    std::cout << "Press m to toggle manual progression." << std::endl;
    std::cout << "Press q to quit." << std::endl;
    std::cout << "Press any other key to resume." << std::endl;
    char char_input;
    std::cin >> char_input;
    switch(char_input){
        case 'r':
        case 'R':{
            display_vector = start_state;
            break;
        }
        case 'm':
        case 'M':{
            if(auto_run == true){
                auto_run = false;
            }
            else{
                auto_run = true;
            }
            break;
        }
        case 'q':
        case 'Q':{
            game_state = false;
            break;
        }
        default:{
            break;
        }
    }
}