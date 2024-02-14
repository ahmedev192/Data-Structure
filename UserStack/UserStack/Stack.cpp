#include "Stack.h"
#include <iostream>
using namespace std; 


// Implementation of the constructor
template<typename T>
Stack<T>::Stack() {
    size = 100;
    array = new T[size]; 
    top = -1 ;
}  

// Implementation of the destructor
template<typename T>
Stack<T>::~Stack() {
    delete[] array;  // Free dynamically allocated memory
}


// push() implementation
template<typename T>
void Stack<T>::push(T value) {
    if (isFull()) {
        // Handle stack overflow
        cerr << "Error: Stack overflow\n";
        return;
    }
    array[++top] = value;
}

// pop() implementation
template<typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        cerr << "Error: Stack underflow\n";
        return T();
    }
    return array[top--];
}



// peek() implementation
template<typename T>
T Stack<T>::peek() {
    if (isEmpty()) {
      cerr << "Error: Stack is empty\n";
        return T();
    }
    return array[top];
}



// isEmpty() implementation
template<typename T>
bool Stack<T>::isEmpty() {
    return top == -1;
}

// isFull() implementation
template<typename T>
bool Stack<T>::isFull() {
    return top == size - 1;
}

template<typename T>
void Stack<T>::display() {
    for (int i = top; i >= 0; i--)
        cout << array[i] << " ";
    cout << "\n";
}


// Implementation of the reverseUntilSpace function
template<typename T>
std::string Stack<T>::reverseUntilSpace(const std::string& input) {
    Stack<char> stack;
    std::string result;
    for (char c : input) {
        if (c != ' ') {
            stack.push(c);
        }
        else {
            while (!stack.isEmpty()) {
                result += stack.pop();
            }
            result += ' ';
        }
    }
    while (!stack.isEmpty()) {
        result += stack.pop();
    }
    return result;
}


template<typename T>
int Stack<T>::length(){
    return top+1 ;
}



template<typename T>
int Stack<T>::reverseNumber(int num) {
    Stack<int> digitStack;

    // Push each digit of the original number onto the stack
    while (num != 0) {
        int digit = num % 10;
        digitStack.push(digit);
        num /= 10;
    }

    int reversedNumber = 0;
    int stackSize = digitStack.length();

    // Construct the reversed number by popping digits from the stack
    for (int i = 0; i < stackSize; i++) {
        reversedNumber += (digitStack.pop() * (pow(10, i)));
    }

    return reversedNumber;
}


// Implementation of the checkPrincess function
template<typename T>
bool Stack<T>::checkPrincess(std::string s) {
    Stack<char> stack;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            stack.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (stack.isEmpty()) {
                return false;  // More closing brackets than opening ones
            }
            char opening = stack.pop();
            if ((c == ')' && opening != '(') || (c == '}' && opening != '{') || (c == ']' && opening != '[')) {
                return false;  // Mismatched closing bracket
            }
        }
    }
    return stack.isEmpty();  // True if all brackets matched
}

template<typename T>
std::string Stack<T>::removeDuplicates(std::string str) {
    Stack<char> chars;
    for (int i = 0; i < str.length(); i++) {
        if (!chars.isEmpty() && chars.peek() == str[i]) {
            chars.pop();
        }
        else {
            chars.push(str[i]);

        }
    }
    string answer = "";
    while (!chars.isEmpty())
        answer = chars.pop() + answer;

    return answer;

};


template<typename T>
void Stack<T>::insertAtBottom(T value) {
    // Base case: If the stack is empty, push the new element to the stack
    if (isEmpty()) {
        push(value);
    }
    else {
        // Recursive case: Pop the top element and recursively insert the new element
        // until the stack becomes empty, then push the popped element back onto the stack
        T temp = pop();
        insertAtBottom(value);
        push(temp);
    }
};


template<typename T>
void Stack<T>::reverse() {
    // Base case: If the stack is empty or has only one element, no need to reverse
    if (isEmpty() || length() == 1) {
        return;
    }
    else {
        // Pop the top element
        T temp = pop();
        // Recursively reverse the remaining elements
        reverse();
        // Insert the popped element at the bottom of the stack
        insertAtBottom(temp);
    }
};



template<typename T>
int Stack<T>::precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
};



template<typename T>
std::string Stack<T>::infixToPostfix(std::string infix) {
    Stack<char> operators;
    string postfix;

    infix += '-';			// Whatever lowest priority: force stack got empty
    operators.push('#');	// Remove IsEmpty

    for (int i = 0; i < (int)infix.size(); ++i) {
        if (isdigit(infix[i]))
            postfix += infix[i];
        else if (infix[i] == '(')
            operators.push(infix[i]);
        else if (infix[i] == ')') {
            while (operators.peek() != '(')
                postfix += operators.pop();
            operators.pop();	// pop (
        }
        else {
            while (precedence(operators.peek()) >= precedence(infix[i]))
                postfix += operators.pop();
            operators.push(infix[i]);
        }
    }

    return postfix;
};
