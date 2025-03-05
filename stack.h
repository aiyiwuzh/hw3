#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
// stack = last in first out 

template <typename T>
class Stack : private std::vector<T>
{
public:
    // default constructor
    Stack() {}  

    // default destructor
    ~Stack() {}

    // returns true if the stack is empty
    bool empty() const 
    { 
        return std::vector<T>::empty();
    }

    // returns the size of the stack
    size_t size() const
    {
        return std::vector<T>::size(); 
    }
    
    // adds an element to the top of the stack
    void push(const T& item)
    {
        std::vector<T>::push_back(item); 
    }

    // removes the element at the top of the stack
    void pop()  // throws std::underflow_error if empty
    {
        if (empty())
        {
            throw std::underflow_error("Error: stack is empty.");
        }
        std::vector<T>::pop_back();
    }

    // returns the top element of the stack
    const T& top() const // throws std::underflow_error if empty
    {
        if (empty())
        {
            throw std::underflow_error("Error: stack is empty.");
        }
        return std::vector<T>::back(); 
    } 

    // Add other members only if necessary

};


#endif