#include "queue_teststack.h"
#include <iostream>

//test program for queue with stacks
int main(int argc, char *argv[]) {
QueueStack<int> q;

std::cout << "Is queue empty? " << q.empty() << std::endl;


q.put(5);
q.put(7);
q.put(6);

std::cout << "Is queue empty after put? " q.empty() << std::endl;

std::cout << "Front of the queue, should be 5: " << q.front() << std::endl;



}