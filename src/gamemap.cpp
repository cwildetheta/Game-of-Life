#include "gamemap.h"
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

gamemap::gamemap(int height_input, int width_input) : height(height_input), width(width_input) {
    for(int i = 0; i < height; i++){
        display_vector.push_back(std::vector<bool>());
        for(int k = 0; k < width; k++){
            display_vector[i].push_back(false);
        }
    }
    display_vector[6][7] = true;
    display_vector[7][6] = true;
    display_vector[7][7] = true;
    display_vector[7][8] = true;
}
void gamemap::run_game(){
    bool game_state = true, auto_run = true;
    char input_auto_run = 'n';
    std::cout << "Would you like to manually control the turns? ";
    std::cin >> input_auto_run;
    if(input_auto_run == 'y'){
        auto_run = false;
    }
    while(game_state == true){
        system("cls");
        display_map();
        if(auto_run == false){
            char input_turn = 'e';
            std::cout << "Next turn? ";
            std::cin >> input_turn;
            if(input_turn == 'y'){
                calculate_state();
                display_vector = std::move(calculation_vector);
            }
            else{
                game_state = false;
            }
        }
        else{
            std::this_thread::sleep_for(std::chrono::seconds(1));
            calculate_state();
            display_vector = std::move(calculation_vector);
        }
    }
}
void gamemap::display_map(){
    for(auto row_obj : display_vector){
        for(auto elem : row_obj){
            if(elem == true){
                std::cout << char(254) << " ";
            }
            else{
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
    }
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
    for(int i = 0; i < height; i++){
        calculation_vector.push_back(std::vector<bool>());
        for(int k = 0; k < width; k++){
            if((i == 0) || (i == (height-1)) || (k == 0) || (k == (width-1))){
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