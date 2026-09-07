#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;
using namespace std::chrono;

int main(){

// Initialise sample
int n = 1000;
int i;
int j;

// Record starting time
    auto start =
    high_resolution_clock::now();


// Code

int sum = 0;                    
for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
        ++sum;                  
    }                           
}      

// Record ending time
    auto stop =
        high_resolution_clock::now();

    auto duration =
        duration_cast<microseconds>(
            stop - start);

    cout << "Sample size: " << n << endl
         << "Time taken: "
         << duration.count()
         << " microseconds";

    return 0;

return 0;

}

