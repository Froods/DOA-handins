#include "set_class.h"

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
bool Set<T>::contains(const T &element) const
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
size_t Set<T>::size() const
{
	return size_;
}

//Function to check if the set is empty
template <typename T>
bool Set<T>::isEmpty() const
{
    if (size_ == 0) return true;
    return false;
}

//Function to display the elements of the set
template <typename T>
void Set<T>::display() const
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