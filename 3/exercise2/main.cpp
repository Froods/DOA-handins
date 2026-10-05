#include <iostream>

void printLine(int count){  //Funktion der printer den enkelte linje for trekanten med den ønskede længde
    for(int i = 0; i < count; i++) std::cout << "*";
    std::cout << std::endl;
}

void triangle(int m, int n){

    if (m <= n) {           //For m mindre eller lig med n skal der tegnes
		printLine(m);       //Winding inden recursion kald
		triangle(m+1, n);   //Recursive kald som fortsætter indtil if statement er false
		printLine(m);       //Unwinding af recursion kald
	}

}

int main(){

    triangle(4,6);

    return 0;
}