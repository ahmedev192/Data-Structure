#pragma once
#include <vector> // Include the vector header

template<typename T>
struct Node {
	T data;
	Node<T>* right{};
	Node<T>* left{};
	Node(T data) :
		data(data), right(nullptr), left(nullptr) {
	}
};

template<typename T>
class BinaryTree
{
private:
	// Main Functions 
	void destroyTree(Node<T>* node);
	// Applications 
	int getMax(Node<T>* current);
	int maxHeight(Node<T>* current);
	int countNodes(Node<T>* current);
	bool search(Node<T>* current, T value);
	void print_nodes_level(Node<T>* node, int level);

public:
	Node<T>* root{};
	// Main Functions 
	BinaryTree(T rootValue);
	~BinaryTree();
	void printInOrder(Node<T>* current);
	void printPostOrder(Node<T>* current);
	void printPreOrder(Node<T>* current);
	void add(const std::vector<T>& values, const std::vector<char>& directions);
	// Applications 
	int MaxValue();
	int maxHeight();
	int countNodes();
	bool search(T value);
	bool isPerfectFomula();
	void printLevelOrder();
	void print_nodes_level(int level);
	void level_order_traversal_spiral();
};

