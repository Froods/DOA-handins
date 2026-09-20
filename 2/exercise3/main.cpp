#include "queue_stack.h"
#include <iostream>

//test program for queue with stacks
int main(int argc, char *argv[]) {
QueueStack<int> q;

std::cout << "Is queue empty? (1 = true, 0 = false) " << q.empty() << std::endl;


q.put(5);
q.put(7);
q.put(6);

std::cout << "Is queue empty after put? " << q.empty() << std::endl;

std::cout << "Front of the queue, should be 5: " << q.front() << std::endl;

std::cout << "Get() test, should pop 5: " << q.get() << "\nFront of queue should be 7 now: " << q.front();
return 0;
}