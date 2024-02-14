
#include <iostream>
#include "Queue.cpp"
using namespace std;
int main()
{

	Queue<int> q;

	std::cout << "Queue is empty: " << q.isEmpty() << std::endl;

	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);


	std::cout << "Dequeued item: " << q.dequeue() << std::endl;

	std::cout << "Queue contents: ";
	q.display();

	q.enqueue(60);
	q.enqueue(70);
	std::cout << "Dequeued item: " << q.dequeue() << std::endl;
	std::cout << "Dequeued item: " << q.dequeue() << std::endl;

	std::cout << "Queue is empty: " << q.isEmpty() << std::endl;

	std::cout << "Queue contents: ";
	q.display();

	q.enqueue(80);

	std::cout << "Queue contents: ";
	q.display();

}
