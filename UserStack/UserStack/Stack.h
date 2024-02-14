#pragma once
#include <string>
template <typename T>
class Stack
{
private:
    T* array;    // Pointer to dynamically allocated memory
    int size;    // Size of the stack
    int top;     // Index of the stack top
public:
    Stack();          // Constructor
    ~Stack();         // Destructor
    void push(T value);
    T pop();
    T peek();
    bool isEmpty();
    bool isFull();
    int length();
    void display();
    void reverse();
    void insertAtBottom(T value);
    // Applications
    static std::string reverseUntilSpace(const std::string& input);
    static int reverseNumber(int num);
    static bool checkPrincess(std::string s);
    static std::string removeDuplicates(std::string str);
    int precedence(char op);
    std::string infixToPostfix(std::string infix);
};


