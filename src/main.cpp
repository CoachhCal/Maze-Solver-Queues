#include <iostream>
#include "maze_solver.h"

int main(int argc, char** argv) {
    MazeSolver maze_solver;
    maze_solver.solve_maze(argc, argv);
    return 0;
}
