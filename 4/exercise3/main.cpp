#include "MinHeapPriorityQueue.h"
#include <iostream>

int main()
{
    //Test for MinHeapPriorityQueue
    MinHeapPriorityQueue<int> mhpq;

    std::cout << "Is queue empty: " << mhpq.empty() << "\n\n";
    std::cout << "Pushing integers 5, 3, 10\n\n";
    mhpq.push(5);
    mhpq.push(3);
    mhpq.push(10);

    std::cout << "Is queue empty after push: " << mhpq.empty() << "\n\n";
    std::cout << "The front of the queue: " << mhpq.top() << "\n\n";

    std::cout << "Popping the front\n\n";
    mhpq.pop();

    std::cout << "Front of the queue after pop: " << mhpq.top() << "\n\n";

    return 0;
}