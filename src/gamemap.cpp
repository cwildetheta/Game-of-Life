#include "gamemap.h"
#include "base_functions.h"
#include "map_types.h"
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <conio.h>

gamemap::gamemap(int height_input, int width_input) : height(height_input), width(width_input) {
    std::string template_message = "Which template would you like to use? \n1 for random tiles. \n2 for preset 1. \n";
    int template_num = int_value_checker(template_message, 1, 2);
    display_vector = generate_map(template_num, height, width, boundary);
}
void gamemap::run_game(){
    char input_auto_run = 'n';
    std::cout << "Would you like to manually control the turns? ";
    std::cin >> input_auto_run;
    if(input_auto_run == 'y'){
        auto_run = false;
    }
    start_state = display_vector;
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
            //std::this_thread::sleep_for(std::chrono::seconds(1));
            while(((clock() - start) / CLOCKS_PER_SEC) <= 0.8){
                if(_kbhit()){
                    display_menu();
                }
            }
        }
    }
}
void gamemap::display_map(){
    std::cout << char(218);
    for(int l = 0; l < width; l++){
        std::cout << char(196) << char(196);
    }
    std::cout << char(191) << std::endl;
    for(int i = 0; i < height; i++){
        std::cout << char(179);
        for(int k = 0; k < width; k++){
            if(display_vector[i+boundary][k+boundary] == true){
                std::cout << char(254) << " ";
            }
            else{
                std::cout << "  ";
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
int gamemap::calculate_neighbours(int height, int width){
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
void gamemap::calculate_state(){
    for(int i = 0; i < (height+(2*boundary)); i++){
        calculation_vector.push_back(std::vector<bool>());
        for(int k = 0; k < (width+(2*boundary)); k++){
            if((i == 0) || (i == ((height+(2*boundary))-1)) || (k == 0) || (k == ((width+(2*boundary))-1))){
                calculation_vector[i].push_back(false);
            }
            else{
                int neighbours = calculate_neighbours(i,k);
                if((display_vector[i][k] == true) && (neighbours > 1) && (neighbours < 4)){
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
void gamemap::display_menu()
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