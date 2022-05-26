#ifndef GAMEMAP_H_INCLUDED
#define GAMEMAP_H_INCLUDED
#include <vector>

class gamemap{
    private:
        const int height, width;
        const int boundary = 10;
        std::vector<std::vector<bool>> display_vector, calculation_vector, start_state;
        bool game_state = true, auto_run = true;

    public:
        gamemap(int, int);
        void run_game();
        void display_map();
        int calculate_neighbours(int, int);
        void calculate_state();
        void display_menu();
};

#endif //GAMEMAP_H_INCLUDED