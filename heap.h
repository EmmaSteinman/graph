#include <string>
#include <fstream>

const int DEFAULT_SIZE = 100;
using namespace std;
template <class KeyType>
class MinHeap
{
public:
      MinHeap(int n = DEFAULT_SIZE);          // default constructor
      MinHeap(KeyType* initA[], int n);        // construct heap from array
      MinHeap(const MinHeap<KeyType>& heap);  // copy constructor
      ~MinHeap();                             // destructor
      void heapSort(KeyType* sorted[]);  // heapsort, return result in sorted
      std::string toString() const;     // return string representation
      MinHeap<KeyType>& operator=(const MinHeap<KeyType>& heap);  // assignment operator

protected:
      KeyType **A;     // array containing the heap
      int heapSize;   // size of the heap
      int capacity;   // size of A
      void buildHeap();                 // build heap
      int leftChild(int index) { return 2 * index + 1; }  // return index of left child
      int rightChild(int index) { return 2 * index + 2; } // return index of right child
      int parent(int index) { return (index - 1) / 2; }   // return index of parent
      void swap(int index1, int index2);        // swap elements in A
      void copy(const MinHeap<KeyType>& heap);  // copy heap to this heap
      void heapify(int index);          // heapify subheap rooted at index

      void destroy();                           // deallocate heap
};
#include "heap.cpp"
