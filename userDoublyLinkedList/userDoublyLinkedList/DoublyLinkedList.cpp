#include "DoublyLinkedList.h"

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
	head = nullptr;
	tail = nullptr;
	length = 0;
};


template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
		while (length)
			deleteFirst();
}

template <typename T>
void DoublyLinkedList<T>::print() {
	if (!head) {
		cout << "List is empty here from print function :)" << endl;
		return;
	}

	cout << "Linked List: " << endl;
	for (Node<T>* i = head; i ; i = i->next) {
		cout << i->data << endl;
	}
};



template <typename T>
void DoublyLinkedList<T>::addLastNode(Node<T>* node) {
	if (!head) {
		head = tail = node;

	} 
	else {
		link(tail, node);
		tail = node; 
	}
	length++;
};



template <typename T>
void DoublyLinkedList<T>::insertEnd(T value) {
	// Allocate memory for a new Node<T> object
	Node<T>* n = new Node<T>(value);

	// Check if the list is empty
	if (!head) {
		head = tail = n;
	}
	else {
		// Append the new node to the end of the list
		link(tail, n);
		tail = n;
	}

	// Increment the length of the list
	length++;
}



template <typename T>
void DoublyLinkedList<T>::insertFront(T value) {
	Node<T>* newNode = new Node<T>(value);

	if (!head) {
		head = tail = newNode;
		 
	}
	else {
		link(newNode, head);
		head = newNode;
	}

	length++;
};




template <typename T>
void DoublyLinkedList<T>::deleteFirst() {
	deleteNode(head);
};

template <typename T>
void DoublyLinkedList<T>::deleteLast() {
	deleteNode(tail);

};



template <typename T>
void DoublyLinkedList<T>::deleteNode(Node<T>* node) {
	if (!head) {
		cout << "List is empty here from deleteNode function :)" << endl;
		return;
	}

	if (node == head) {
		head = head->next;
		delete node;
		length--;
		// If the list becomes empty after deletion, update tail
		if (!head) {
			tail = nullptr;
		}
		return;
	}
	Node<T>* current = head;
	while (current!=node && current) {
		current = current->next;
	}

	if (!current) {
		cout << "Node not found in the list! here from deleteNode function :)" << endl;
		return;
	}
	current->previous->next = current->next;
	// If the node to be deleted is the tail, update tail
	if (node == tail) {
		tail = current->previous;
	}
	delete node;
	length--;
};




template <typename T>
void DoublyLinkedList<T>::link(Node<T>* first, Node<T>* second) {
	if (first)
		first->next = second;
	if (second)
		second->previous = first;
};

template <typename T>
void DoublyLinkedList<T>::deleteAndLink(Node<T>* node) {
	// remove this node, but connect its neighbors
	link(node->previous, node->next);
	deleteNode(node);
};


template <typename T>
void DoublyLinkedList<T>::printReversed() {
	for (Node* current = tail; current; current = current->previous)
		cout << current->data << " ";
	cout << "\n";
};