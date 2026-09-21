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
    bool contains(const T& element);

    // Function to get the size of the set
    size_t size();

    // Function to check if the set is empty
    bool isEmpty();

    // Function to display the elements of the set
    void display();
};

template <typename T>
void Set<T>::insert(const T &element)
{
    if (!contains(element)) {
		queue_.push(element);
		size_++;
	}
}

//Function to remove an element from the set
template <typename T>
void Set<T>::remove(const T &element)
{
   for (int i = 0; i < size_; i++) {
		auto val = queue_.front();

		queue_.pop();

		if (element == val){
			size_--;
			return;
		}

		queue_.push(val);
   }
}

//Function to check if an element exists in the set
template <typename T>
bool Set<T>::contains(const T &element)
{
    for (int i = 0; i < size_; i++) {
		auto val = queue_.front();

		queue_.pop();
		queue_.push(val);

		if (element == val){
			return true;
		}
   }
   return false;
}

//Function to get the size of the set
template <typename T>
size_t Set<T>::size()
{
	return size_;
}

//Function to check if the set is empty
template <typename T>
bool Set<T>::isEmpty()
{
    if (size_ == 0) return true;
    return false;
}

//Function to display the elements of the set
template <typename T>
void Set<T>::display()
{
    std::cout << "Values of set: " << std::endl;
    for (int i = 0; i < size_; i++) {
    auto val = queue_.front();

    std::cout << "{" << val << "}, ";
    
    queue_.pop();
	queue_.push(val);
   }
   std::cout << std::endl;
}