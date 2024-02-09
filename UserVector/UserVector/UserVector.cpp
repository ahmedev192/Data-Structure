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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
