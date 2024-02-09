#include "Vector.h"
#include <cassert>
#include <iostream>  


template <typename T>
Vector<T>::Vector(int Size) {
	size = Size;
	if (size < 0)
		size = 0;
	capacity = size + 10; 
	arr = new T[capacity]{};
};


template <typename T>
Vector<T>::~Vector() {
	delete[] arr;
	arr = nullptr;
};

template <typename T>
T Vector<T>::get(int idx) {
	assert(0 <= idx && idx < size);
	return arr[idx];
};

template <typename T>
void Vector<T>::set(int idx, T val) {
	assert(0 <= idx && idx < size);
	arr[idx] = val;
};

template <typename T>
void Vector<T>::print() {
	for (int i = 0; i < size; i++) {
		std::cout << "Element Number " << i << " : " << arr[i] << "\n";
	}
};

template <typename T>
int Vector<T>::find(T val) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == val) {
			return i;
		}
	}
	return -1;
};

template <typename T>
T Vector<T>::getFront() {
	return arr[0];
};

template <typename T>
T Vector<T>::getBack() {
	return arr[size - 1];
};

template <typename T>
void Vector<T>::pushFront(T val) {
	if (size == capacity)
		expand();

	for (int i = size; i > 0; i--) {
		arr[i] = arr[i - 1];
	}
	arr[0] = val;
	size++;

};

template <typename T>
void Vector<T>::pushBack(T val) {
	if (size == capacity)
		expand();

	arr[size] = val;
	size++;
};

template <typename T>
void Vector<T>::expand() {
	T* arr2 = new T[capacity * 2]{};
	for (int i = 0; i < size; i++) {
		arr2[i] = arr[i];
	}
	swap(arr, arr2);
	delete[] arr2;
	capacity *= 2;
};


template <typename T>
void Vector<T>::insert(int idx, T val) {
	assert(0 <= idx && idx <= size);



	if (size == capacity)
		expand();

	for (int i = size; i > idx; i--) {
		arr[i] = arr[i - 1];
	}
	arr[idx] = val;
	size++;
};


template <typename T>
void Vector<T>::rotate() {
	T temp;
	for (int i = 0; i < size / 2; i++) {
		temp = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - i - 1] = temp;
	}
};

template <typename T>
void Vector<T>::deleteAt(int idx) {
	if (idx < 0 || idx >= size) {
		// Index out of bounds, handle the error as needed
		std::cerr << "Error: Index out of bounds in deleteAt" << std::endl;
		return;
	}

	// Shift elements to the left starting from the specified index
	for (int i = idx; i < size - 1; ++i) {
		arr[i] = arr[i + 1];
	}

	// Decrease the size
	--size;
}


template <typename T>
int Vector<T>::getSize() {
	return size;
};