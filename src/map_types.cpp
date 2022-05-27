#include "map_types.h"
#include "base_functions.h"

std::vector<std::vector<bool>> generate_map(int template_number, int height, int width, int boundary)
{
    std::vector<std::vector<bool>> display_vector;
    for(int i = 0; i < (height+(2*boundary)); i++){ //Establish the blank vector.
        display_vector.push_back(std::vector<bool>());
        for(int k = 0; k < (width+(2*boundary)); k++){
            display_vector[i].push_back(false);
        }
    }
    switch(template_number){
        case 1:{ //Random tiles filled.
            int chance = int_value_checker("What chance do you want there to be for a random tile to be alive? Integer between 1 and 100: ", 1, 100);
            for(auto &row : display_vector){
                for(auto elem : row){
                    if(rand()%100 < chance){
                        elem = true;
                    }
                }
            }
        }
        case 2:{ //A preset pattern with interesting evolution.
            display_vector[(height/2)-1+boundary][(width/2)+boundary] = true;
            display_vector[(height/2)+boundary][(width/2)-1+boundary] = true;
            display_vector[(height/2)+boundary][(width/2)+boundary] = true;
            display_vector[(height/2)+boundary][(width/2)+1+boundary] = true;
            display_vector[(height/2)+1+boundary][(width/2)-1+boundary] = true;
            display_vector[(height/2)+1+boundary][(width/2)+1+boundary] = true;
            break;
        }
        default:{
            break;
        }
    }
    return display_vector;
}