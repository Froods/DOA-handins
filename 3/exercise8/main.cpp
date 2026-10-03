#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
#include <functional>
#include "quick_sort.h"
using namespace std;
using namespace std::chrono;

int main()
{
	function<int(int)> f = [](int n) {
		return rand() % n;
	};

	vector<int> sizes = {2000, 4000, 6000, 8000, 10000, 12000, 14000, 16000, 18000, 20000};

	cout << "Measurements for quickSort:\n";
	
	for (int n : sizes) {
		vector<int> v(n);

		generate(v.begin(),
             v.end(), bind(f,n));

		// Record starting time
		auto start =
			high_resolution_clock::now();

		// Function whose execution
		// time is to be measured
		quickSort(v);

		// Record ending time
		auto stop =
			high_resolution_clock::now();

		auto duration =
			duration_cast<microseconds>(
				stop - start);

		cout << "Time taken for vector of size " << n << ": " << duration.count() << " microseconds\n";

	}

	cout << "\n\nMeasurements for stlsort:\n";

	for (int n : sizes) {
		vector<int> v(n);

		generate(v.begin(),
             v.end(), bind(f,n));

		// Record starting time
		auto start =
			high_resolution_clock::now();

		// Function whose execution
		// time is to be measured
		sort(v.begin(), v.end()); // stlsort simply uses the built-in sort() algorithm

		// Record ending time
		auto stop =
			high_resolution_clock::now();

		auto duration =
			duration_cast<microseconds>(
				stop - start);

		cout << "Time taken for vector of size " << n << ": " << duration.count() << " microseconds\n";

	}

    return 0;
}