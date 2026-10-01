#ifndef _QUICK_SORT_H_
#define _QUICK_SORT_H_

/**
 * Order left, center, and right and hide the pivot.
 * Then compute partition, restore the pivot and return its position.
 */
#include <vector>
using namespace std;

const int useInsertion = 16;

template <typename Comparable>
int partition(vector<Comparable>& a, int left, int right) {
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
	if (left == right) return;
	if (left == right-1 && a[left] > a[right]) {
		Comparable temp = a[right];
		a[right] = a[left];
		a[left] = temp;
		return;
	}

	int cur = left+1;
	int count = 0;
	while (cur <= right) {
		if (a[cur-1] <= a[cur]) {
			cur++;
			continue;
		}

		Comparable temp = a[cur];
		while (cur-count-1 >= left && a[cur-count-1] > a[cur-count]) {
			a[cur-count] = a[cur-count-1];
			a[cur-count-1] = temp;
			count++;
		}

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
	if (right - left <= useInsertion) {
		insertionSort(a,left,right);
		return;
	}
	int i = partition(a, left, right);
	quickSort(a, left, i - 1);	// Sort small elements
	quickSort(a, i + 1, right);	// Sort large elements
}

/**
 * Quicksort algorithm (driver).
 */
template <typename Comparable> void quickSort(vector < Comparable > &a) {
	quickSort(a, 0, a.size() - 1);
}

#endif
