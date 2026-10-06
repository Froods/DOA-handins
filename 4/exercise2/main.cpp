#include "min_heap.h"

int main()
{
    MinHeap<int> heat;

    heat.insert(5);
    heat.insert(2);
    heat.insert(20);
    heat.insert(7);
    heat.insert(17);
    heat.insert(1);

    std::cout << heat.peek() << std::endl;



    return 0;
}