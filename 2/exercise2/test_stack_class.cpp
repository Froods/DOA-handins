#include <iostream>
#include "stack_class.h"

int main(int argc, char *argv[]) {
	Stack<int> *stack = new Stack<int>();
	stack->push(10);
	stack->push(5);
	stack->push(3);
	stack->push(7);

	std::cout << "Top element:    " << stack->top() << std::endl;
	while (stack->empty() == false) {
		std::cout << "Next element:   " << stack->pop() << std::endl;
	}
	std::cout << "Stack is empty?  " << stack->empty() << std::endl;

	delete stack;


}

