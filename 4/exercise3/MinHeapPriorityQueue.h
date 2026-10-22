#include "priority_queue.h"
#include "min_heap.h"

template <typename T>
class MinHeapPriorityQueue : public PriorityQueue<T>
{
private:
MinHeap<T> heap;

//Public functions from PriorityQueue is overridden and implemented
//The functions from min_heap.h is used
public:
    void push(const T &x) override
    {
        heap.insert(x); //The MinHeap equivalent of push()
    }

    void pop() override
    {
        heap.remove(); //The MinHeap equivalent of pop()
    }

    T top() override
    {
        return heap.peek(); //The MinHeap equivalent of top()
    }

    bool empty() const override 
    {
        return heap.isEmpty(); //The MinHeap equivalent of empty()
    }

    ~MinHeapPriorityQueue() = default;

};