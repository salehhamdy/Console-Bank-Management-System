#ifndef STACK_H
#define STACK_H

#include <vector>
#include <string>

class Stack {
private:
    std::vector<std::string> interactions;

public:
    void push(const std::string& interaction);
    void pop();
    void display() const;
};

#endif // STACK_H
