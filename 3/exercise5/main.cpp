#include "simple_list.h"
#include "reverse_list.h"
#include <iostream>

int main() {
	// Initialize list
	List<int> l;

	// Push back/front
	std::cout << "Push back/front:\n";
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	l.push_back(6);
	l.print();

	// Test search function
	std::cout << "Searching for 4, expecting index 3. Result: " << l.search(4) << "\n";
	std::cout << "Searching for 7, expecting error -1. Result: " << l.search(7) << "\n";

	return 0;
}