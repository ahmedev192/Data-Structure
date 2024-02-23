# Data-Structure
📦 C++ Standard Library Manual Implementation Repository


# Linked List Implementation in C++

This repository contains a C++ implementation of a singly linked list. A linked list is a linear data structure consisting of a sequence of elements, where each element points to the next one in the sequence. This implementation provides various operations to manipulate and traverse the linked list.

## Features

- **Insertion**: Insert elements at the end or front of the linked list.
- **Deletion**: Delete elements from the beginning or end of the linked list, or delete a specific node.
- **Traversal**: Print the elements of the linked list.
- **Node Swapping**: Swap adjacent nodes in pairs.
- **Reversal**: Reverse the order of elements in the linked list.
- **Removal of Last Occurrence**: Remove the last occurrence of a specific value from the linked list.

## Usage

1. Clone the repository to your local machine:

    ```bash
    git clone https://github.com/ahmedev192/Data-Structure.git
    ```


## Example

```cpp
#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList<int> list;

    list.insertEnd(1);
    list.insertEnd(2);
    list.insertEnd(3);
    list.insertFront(0);

    list.print(); // Output: 0 1 2 3

    list.reverse();
    list.print(); // Output: 3 2 1 0

    return 0;
}

```

# Doubly Linked List Implementation in C++

This repository contains a C++ implementation of a doubly linked list. A doubly linked list is a linear data structure consisting of a sequence of elements, where each element points to the next one and the previous one in the sequence. This implementation provides various operations to manipulate and traverse the doubly linked list.

## Features

- **Insertion**: Insert elements at the end or front of the doubly linked list.
- **Deletion**: Delete elements from the beginning or end of the doubly linked list, or delete a specific node.
- **Traversal**: Print the elements of the doubly linked list.
- **Reverse Traversal**: Print the elements of the doubly linked list in reverse order.

## Usage

1. Clone the repository to your local machine:

    ```bash
    git clone https://github.com/ahmedev192/Data-Structure.git
    ```

## Example

```cpp
#include <iostream>
#include "DoublyLinkedList.h"

int main() {
    DoublyLinkedList<int> list;

    list.insertEnd(1);
    list.insertEnd(2);
    list.insertEnd(3);
    list.insertFront(0);

    list.print(); // Output: 0 1 2 3

    list.printReversed(); // Output: 3 2 1 0

    return 0;
}

```



# Array-based Stack Implementation in C++

This repository contains a C++ implementation of a stack data structure based on arrays. A stack is a Last-In-First-Out (LIFO) data structure, where elements are added and removed from the top of the stack. This implementation provides various operations to manipulate and traverse the stack.

## Features

- **Push**: Add an element to the top of the stack.
- **Pop**: Remove and return the element from the top of the stack.
- **Peek**: Return the element from the top of the stack without removing it.
- **Empty and Full Checking**: Check if the stack is empty or full.
- **Length**: Get the current number of elements in the stack.
- **Display**: Print the elements of the stack.
- **Reverse**: Reverse the order of elements in the stack.
- **Insert at Bottom**: Insert an element at the bottom of the stack.
- **Applications**: Includes several applications such as reversing a string until space, reversing a number, checking if a string has a valid arrangement of parentheses, and removing duplicates from a string.
- **Infix to Postfix Conversion**: Convert an infix expression to a postfix expression using the Shunting-Yard ALgorithm.

## Usage

1. Clone the repository to your local machine:

    ```bash
    git clone https://github.com/ahmedev192/Data-Structure.git
    ```

2. Include the `Stack.h` header file in your C++ project:

    ```cpp
    #include "Stack.h"
    ```

3. Instantiate a `Stack` object with the desired data type:

    ```cpp
    Stack<int> stack;
    ```

4. Use the provided member functions to perform operations on the stack:

    ```cpp
    stack.push(5);
    stack.push(10);
    stack.display();
    ```

## Example

```cpp
#include <iostream>
#include "Stack.h"

int main() {
    Stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Top element: " << stack.peek() << std::endl;

    while (!stack.isEmpty()) {
        std::cout << stack.pop() << " ";
    }
    std::cout << std::endl;

    return 0;
}

```


# Queue Implementations in C++

This repository contains C++ implementations of two types of queues: circular array-based queue (Deque) and linked list-based queue.

## Circular Array-based Queue (Deque)

### Features

- **Enqueue Front**: Add an element to the front of the queue.
- **Enqueue Rear**: Add an element to the rear of the queue.
- **Dequeue Front**: Remove and return the element from the front of the queue.
- **Dequeue Rear**: Remove and return the element from the rear of the queue.
- **Display**: Print the elements of the queue.
- **Empty and Full Checking**: Check if the queue is empty or full.

### Usage

1. Clone the repository to your local machine:

    ```bash
    git clone https://github.com/ahmedev192/Data-Structure.git
    ```


2. Use the provided member functions to perform operations on the queue:

    ```cpp
    queue.enqueueFront(5);
    queue.enqueueRear(10);
    queue.display();
    ```

## Linked List-based Queue

### Features

- **Enqueue**: Add an element to the rear of the queue.
- **Dequeue**: Remove and return the element from the front of the queue.
- **Display**: Print the elements of the queue.
- **Empty Checking**: Check if the queue is empty.

### Usage

1. Clone the repository to your local machine:

    ```bash
    git clone https://github.com/ahmedev192/Data-Structure.git
    ```

2. Use the provided member functions to perform operations on the queue:

    ```cpp
    queue.enqueue(5);
    queue.enqueue(10);
    queue.display();
    ```





# Binary Tree Implementation in C++

This repository contains a simple implementation of a binary tree data structure in C++. The `BinaryTree` class provides various functionalities such as adding nodes, traversing the tree in different orders, finding maximum value, calculating height, counting nodes, searching for a value, checking if the tree satisfies the perfect binary tree formula, and printing tree nodes at a specific level.

## Features

- Add nodes to the binary tree.
- Print tree nodes in different traversal orders: InOrder, PreOrder, and PostOrder.
- Find the maximum value in the tree.
- Calculate the height of the tree.
- Count the total number of nodes in the tree.
- Search for a value in the tree.
- Check if the tree satisfies the perfect binary tree formula.
- Print tree nodes at a specific level.
- Perform level order traversal and print nodes in level order.
- Perform level order traversal in a spiral manner.

## Usage

To use the binary tree implementation in your project, follow these steps:

1. Clone the repository:

    ```bash
    git clone https://github.com/ahmedev192/Data-Structure.git
    ```

2. Include the `BinaryTree.h` header file in your project.

3. Create a `BinaryTree` object and use its member functions to perform various operations on the binary tree.

## Example

```cpp
#include <iostream>
#include "BinaryTree.h"

int main() {
    // Create a binary tree with root value 1
    BinaryTree<int> tree(1);

    // Add nodes to the tree
    std::vector<int> values = {2, 3, 4, 5, 6};
    std::vector<char> directions = {'L', 'R', 'L', 'R', 'L'};
    tree.add(values, directions);

    // Test various functionalities of the BinaryTree class

    return 0;
}

```



## Contributing

Contributions to improve existing data structures, add new data structures, fix bugs, or enhance documentation are welcome! If you find any issues or have suggestions, feel free to open an issue or submit a pull request.



