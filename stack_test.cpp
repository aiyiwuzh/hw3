#include "stack.h"
#include <iostream>

// tests functionality of stack.cpp

int main() 
{
    // create a stack of ints
    Stack<int> myStack; 

    if (myStack.empty()) 
    {
       std::cout << "Stack is initially empty" << std::endl; 
    }

    myStack.push(1);
    myStack.push(2); 

    if (!myStack.empty())
    {
        std::cout << "Stack is not empty" << std::endl; 
    }

    if (myStack.size() == 2)
    {
        std::cout << "Stack size is 2" << std::endl;
    }
    
    if (myStack.top() == 2) 
    {
        std::cout << "Top is 2" << std::endl; 
    }

    myStack.pop(); 
    myStack.pop(); 

    if (myStack.empty())
    {
        std::cout << "All popped" << std::endl; 
    }

    return 0; 
}