#include <vector>
#include "binary_search_tree.h"

using namespace std;

template<typename Comparable>
class OrderedSet {
  private:
	size_t theSize;
	BinarySearchTree<Comparable> tree;

  public:
	OrderedSet() { }

	~OrderedSet() { clear(); }

	OrderedSet(const OrderedSet& s) {
		auto t = s.begin();

		while (t != s.end()) {
			push(*t);
			t++;
		}
	}

	void clear() {
		tree.makeEmpty();
		theSize = 0;
	}

	size_t size() const {
		return theSize;
	}

	bool empty() const {
		if (theSize != 0) return false;
		return true;
	}

	void push(const Comparable& t) {
		if (!tree.contains(t)) theSize++;
		tree.insert(t);
	}

	friend class BinarySearchTree<Comparable>;
	typedef typename BinarySearchTree<Comparable>::iterator iterator;

	iterator begin() const {
		return {tree.findMin()};	//Returns a BinaryNode pointer to the smallest element (Same as what the iterator consists of)
	}

	iterator end() const {
		return nullptr;				//Returns nullptr since thats what the end should be
	}

	iterator insert(const Comparable& t) {
		if (!tree.contains(t)) theSize++;		//Increments size if the element is a non duplicate
		return {tree.insert(t)};				//Inserts element
	}

	iterator find(const Comparable& t) {
		return {tree.find(t)};					//Returns a BinaryNode pointer to the element if it exists, otherwise returns nullptr
	}

	iterator erase(iterator& itr) {
		if (tree.contains(t)) theSize--;		//Decrements size if the element exists in the tree
		return {tree.erase(itr)};				//Erases element and returns an iterator to the next element in the tree
	}
};
