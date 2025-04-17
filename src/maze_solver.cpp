//
// Created by calvi on 2025-04-17.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include "maze_solver.h"
#include "stack.h"

void MazeSolver::solve_maze(int argc , char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return;
    }

    std::fstream file;
    file.open(argv[1], std::ios::in | std::ios::out);

    if (!file.is_open()) {
        std::cerr << "Error: could not open or create file " << argv[1] << std::endl;
        return;
    }

    std::string maze_text;
    std::string line;

    while (getline(file, line)) {
        maze_text += line;
        _maze_length += 1;
    }

    if(line.empty()) {
        std::cerr << "Error: extra line at the end of file" << std::endl;
        return;
    }

    _maze_width = (int)line.length();

    file.close();

    //initialize the maze array based on mazes length and width
    _maze = new char*[_maze_length];
    for (int i = 0; i < _maze_length; ++i) {
        _maze[i] = new char[_maze_width];

    }

    populate_maze(maze_text);
    find_maze_exits();
    Stack stack;

    stack.push({_maze_exits[0].first,_maze_exits[0].second});
    _maze[stack.top()->_x_coord][stack.top()->_y_coord] = '#';

    std::vector<std::pair<int, int>> move_to_coords;

    while(stack.top()->_x_coord != _maze_exits[1].first || stack.top()->_y_coord != _maze_exits[1].second) {

        int x_coord = stack.top()->_x_coord;
        int y_coord = stack.top()->_y_coord;

        //look left
        if (0 < x_coord && _maze[x_coord - 1][y_coord] == ' ') {
            move_to_coords.emplace_back(x_coord - 1, y_coord);
        }

        //look right
        if (x_coord < _maze_width && _maze[x_coord + 1][y_coord] == ' ') {
            move_to_coords.emplace_back(x_coord + 1, y_coord);
        }

        //look up
        if (0 < y_coord && _maze[x_coord][y_coord - 1] == ' ') {
            move_to_coords.emplace_back(x_coord, y_coord - 1);
        }

        //look down
        if (y_coord < _maze_length && _maze[x_coord][y_coord + 1] == ' ') {
            move_to_coords.emplace_back(x_coord, y_coord + 1);
        }

        if (!move_to_coords.empty()) {
            stack.push({move_to_coords[0].first, move_to_coords[0].second});
            move_to_coords.clear();

        } else {
            _maze[stack.top()->_x_coord][stack.top()->_y_coord] = '@';
            stack.pop();
        }

        _maze[stack.top()->_x_coord][stack.top()->_y_coord] = '#';
    }
    save_solved_maze(argv[1]);
}

void MazeSolver::populate_maze(std::string text) const {
    int char_index = 0;
    while(char_index < text.length()){
        for(int y = 0; y < _maze_width; y++){
            for (int x = 0; x < _maze_length; x++){
                _maze[x][y] = text[char_index];
                char_index++;
            }
        }
    }
}

void MazeSolver::find_maze_exits(){
    int char_index=0;
    for(int y = 0; y < _maze_width; y++){
        for (int x = 0; x < _maze_length; x++){
            if((_maze[x][y]) == ' ' && (x == 0 || y == 0 || x == _maze_width - 1 || y  == _maze_length - 1)){
                _maze_exits.emplace_back(x, y);
            }
            char_index++;
        }
    }
}

void MazeSolver::save_solved_maze(const std::string& file_name) const {

    //creating the filepath string for the solved maze file
    //std::string filePath = std::move(fileName);
    size_t index_slash = file_name.find_last_of("/\\");
    size_t index_period = file_name.find_last_of('.');
    std::string original_file_name = file_name.substr(index_slash + 1, index_period - (index_slash + 1));
    std::string solved_file_path = "../solved/" + original_file_name + "_solved.txt";

    std::ofstream out_file(solved_file_path);
    if (!out_file.is_open()) {
        std::cerr << "Error: Unable to open file " << file_name << std::endl;
        return;
    }

    //write maze to the solved file
    //The '@' are removed, as they show wrong pathways
    for(int y = 0; y < _maze_width; y++){
        for (int x = 0; x < _maze_length; x++){
            if (_maze[x][y] == '@'){
                _maze[x][y] = ' ';
            }
            out_file << _maze[x][y];
        }
        out_file << std::endl;
    }
    out_file.close();
}
