#include "Queue.h"
#include <iostream>
using namespace std;

template<typename T>
Queue<T>::Queue() {
	size = 5;
	front = rear = -1;
	added_elements = 0;
	array = new T[size];

};


template<typename T>
Queue<T>::~Queue() {
	delete[] array;
};

template<typename T>
void Queue<T>::enqueueFront(T value) {
    if (isFull()) {
        std::cout << "Queue is full. Cannot enqueue." << std::endl;
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    }
    else {
        front = (front - 1 + size) % size; // Wrap around
    }
    array[front] = value;
    added_elements++;
}

template<typename T>
void Queue<T>::enqueueRear(T value) {
    if (isFull()) {
        std::cout << "Queue is full. Cannot enqueue." << std::endl;
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    }
    else {
        rear = (rear + 1) % size;
    }
    array[rear] = value;
    added_elements++;
}

template<typename T>
T Queue<T>::dequeueFront() {
    if (isEmpty()) {
        std::cout << "Queue is empty. Cannot dequeue." << std::endl;
        exit(1);
    }
    T value = array[front];
    if (front == rear) { // If there is only one element
        front = rear = -1;
    }
    else {
        front = (front + 1) % size;
    }
    added_elements--;
    return value;
}

template<typename T>
T Queue<T>::dequeueRear() {
    if (isEmpty()) {
        std::cout << "Queue is empty. Cannot dequeue." << std::endl;
        exit(1);
    }
    T value = array[rear];
    if (front == rear) { // If there is only one element
        front = rear = -1;
    }
    else {
        rear = (rear - 1 + size) % size; // Wrap around
    }
    added_elements--;
    return value;
}

template<typename T>
bool Queue<T>::isEmpty() {
	bool empty = (added_elements == 0);
	if (empty) {
		cout << "Queue is empty." << std::endl;
	}
	return empty;
}

template<typename T>
bool Queue<T>::isFull() {
	bool full = (added_elements == size);
	if (full) {
		cout << "Queue is full." << std::endl;
	}
	return full;
}



template<typename T>
void Queue<T>::display() {
	if (isEmpty()) {
		return;
	}
	int iterator = front;
	for (int i = 0; i < added_elements; i++) {
		std::cout << array[iterator] << " "; // Print element followed by space
		iterator = (iterator + 1) % size;
	}
	std::cout << std::endl; 
};
