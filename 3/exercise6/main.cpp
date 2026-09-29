#include "selection_sort.h"


int main(){

	//Testing with a vector of integers
	std::cout << "Test with integers" << std::endl;
	std::vector<int> ints = {4,12,5,28,55,1,3,9};
	std::cout << "Before sorting: ";
	print(ints);
	selectionSort(ints);
	std::cout << "After sorting: ";
	print(ints);
	std::cout << std::endl;

	//Testing with a vector of strings
	std::cout << "Test with strings: Sorted alphabetically" << std::endl;
	std::vector<std::string> strings = {"Pear", "Banana", "Apple", "Orange", "Clementine"};
	std::cout << "Before sorting: ";
	print(strings);
	selectionSort(strings);
	std::cout << "After sorting: ";
	print(strings);



	return 0;
}
