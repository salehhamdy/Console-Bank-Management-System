#include "Queue.h"
#include <iostream>

void Queue::enqueue(const std::string& task) {
    processingQueue.push(task);
}

void Queue::dequeue() {
    if (!processingQueue.empty())
        processingQueue.pop();
}

void Queue::display() const {
    std::queue<std::string> tempQueue = processingQueue;
    while (!tempQueue.empty()) {
        std::cout << tempQueue.front() << std::endl;
        tempQueue.pop();
    }
}
