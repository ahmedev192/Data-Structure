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





## Contributing

Contributions to improve existing data structures, add new data structures, fix bugs, or enhance documentation are welcome! If you find any issues or have suggestions, feel free to open an issue or submit a pull request.



