#ifndef QUEUE_H
#define QUEUE_H

#include <queue>
#include <string>

class Queue {
private:
    std::queue<std::string> processingQueue;

public:
    void enqueue(const std::string& task);
    void dequeue();
    void display() const;
};

#endif // QUEUE_H
