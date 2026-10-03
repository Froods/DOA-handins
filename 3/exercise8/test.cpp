#include <iostream>
#include <vector>
#include "quick_sort.h"
#include <cstdlib>   // rand, srand
#include <ctime>     // time

int main() {
	srand(time(nullptr)); // seed

	// Before
	std::cout << "Vector before sorting:\n";
	std::vector<int> v(100);
	for (int& element : v) {
		element = rand() % 101;
		std::cout << element << " ";
	}
	std::cout << "\n";

	// After
	std::cout << "Vector before sorting:\n";
	quickSort(v);
	for (int& element : v) {
		std::cout << element << " ";
	}
	std::cout << "\n";
	
	return 0;
}