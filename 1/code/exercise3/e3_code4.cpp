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

int sum = 0;                        // 1
for (i = 0; i < n; ++i) {
    for (j = 0; j < i; ++j) {
        ++sum;                  // 1
    }                           // ((N * N-1) / 2) * 1 + 1
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

}

