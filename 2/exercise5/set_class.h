#pragma once
#include <iostream>
#include <queue>

template <typename T>
class Set {
private:
    std::queue<T> queue_;
	int size_ = 0;

public:
    // Function to add an element to the set
    void insert(const T& element);

    // Function to remove an element from the set
    void remove(const T& element);

    // Function to check if an element exists in the set
    bool contains(const T& element) const;

    // Function to get the size of the set
    size_t size() const;

    // Function to check if the set is empty
    bool isEmpty() const;

    // Function to display the elements of the set
    void display() const;
};
