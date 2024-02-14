// UserVector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector.cpp"

int main()
{
    // Create a Vector of integers
    Vector<int> intVector(5);

    // Initialize the Vector
    for (int i = 0; i < intVector.getSize(); ++i) {
        intVector.set(i, i + 1);
    }

    // Print the original Vector
    std::cout << "Original Vector:" << std::endl;
    intVector.print();

    // Delete an element at a specific index
    int indexToDelete = 2;
    std::cout << "\nDeleting element at index " << indexToDelete << ":" << std::endl;
    intVector.deleteAt(4);

    // Print the Vector after deletion
    std::cout << "Vector after deletion:" << std::endl;
    intVector.print();
}
