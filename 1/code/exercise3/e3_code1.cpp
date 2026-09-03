#include <cstdint>
#include <ctime>
#include <iostream>

int main(){

uint64_t sum = 0;
clock_t before = clock();

int n = 1000;
int i;

for (i = 0; i < n; ++i) {
    ++sum;                     
}       

clock_t after = clock() - before;

std::cout << "Code 1: " << sum << " Time: " << (double)after / CLOCKS_PER_SEC << std::endl;
std::cout << "Hej";
return 0;

}

