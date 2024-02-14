// UserStack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Stack.cpp"
#include <cmath>

using namespace std; 
int main()
{
    // Test Stack functionalities
    Stack<int> intStack;
    Stack<char> charStack;

    // Push elements onto the integer stack
    std::cout << "Pushing elements onto Integer Stack..." << std::endl;
    for (int i = 1; i <= 5; ++i) {
        intStack.push(i);
    }

    std::cout << "Integer Stack: ";
    intStack.display(); // Display the integer stack

    // Test isEmpty and length
    std::cout << "Is Integer Stack empty? " << (intStack.isEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "Length of Integer Stack: " << intStack.length() << std::endl;

    // Test peek
    std::cout << "Top element of Integer Stack: " << intStack.peek() << std::endl;

    // Test reverse
    std::cout << "Reversing Integer Stack..." << std::endl;
    intStack.reverse();
    std::cout << "Reversed Integer Stack: ";
    intStack.display();

    // Test insertAtBottom
    std::cout << "Inserting 0 at bottom of Integer Stack..." << std::endl;
    intStack.insertAtBottom(0);
    std::cout << "Modified Integer Stack: ";
    intStack.display();

    // Test removeDuplicates
    std::string duplicateStr = "mississippi";
    std::cout << "Removing duplicates from \"" << duplicateStr << "\": ";
    std::cout << Stack<char>::removeDuplicates(duplicateStr) << std::endl;

    // Test reverseUntilSpace
    std::string spaceStr = "Hello World";
    std::cout << "Reversing until space in \"" << spaceStr << "\": ";
    std::cout << Stack<char>::reverseUntilSpace(spaceStr) << std::endl;

    // Test reverseNumber
    int num = 12345;
    std::cout << "Reversing number " << num << ": " << Stack<int>::reverseNumber(num) << std::endl;

    // Test checkPrincess
    std::string princessStr = "()((())){}[[[]]][][{()}]";
    std::cout << "Checking princess string: " << (Stack<char>::checkPrincess(princessStr) ? "Valid" : "Invalid") << std::endl;

    // Test infixToPostfix
    std::string infixExpression = "3+4*2/(1-5)^2";
    std::cout << "Infix Expression: " << infixExpression << std::endl;
    std::string postfixExpression = intStack.infixToPostfix(infixExpression);
    std::cout << "Postfix Expression: " << postfixExpression << std::endl;


}
