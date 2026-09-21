#include "simple_list.h"
#include "reverse_list.h"
#include <iostream>

int main() {
	List<int> l;

	// Push back/front
	std::cout << "Push back/front:\n";
	l.push_back(2);
	l.push_front(1);
	l.push_back(3);
	l.print();

	// Pop back/front
	std::cout << "\nPop back/front:\n";
	l.pop_back();
	l.pop_front();
	l.print();

	// Check for value:
	std::cout << "\nCheck for value:\n";
	l.push_front(1);
	l.push_back(3);
	l.print();
	std::cout << (l.exists(3) ? "Number 3 is in list" : "number 3 isn't in list") << std::endl;
	std::cout << (l.exists(5) ? "Number 5 is in list" : "number 5 isn't in list") << std::endl;

	// Remove at index:
	std::cout << "\nRemove at index:\n";
	l.remove_at(1);
	l.print();

	// Insert at index:
	std::cout << "\nInsert at index:\n";
	l.insert_at(2,1);
	l.print();

	// Reverse list:
	std::cout << "\nReverse list:\n";
	reverse_list(l);
	l.print();

	return 0;
}