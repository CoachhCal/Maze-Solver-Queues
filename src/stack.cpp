//
// Created by calvi on 2025-04-17.
//

#include "stack.h"

//add to top of stack
void Stack::push(const Data& data) {
    auto node = std::make_unique<Node>(data);
    node->_next = std::move(_top);
    _top = std::move(node);
}

//returns element from top of stack, unless null
std::optional<Data> Stack::top() {
    if (_top == nullptr) return std::nullopt;
    return std::make_optional(_top->_data);
}

//remove from top of stack
void Stack::pop() {
    if (_top == nullptr) return;
    _top = std::move(_top->_next);
}
