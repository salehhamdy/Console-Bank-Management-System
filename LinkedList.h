#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
    } *head;

public:
    LinkedList() : head(nullptr) {}
    ~LinkedList();

    void insertAtEnd(T data);
    void display() const;
};

template <typename T>
LinkedList<T>::~LinkedList() {
    Node* current = head;
    while (current) {
        Node* tmp = current;
        current = current->next;
        delete tmp;
    }
}

template <typename T>
void LinkedList<T>::insertAtEnd(T data) {
    Node* newNode = new Node{data, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next)
        current = current->next;
    current->next = newNode;
}

template <typename T>
void LinkedList<T>::display() const {
    Node* current = head;
    while (current) {
        current->data->putdata(); // Assuming T has putdata() method
        current = current->next;
    }
}

#endif // LINKEDLIST_H
