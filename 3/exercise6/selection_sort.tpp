#include <algorithm>
#include <iostream>

template <typename Object>
void selectionSort(std::vector<Object>& a){
	
	int smallest; //Initialising the integer that stores the index of the smallest item while looping
	
	for (int i = 0; i < a.size(); i++){ 		  //Outer loop handles has index i
		smallest = i;
		for (int j = i+1; j < a.size(); j++){	  //Inner loop finds the smallest item on each iteration of the vector starting 1 past the previous replacement index
			if(a[j] < a[smallest]) smallest = j;
		}
		if(smallest != i) std::swap(a[i],a[smallest]);			  //After each inner loop the smallest item is swapped with the current index in the vector
	}

}


template <typename Object>
void print(std::vector<Object>& a){	 //Function to print output for testing
	for (auto i : a){
		std::cout << i << " ";
	}
	std::cout << std::endl;
}
