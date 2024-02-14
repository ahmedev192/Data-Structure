#include "Queue.h"
#include <iostream>

template<typename T>
Queue<T>::Queue() : front(nullptr), rear(nullptr), added_elements(0) {}

template<typename T>
Queue<T>::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

template<typename T>
void Queue<T>::enqueue(T value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
    added_elements++;
}

template<typename T>
T Queue<T>::dequeue() {
    if (isEmpty()) {
        std::cerr << "Queue is empty. Cannot dequeue." << std::endl;
        exit(1); // You can handle error in a different way
    }
    T value = front->data;
    Node* temp = front;
    front = front->next;
    delete temp;
    added_elements--;
    if (isEmpty()) {
        rear = nullptr;
    }
    return value;
}

template<typename T>
void Queue<T>::display() {
    if (isEmpty()) {
        std::cout << "Queue is empty." << std::endl;
        return;
    }
    Node* current = front;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template<typename T>
bool Queue<T>::isEmpty() {
    return added_elements == 0;
}
