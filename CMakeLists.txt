cmake_minimum_required(VERSION 3.30)
project(Maze_Solver)

set(CMAKE_CXX_STANDARD 23)

add_executable(Maze_Solver
                src/main.cpp
                src/maze_solver.cpp
                src/stack.cpp)
