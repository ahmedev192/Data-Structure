#include "BinaryTree.h"
#include <cassert>
#include <iostream>
#include <queue>
#include <deque>

using namespace std;

template<typename T>
BinaryTree<T>::BinaryTree(T rootValue) {
	root = new Node<T>(rootValue);
};

// Destructor
template<typename T>
BinaryTree<T>::~BinaryTree() {
	destroyTree(root);
}

template<typename T>
void  BinaryTree<T>::destroyTree(Node<T>* node) {
	if (node) {
		destroyTree(node->left);
		destroyTree(node->right);
		delete node;
	}
};


// LVR
template<typename T>
void BinaryTree<T>::printInOrder(Node<T>* current) {
	if (current) {
		printInOrder(current->left);
		std::cout << current->data << " ";
		printInOrder(current->right);
	}
};


// LRV
template<typename T>
void BinaryTree<T>::printPostOrder(Node<T>* current) {
	if (current) {
		printPostOrder(current->left);
		printPostOrder(current->right);
		std::cout << current->data << " ";
	}
};



//VLR
template<typename T>
void BinaryTree<T>::printPreOrder(Node<T>* current) {
	if (current) {
		std::cout << current->data << " ";
		printPreOrder(current->left);
		printPreOrder(current->right);
	}
};




template<typename T>
void BinaryTree<T>::add(const std::vector<T>& values, const std::vector<char>& directions) {
	Node<T>* current = root;

	assert(values.size() == directions.size());
	for (size_t i = 0; i < values.size(); i++) {
		if (directions[i] == 'l' || directions[i] == 'L') {
			if (!current->left) {
				Node<T>* value = new Node<T>(values[i]);
				current->left = value;
			}
			else {
				assert(current->left->data == values[i]);
			}
			current = current->left;
		}
		else if (directions[i] == 'r' || directions[i] == 'R') {
			if (!current->right) {
				Node<T>* value = new Node<T>(values[i]);
				current->right = value;
			}
			else {
				assert(current->right->data == values[i]);
			}
			current = current->right;
		}
	}
}

template<typename T>
int BinaryTree<T>::MaxValue() {
	if (!root) {
		// Handle the case where the tree is empty
		std::cerr << "Tree is empty!" << std::endl;
		return -1; // Assuming -1 represents an invalid maximum value
	}
	return getMax(root);
}



template<typename T>
int BinaryTree<T>::getMax(Node<T>* current) {
	int inner_max;
	if (!current) {
		return -1;
	}

	int max_left = getMax(current->left);
	int max_right = getMax(current->right);
	int current_max = current->data;
	// Compare the maximum value in the left subtree, right subtree, and the current node's value
	if (max_left > current_max)
		current_max = max_left;
	if (max_right > current_max)
		current_max = max_right;
	return current_max;
};

template<typename T>
int BinaryTree<T>::maxHeight(Node<T>* current) {
	if (!current) {
		return -1; 
	}

	int left_height = maxHeight(current->left);
	int right_height = maxHeight(current->right);

	return max(left_height, right_height) + 1 ;
};



template<typename T>
int BinaryTree<T>::maxHeight() {
	return maxHeight(root);

};


template<typename T>
int BinaryTree<T>::countNodes(Node<T>* current) {
	if (!current)
		return 0;
	int left_nodes = countNodes(current->left);
	int right_nodes = countNodes(current->right);

	return left_nodes + right_nodes + 1;
};


template<typename T>
int BinaryTree<T>::countNodes() {
	return countNodes(root);
};


template<typename T>
bool BinaryTree<T>::search(Node<T>* current,  T value) {
	if (!current)
		return 0; 
	if (current->data == value)
		return 1; 

	return  search(current->left,  value) || search(current->right,  value);
};



template<typename T>
bool BinaryTree<T>::search( T value) {
	return search(root, value);
};



template<typename T>
bool BinaryTree<T>::isPerfectFomula() {
	int h = maxHeight();
	int n = countNodes();
	return pow(2, h + 1) - 1 == n;
};



template<typename T>
void BinaryTree<T>::printLevelOrder() {
	if (root == nullptr)
		return;

	std::queue<Node<T>*> q;
	q.push(root);

	while (!q.empty()) {
		int levelSize = q.size(); // Store the number of nodes at the current level
	
		// Process all nodes at the current level
		for (int i = 0; i < levelSize; ++i) {
			Node<T>* current = q.front();
			q.pop();
			std::cout << current->data << " ";

			// Enqueue children of the current node
			if (current->left != nullptr)
				q.push(current->left);
			if (current->right != nullptr)
				q.push(current->right);
		}

		// After processing all nodes at the current level, print std::endl
		std::cout << std::endl;
	}
};




template<typename T>
void BinaryTree<T>::print_nodes_level(Node<T>* node, int level) {
	if (node == nullptr)
		return;

	if (level == 1) {
		std::cout << node->data << " ";
	}
	else if (level > 1) {
		print_nodes_level(node->left, level - 1);
		print_nodes_level(node->right, level - 1);
	}
}

template<typename T>
void BinaryTree<T>::print_nodes_level(int level) {
	print_nodes_level(root, level);
}




template<typename T>
void BinaryTree<T>::level_order_traversal_spiral() {
	// It seems as if we need one level proceeded with a normal queue
	// But another with a stack
	// a deque allows both processing easily!

	std::deque<Node<T>*> nodes_queue;
	nodes_queue.push_back(root);

	int level = 0;
	bool forward_level = true;

	while (!nodes_queue.empty()) {
		int sz = nodes_queue.size();

		std::cout << "Level " << level << ": ";
		while (sz--) {
			Node<T>* cur;

			if (forward_level) {    // generate from front
				// Usual queue style: pop queue front, push queue rear: left, then right
				cur = nodes_queue.front();
				nodes_queue.pop_front();

				if (cur->left)
					nodes_queue.push_back(cur->left);

				if (cur->right)
					nodes_queue.push_back(cur->right);
			}
			else {                // generate  from back
				// like Stack: pop stack end, push stack front: right, then left
				cur = nodes_queue.back();
				nodes_queue.pop_back();

				// observe from the end, the right comes before left
				if (cur->right)
					nodes_queue.push_front(cur->right);

				if (cur->left)
					nodes_queue.push_front(cur->left);
			}
			std::cout << cur->data << " ";
		}
		forward_level = !forward_level;
		level++;
		std::cout << "\n";
	}
}
