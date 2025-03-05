#include <iostream>
#include <functional>
#include "heap.h"

int main()
{
    // make a min heap with integers
    Heap<int> minHeap;
    minHeap.push(1);
    minHeap.push(5);
    minHeap.push(10);
    minHeap.push(2);  
    std::cout << "Min Heap: " ;
    while (!minHeap.empty())
    {
        // should print out 1,2,5,10
        std::cout << minHeap.top() << " ";
        minHeap.pop(); 
    }
    std::cout << std::endl;

    // make a min heap with strings
    // should be in alphabetical order
    Heap<std::string> minHeapStrings; 
    minHeapStrings.push("apple");
    minHeapStrings.push("baseball");
    minHeapStrings.push("cat");
    std::cout << "Min Heap w/ Strings: ";
    while (!minHeapStrings.empty())
    {
        std::cout << minHeapStrings.top() << " " ;
        minHeapStrings.pop();
    }
    std::cout << std::endl;

    // make a max heap with integers 
    Heap<int, std::greater<int>> maxHeap;  
    maxHeap.push(1);
    maxHeap.push(5);
    maxHeap.push(10);
    maxHeap.push(2);
    std::cout << "Max Heap: ";
    while (!maxHeap.empty()) 
    {
        // should print 10,5,2,1
        std::cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    std::cout << std::endl;

    return 0; 
}


