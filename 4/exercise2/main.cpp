#include "min_heap.h"

int main()
{
    MinHeap<int> heap;


    std::cout << "Checking if heap is empty before inserting: " << heap.isEmpty() << "\n\n";

    std::cout << "Inserting integers 5, 2, 20, 7, 1, 17\n\n";
    heap.insert(5);
    heap.insert(2);
    heap.insert(20);
    heap.insert(7);
    heap.insert(1);
    heap.insert(17);

    std::cout << "Checking if heap is empty after insertion: " << heap.isEmpty() << "\n\n";

    std::cout << "Peeking at the root of the heap, which should be 1: " << heap.peek() << "\n\n";
    
    std::cout << "Removing the root of the heap\n\n";

    while (!heap.isEmpty()){
        heap.remove();
        std::cout << "Root of heap after removing: " << heap.peek() << "\n";
    }


    
    return 0;
}