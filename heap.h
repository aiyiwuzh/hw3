#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <algorithm>

// default comparator will create a min-heap since it is comparing which element is less 
template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below

  PComparator comparator_; 
  std::vector<T> heap;
  size_t m_; 

  // helper function to heapify up to maintain the heap property 
  void heapifyUp(size_t index) {
    while (index > 0) 
    {
      size_t parent = (index - 1) / m_; 
      if (comparator_(heap[index], heap[parent])) {
        std::swap(heap[index], heap[parent]);
        index = parent; 
      }
      else 
      {
        break; 
      }
    }
  }

  // helper function to heapify down to maintain the heap property
  void heapifyDown(size_t index) {
    size_t best = index;
    size_t next = m_ * index + 1; 

    for (size_t i = 0; i < m_; i++)
    {
      if ((next + i) < heap.size() && comparator_(heap[next + i], heap[best]))
      {
        best = (next + i); 
      }
    }
   
    if (best != index)
    {
      std::swap(heap[index], heap[best]);
      heapifyDown(best); 
    }
  }

};

// Add implementation of member functions here

// Constructor
template <typename T, typename PComparator> 
Heap<T,PComparator>::Heap(int m, PComparator c) : comparator_(c), m_(m)
{ }

// Destructor
template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap() 
{ }

// Pushes an item to the heap 
template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) 
{
  heap.push_back(item); 
  heapifyUp(heap.size() - 1);
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Cannot top(), heap is empty.");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return heap[0];
}


// We will start pop() for you to handle the case of 
// calling pop on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Cannot pop(), heap is empty.");
  }

  // swap top element with last element
  std::swap(heap[0], heap.back()); 

  // remove back element (top element)
  heap.pop_back(); 

  if (!empty())
  {
    heapifyDown(0); 
  }
}

// Returns true if the heap is empty
template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const 
{
  return heap.empty();
}

// Returns the size of the heap 
template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return heap.size(); 
}

#endif

