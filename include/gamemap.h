#ifndef GAMEMAP_H_INCLUDED
#define GAMEMAP_H_INCLUDED
#include <vector>

class gamemap{
    private:
        const int height, width;
        const int boundary = 5;
        std::vector<std::vector<bool>> display_vector, calculation_vector;

    public:
        gamemap(int, int);
        void run_game();
        void display_map();
        int calculate_neighbours(int, int);
        void calculate_state();
};

#endif //GAMEMAP_H_INCLUDED