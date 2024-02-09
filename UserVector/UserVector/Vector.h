#pragma once
template <typename T>
class Vector
{
private :
	T* arr{};
	int size{0}, capacity;

	void expand();

public : 
	Vector(int Size);
	~Vector();
	T get(int idx);
	void set(int idx, T val);
	void print();
	int find(T val);
	T getFront();
	T getBack();
	void pushFront(T val);
	void pushBack(T val);
	void insert(int idx, T val);
	void rotate();
	void deleteAt(int idx);
	int getSize();
};

