#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList() {
	head = nullptr;
	tail = nullptr;
	length = 0;
};


template <typename T>
void LinkedList<T>::print() {
	if (!head) {
		cout << "List is empty here from print function :)" << endl;
		return;
	}

	cout << "Linked List: " << endl;
	for (Node<T>* i = head; i != nullptr; i = i->next) {
		cout << i->data << endl;
	}
};

template <typename T>
void LinkedList<T>::addLastNode(Node<T>* node) {
	if (!head) {
		head = node;
		tail = node;
	}
	else {
		tail->next = node;
		tail = node;
		tail->next = nullptr;
	}
	length++;
};


template <typename T>
void LinkedList<T>::deleteNode(Node<T>* node) {
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
	Node<T>* prev = head;
	while (prev->next && prev->next != node) {
		prev = prev->next;
	}

	if (!prev->next) {
		cout << "Node not found in the list! here from deleteNode function :)" << endl;
		return;
	}
	prev->next = node->next;
	// If the node to be deleted is the tail, update tail
	if (node == tail) {
		tail = prev;
	}
	delete node;
	length--;
};


template <typename T>
void LinkedList<T>::insertEnd(T value) {
	// Allocate memory for a new Node<T> object
	Node<T>* n = new Node<T>(value);

	// Check if the list is empty
	if (!head) {
		head = tail = n;
	}
	else {
		// Append the new node to the end of the list
		tail->next = n;
		tail = n;
	}

	// Increment the length of the list
	length++;
}


template <typename T>
void LinkedList<T>::insertFront(T value) {
	Node<T>* newNode = new Node<T>(value);

	if (!head) {
		head = newNode;
		tail = newNode;
	}
	else {
		newNode->next = head;
		head = newNode;
	}

	length++;
};


template <typename T>
void LinkedList<T>::deleteFirst() {
	deleteNode(head);
};

template <typename T>
void LinkedList<T>::deleteLast() {
	deleteNode(tail);

};


template <typename T>
Node<T>* LinkedList<T>::get_nth(int n) {
	// Check if the list is empty or if n is out of bounds
	if (!head || n < 0 || n >= length) {
		cout << "Invalid index here from get_nth function :)" << endl;
		return nullptr;
	}

	// Check for negative index
	if (n < 0) {
		cout << "Invalid index (negative). here from get_nth function :)" << endl;
		return nullptr;
	}


	// Traverse the list to find the nth node
	Node<T>* current = head;
	for (int i = 0; i < n; ++i) {
		current = current->next;
	}

	// Return the nth node
	return current;
};


template <typename T>
void LinkedList<T>::delete_nth_node(int n) {
	Node<T>* node = get_nth(n);
	deleteNode(node);

}


template <typename T>
void LinkedList<T> ::swapPairs() {
	if (!head) {
		cout << "Already empty ,here from swapPairs function :)" << endl;
		return;
	}

	Node<T>* current = head;
	Node<T>* next = head->next;
	T temp;
	while (next) {
		temp = current->data;
		current->data = next->data;
		next->data = temp;

		if (current->next->next != nullptr) {
			current = next->next;
			next = current->next;
		}
		else {
			return;
		}
	}
};



template <typename T>
void LinkedList<T> ::reverse() {
	if (!head || !head->next) {
		return;
	}

	Node<T>* previous = nullptr; 
	Node<T>* current = head;
	tail = head;

	Node<T>* next = nullptr;
	while (current) {
		next = current->next;
		current->next =previous;
		previous = current;
		current = next;
	}
	head = previous;

};

template <typename T>
void LinkedList<T>::removeLastOccurrence(T value) {
	Node<T>* previous = nullptr;
	Node<T>* current = head;
	Node<T>* last_occurance = nullptr;
	Node<T>* before_last = nullptr;
	while (current) {
		
		if (current->data == value) {
			last_occurance = current;
			before_last = previous;
		}
		previous = current;
		current = current->next;
	}
	if (last_occurance) {
		if (before_last) {
			before_last->next = last_occurance->next;
		}
		else {
			head = head->next;
		}
		deleteNode(last_occurance);
	}

};
