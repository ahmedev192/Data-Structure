#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct Node {
	T data{ };
	Node<T>* next{ };
	Node<T>* previous{ };
	Node(T data) : data(data) {}
	void set(Node* next, Node* prev) {
		this->next = next;
		this->prev = prev;
	}
	~Node() {
		cout << "Destroy value: " << data << " at address " << this << "\n";
	}
};

template <typename T>
class DoublyLinkedList
{
private :
	Node<T>* head ;  
	Node<T>* tail  ; 
	int length ;
public :
	DoublyLinkedList();
	~DoublyLinkedList();
	void link(Node<T>* first, Node<T>* second);
	void addLastNode(Node<T>* node);
	void insertEnd(T value);
	void insertFront(T value);
	void print();
	void printReversed();
	void deleteNode(Node<T>* node);
	void deleteAndLink(Node<T>* node);
	void deleteFirst();
	void deleteLast();

};

