#ifndef TREE_H
#define TREE_H

#include <iostream>

template <typename T>
class Tree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
    };
    Node* root;

    void insert(Node*& node, const T& data);
    void inOrder(Node* node) const;
    Node* search(Node* node, int key) const;
    Node* remove(Node*& node, int key);
    void destroyTree(Node* node); // Added helper function

public:
    Tree() : root(nullptr) {}
    ~Tree();

    void insert(const T& data);
    void display() const;
    T* search(int key) const;
    void remove(int key);
};

// Destructor
template <typename T>
Tree<T>::~Tree() {
    destroyTree(root);
}

// Helper function to destroy the tree
template <typename T>
void Tree<T>::destroyTree(Node* node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

// Insert Method
template <typename T>
void Tree<T>::insert(const T& data) {
    insert(root, data);
}

template <typename T>
void Tree<T>::insert(Node*& node, const T& data) {
    if (node == nullptr) {
        node = new Node{data, nullptr, nullptr};
    } else if (data.getKey() < node->data.getKey()) {
        insert(node->left, data);
    } else if (data.getKey() > node->data.getKey()) {
        insert(node->right, data);
    } else {
        // Key already exists, handle duplicates if necessary
        std::cout << "Duplicate key found: " << data.getKey() << ". Insertion skipped.\n";
    }
}

// Display Method
template <typename T>
void Tree<T>::display() const {
    inOrder(root);
}

template <typename T>
void Tree<T>::inOrder(Node* node) const {
    if (node != nullptr) {
        inOrder(node->left);
        node->data.putdata();
        inOrder(node->right);
    }
}

// Search Method
template <typename T>
T* Tree<T>::search(int key) const {
    Node* node = search(root, key);
    if (node != nullptr) {
        return &node->data;
    } else {
        return nullptr;
    }
}

template <typename T>
typename Tree<T>::Node* Tree<T>::search(Node* node, int key) const {
    if (node == nullptr || node->data.getKey() == key) {
        return node;
    } else if (key < node->data.getKey()) {
        return search(node->left, key);
    } else {
        return search(node->right, key);
    }
}

// Remove Method
template <typename T>
void Tree<T>::remove(int key) {
    root = remove(root, key);
}

template <typename T>
typename Tree<T>::Node* Tree<T>::remove(Node*& node, int key) {
    if (node == nullptr) {
        return node;
    }
    if (key < node->data.getKey()) {
        node->left = remove(node->left, key);
    } else if (key > node->data.getKey()) {
        node->right = remove(node->right, key);
    } else {
        // Node with one child or no child
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        // Node with two children: Get inorder successor
        Node* temp = node->right;
        while (temp->left != nullptr) {
            temp = temp->left;
        }
        node->data = temp->data;
        node->right = remove(node->right, temp->data.getKey());
    }
    return node;
}

#endif // TREE_H
