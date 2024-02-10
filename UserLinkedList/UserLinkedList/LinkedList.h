#pragma once
#include <iostream>
using namespace std;
template <typename T>
struct Node {
	T data{ };
	Node* next{ };
	Node(T data) : data(data) {}
	~Node() {
		cout << "Destroy value: " << data << " at address " << this << "\n";
	}
};


template <typename T>
class LinkedList
{
private :
	Node<T>* head ;
	Node<T>* tail;
	int length ; 

public:
	LinkedList();
	void print();
	void deleteNode(Node<T>* node);
	void addLastNode(Node<T>* node);
	void insertEnd(T value);
	void insertFront(T value);
	void deleteFirst();
	void deleteLast();
	Node<T>* get_nth(int n);
	void delete_nth_node(int n);
	void swapPairs();
	void reverse();
	void removeLastOccurrence(T value);
};


