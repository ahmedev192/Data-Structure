// UserLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LinkedList.cpp"

using namespace std;
int main()
{
    // Create a LinkedList object
    LinkedList<int> list;

    // Test insertion at the end
    list.insertEnd(1);
    list.insertEnd(2);
    list.insertEnd(3);
    list.insertEnd(4);
    list.insertEnd(5);

    // Print the list
    cout << "List after insertion at the end:\n";
    list.print();

    // Test insertion at the front
    list.insertFront(0);
    list.insertFront(-1);
    list.insertFront(-2);

    // Print the list
    cout << "List after insertion at the front:\n";
    list.print();

    // Test deletion of the first and last nodes
    list.deleteFirst();
    list.deleteLast();

    // Print the list
    cout << "List after deletion of first and last nodes:\n";
    list.print();

    // Test getting the nth node
    cout << "Node at index 2: " << list.get_nth(2)->data << endl;

    // Test deletion of nth node
    list.delete_nth_node(2);

    // Print the list
    cout << "List after deletion of node at index 2:\n";
    list.print();

    // Test swapping pairs
    list.swapPairs();

    // Print the list
    cout << "List after swapping pairs:\n";
    list.print();

    // Test reversal
    list.reverse();

    // Print the list
    cout << "List after reversal:\n";
    list.print();

    // Test removing the last occurrence of a value
    list.addLastNode(new Node<int>(3)); // Add another 3 for testing
    list.removeLastOccurrence(3);

    // Print the list
    cout << "List after removing last occurrence of 3:\n";
    list.print();

}

