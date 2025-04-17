//
// Created by calvi on 2025-02-17.
//

#ifndef MAZE_SOLVER_STACK_H
#define MAZE_SOLVER_STACK_H


#include <iostream>
#include <memory>
#include <optional>

struct Data {
    int _x_coord {0};
    int _y_coord {0};
};

class Stack {
    struct Node {
        Data _data;
        std::unique_ptr<Node> _next {nullptr};
    };
private:
    std::unique_ptr<Node> _top {nullptr};

public:
    void push(const Data&);
    std::optional<Data> top();
    void pop();
};


#endif //MAZE_SOLVER_STACK_H
