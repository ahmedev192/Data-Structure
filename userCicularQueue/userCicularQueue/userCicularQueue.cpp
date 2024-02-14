#include <iostream>
#include "Queue.cpp"
using namespace std; 
int main()
{
    // Create a double-ended circular queue of integers
    Queue<int> q;

    // Test isEmpty() on an empty queue
    std::cout << "Queue is empty: " << q.isEmpty() << std::endl;

    // Test enqueueFront and enqueueRear
    q.enqueueFront(10);
    q.enqueueRear(20);
    q.enqueueFront(5);
    q.enqueueRear(30);

    // Test display
    std::cout << "Queue contents: ";
    q.display();

    // Test dequeueFront and dequeueRear
    std::cout << "Dequeued from front: " << q.dequeueFront() << std::endl;
    std::cout << "Dequeued from rear: " << q.dequeueRear() << std::endl;

    // Test isEmpty() on a non-empty queue
    std::cout << "Queue is empty: " << q.isEmpty() << std::endl;

    // Test display on a non-empty queue
    std::cout << "Queue contents: ";
    q.display();

    // Test additional enqueues and dequeues
    q.enqueueFront(3);
    q.enqueueRear(40);
    q.enqueueFront(1);
    std::cout << "Dequeued from front: " << q.dequeueFront() << std::endl;
    std::cout << "Dequeued from rear: " << q.dequeueRear() << std::endl;

    // Test isFull() on a full queue
    std::cout << "Queue is full: " << q.isFull() << std::endl;

    // Test display on a non-empty queue
    std::cout << "Queue contents: ";
    q.display();

}

