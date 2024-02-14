#pragma once



template<typename T>
class Queue
{
private :
	int size; 
	int front; 
	int rear;
	int added_elements;
	T* array; 
public :
	Queue();
	~Queue();
	void enqueueFront(T value); // Enqueue at the front
	void enqueueRear(T value); // Enqueue at the rear
	T dequeueFront(); // Dequeue from the front
	T dequeueRear(); // Dequeue from the rear
	void display();
	bool isEmpty();
	bool isFull();

	
};

