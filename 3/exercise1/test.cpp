#include <iostream>

bool searchAlgorithm(int *A, int x, int N) {
    if (*A == x) return true;                   //Hvis match return true
	if (N == 1) return false;                   //Hvis intet match ved slutningen return false

	return searchAlgorithm(A+1, x, N-1);        //Recursive kald med næste element i array
}


int maxRecursive(int *arr, int size) {
    if (size == 1) return *arr; //Hvis function befinder sig på sidste index, returner blot værdien af dette index

    int maxOfRest = maxRecursive(arr + 1, size - 1);  //Initialiserer næste værdi til sammenligning og dekrementerer size 
	                    
    if(*arr > maxOfRest) return *arr;
	return maxOfRest;   
}

int minRecursive(int *arr, int size) {
    if (size == 1) return *arr; //Hvis function befinder sig på sidste index, returner blot værdien af dette index

    int minOfRest = maxRecursive(arr + 1, size - 1);  //Initialiserer næste værdi til sammenligning og dekremnterer size
	                    
    if(*arr < minOfRest) return *arr;
	return minOfRest;   
}

int main() {
	int test[] = {1,2,3,4};
    int test2[] = {0,2,3,1};
	
	std::cout << (searchAlgorithm(test,4,sizeof(test)/sizeof(int)) ? "Found!" : "Not found!") << "\n";

    std::cout << maxRecursive(test, sizeof(test)/sizeof(int)) << "\n";

    std::cout << maxRecursive(test2, sizeof(test2)/sizeof(int)) << "\n";
    
    std::cout << minRecursive(test2, sizeof(test2)/sizeof(int)) << "\n";

	return 0;
}