#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot)
{
    // base case: list is empty
    if (!head) {
        smaller = nullptr; 
        larger = nullptr; 
        return; 
    }

    // currentNode will be used to go through the list and sort 
    Node* currentNode = head; 
    // move head to be the next node 
    head = head->next;

    // recursive call 
    llpivot(head, smaller, larger, pivot); 

    // sort the current node into the correct list 
    // less than pivot = smaller
    // greater than pivot = larger
    if (currentNode->val > pivot)
    {
        currentNode->next = larger; 
        larger = currentNode;  
    }
    // node is less than or equal to pivot so goes into smaller
    else if (currentNode->val <= pivot)
    {
        currentNode->next = smaller; 
        smaller = currentNode; 
    }

    // head should be empty list by the end
    head = nullptr; 
}

