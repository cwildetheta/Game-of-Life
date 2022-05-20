#include <iostream>
#include <vector>
#include "gamemap.h"

int main()
{
    /*std::vector<std::vector<bool>> bool_1 = {{false, false, false, false, false}, {false, true, false, false, false}};
    std::vector<std::vector<bool>> bool_2;
    bool run = true;
    while(run == true){
        // for(int i = 0; i < 2; i++){
        //     for(int k = 0; k < 5; k++){
        //         std::cout << bool_1[i][k] << " ";
        //     }
        //     std::cout << std::endl;
        // }
        for(auto row_obj : bool_1){
            for(auto elem : row_obj){
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        }
        char input = 'e';
        std::cout << "Run again: ";
        std::cin >> input;
        if(input == 'y'){
            int num_input_1 = 0, num_input_2 = 0;
            std::cout << "Please enter a number between 1 and 2: ";
            std::cin >> num_input_1;
            std::cout << "Please enter a number between 1 and 5: ";
            std::cin >> num_input_2;
            if((num_input_1 > 0) && (num_input_1 < 3) && (num_input_2 > 0) && (num_input_2 < 6)){
                std::cout << "bool_2 length: " << bool_2.size() << std::endl;
                for(int i = 0; i < 2; i++){
                    bool_2.push_back(std::vector<bool>());
                    for(int k = 0; k < 5; k++){
                        std::cout << "In loop run " << (k+1) << std::endl;
                        if(((i+1) == num_input_1) && ((k+1) == num_input_2)){
                            bool_2[i].push_back(true);
                        }
                        else{
                            bool_2[i].push_back(false);
                        }
                    }
                }
                std::cout << "Finished looping." << std::endl;
                std::cout << "Before move." << std::endl;
                bool_1 = std::move(bool_2);
                std::cout << "After move." << std::endl;
            }
            else{
                run = false;
            }
        }
        else{
            run = false;
        }
    }*/
    gamemap test_game(15, 15);
    test_game.run_game();
    for(int i = 0; i < 255; i++){
        std::cout << i << ": " << char(i) << "  ";
    }
}