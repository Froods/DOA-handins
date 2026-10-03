#ifndef _QUICK_SORT_H_
#define _QUICK_SORT_H_

/**
 * Order left, center, and right and hide the pivot.
 * Then compute partition, restore the pivot and return its position.
 */
#include <vector>
#include <cassert>
using namespace std;

const int useInsertion = 16;

template <typename Comparable>
int partition(vector<Comparable>& a, int left, int right) {
	// Assertions
	assert(left >= 0);                  // left should be a valid index.
	assert(right < (int)a.size());      // right should be insside the index range of the array.
	assert(right - left >= 2);          // Make sure there are at least three elements in array to create partition.

	int center = (left + right) / 2;

	if (a[center] < a[left])
		std::swap(a[left], a[center]);
	if (a[right] < a[left])
		std::swap(a[left], a[right]);
	if (a[right] < a[center])
		std::swap(a[center], a[right]);

	// Place pivot at position right - 1
	std::swap(a[center], a[right - 1]);

	// Now the partitioning
	Comparable& pivot = a[right - 1];
	int i = left, j = right - 1;
	do {
		while (a[++i] < pivot);
		while (pivot < a[--j]);
		if (i < j) {
			std::swap(a[i], a[j]);
		}
	} while (i < j);

	std::swap(a[i], a[right - 1]);	// Restore pivot
	return i;
}

// Insertion sort
template <typename Comparable>
void insertionSort(vector<Comparable>& a, int left, int right) {
	// - Assertions
	assert(left >= 0);                  // left should be a valid index.
	assert(right < (int)a.size());      // right should be insside the index range of the array.
	assert(left <= right + 1);          // Code handles empty arrays gracefully already 
	                                    // (does nothing to them so prorgram wont crash).
								        // if left == right + 1 (0,-1), then the array is empty.
	
	// - Edge cases
	if (left == right) return;          // If array size is 1, simply return
	// If only two elements are in array
	if (left == right-1 && a[left] > a[right]) {
		Comparable temp = a[right];
		a[right] = a[left];
		a[left] = temp;
		return;
	}

	// - Algorithm
	int cur = left+1;                    // Start at index after first index
	int count = 0;                       // init counter for backtracking
	while (cur <= right) {
		// if element before current element is smaller, go forward
		if (a[cur-1] <= a[cur]) {
			cur++;
			continue;
		}

		Comparable temp = a[cur];        // Placeholder for current value
		// If element before current is bigger them swap them.
		// Here the count variable is used to go back through 
		// the array, to check the elements that came before 
		// the element that came before the current element.
		while (cur-count-1 >= left && a[cur-count-1] > a[cur-count]) {
			a[cur-count] = a[cur-count-1];
			a[cur-count-1] = temp;
			count++;
		}

		// Go to next element and reset count
		cur++;
		count = 0;
	}
}

/**
 * Internal quicksort method that makes recursive calls.
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
template <typename Comparable>
void quickSort(vector<Comparable>& a, int left, int right) {
	// - Assertions
	assert(left >= 0);                  // left should be a valid index.
	assert(right < (int)a.size());      // right should be insside the index range of the array.
	assert(left <= right + 1);          // Code handles empty arrays gracefully already 
	                                    // (does nothing to them so prorgram wont crash).
								        // if left == right + 1 (0,-1), then the array is empty.

	// - Case: insertionSort
	if (right - left <= useInsertion) {
		insertionSort(a,left,right);
		return;
	}

	// - Case: quickSort
	int i = partition(a, left, right);  // Create partitions for next quicksort recursion
	quickSort(a, left, i - 1);	        // Sort small elements
	quickSort(a, i + 1, right);	        // Sort large elements
}

/**
 * Quicksort algorithm (driver).
 */
template <typename Comparable> void quickSort(vector < Comparable > &a) {
	quickSort(a, 0, a.size() - 1);
}

#endif
