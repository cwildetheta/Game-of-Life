#include "../include/base_functions.h"
#include <iostream>
#include <limits>

int int_inputter(const std::string& request_output) //Gets an integer input from the user, checks to make sure a char or string isn't entered.
{
    bool in_int_loop = true;
    int int_input;
    while(in_int_loop == true){
        std::cout << request_output;
        std::cin >> int_input;
        if(std::cin.fail()){
            std::cout << "You did not enter an integer." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else{
            in_int_loop = false;
        }
    }
    return int_input;
}

int int_value_checker(const std::string& request_output, int lower_bound, int upper_bound) //Calls the above function, but also checks the input to make sure it's within a given range.
{
    while(true){
        int value = int_inputter(request_output);
        if(value < lower_bound){
            std::cout << "The entered value must be above " << lower_bound << "." << std::endl;
        }
        else if(value > upper_bound){
            std::cout << "The entered value must be below " << upper_bound << "." << std::endl;
        }
        else{
            return value;
        }
    }
}