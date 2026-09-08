#include "linkedList.h"
#include "reverse_list.h"
#include <iostream>

int main() {
	LinkedList l(1);
	l.push_back(2);
	l.push_back(3);

	l.print();

	l.pop_back();

	l.push_front(4);

	l.print();

	l.push_back(3);

	l.insert_at(10,2);

	std::cout << l.exists(3) << std::endl;
	std::cout << l.exists(5) << std::endl;

	l.print();

	l.remove_at(2);

	l.print();

	l.remove_at(0);

	l.print();

	l.remove_at(2);

	l.print();

	l.push_back(3);
	l.push_back(4);
	l.push_back(5);

	l.print();

	reverse_list(l);

	l.print();


	return 0;
}