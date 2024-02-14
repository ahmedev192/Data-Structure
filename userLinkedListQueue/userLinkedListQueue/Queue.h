#pragma once

template<typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };

    Node* front;
    Node* rear;
    int added_elements;

public:
    Queue();
    ~Queue();

    void enqueue(T value);
    T dequeue();
    void display();
    bool isEmpty();
};
