#include "Stack.h"
#include <iostream>

void Stack::push(const std::string& interaction) {
    interactions.push_back(interaction);
}

void Stack::pop() {
    if (!interactions.empty())
        interactions.pop_back();
}

void Stack::display() const {
    for (auto it = interactions.rbegin(); it != interactions.rend(); ++it) {
        std::cout << *it << std::endl;
    }
}
