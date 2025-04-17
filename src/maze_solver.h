//
// Created by calvi on 2025-02-13.
//

#ifndef MAZE_SOLVER_MAZE_SOLVER_H
#define MAZE_SOLVER_MAZE_SOLVER_H


#include <vector>

class MazeSolver {
public:
    int _maze_width = 0;
    int _maze_length = 0;
    char **_maze = nullptr;
    std::vector<std::pair<int, int>> _maze_exits;

    void solve_maze(int, char **);
    void find_maze_exits();
    void populate_maze(std::string) const;
    void save_solved_maze(const std::string&) const;
};


#endif //MAZE_SOLVER_MAZE_SOLVER_H
