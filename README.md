Game of Life simulation, done for The Software Institute training.

There are four cpp files, which handle:
main.cpp: Seeds the random number generator, gets user input for the map height and width, creates the map and runs the game.

base_functions.cpp: Has two functions, one which takes and sanitises an integer input, and the other which calls that function but ensures the entered value is within a given range.

map_types.cpp: Contains the function which generates the initial map, with either a preset or randomly generated tiles.

gamemap.cpp: Contains an gamemap class, which holds the display vector and calculation vector, both of which are 2D vectors of booleans, which are used to display the current game state and calculate the next game state respectively. The class' methods handle the displaying of the display vector, the calculation of the next state and the displaying of the menu. The game can be run either automatically, in which state pressing any key will open up the menu and pause the game, or requiring the user to press a key to progress to the next step.