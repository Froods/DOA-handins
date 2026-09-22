#include <iostream>

void printLine(int count){  //Funktion der printer den enkelte linje for trekanten med den ønskede længde
    for(int i = 0; i < count; i++) std::cout << "*";
    std::cout << std::endl;
}

void triangle(int m, int n){

    if (m <= n) {
		printLine(m);
		triangle(m+1, n);
		printLine(m);
	}

}

int main(){

    triangle(4,6);


    return 0;
}