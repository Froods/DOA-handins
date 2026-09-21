#ifndef _LIST_H_
#define _LIST_H_

template <typename Object>
class List {
  private:
	struct Node {
	    Object  data;
	    Node   *next;
	};
	int   theSize;
	Node *head;
	Node *tail;

  public:
	List() {
		theSize = 0;
		head = new Node; tail = new Node;
		head->next = tail;
		tail->next = nullptr;
	}

	~List() { clear(); delete head; delete tail; }

	int size() { return theSize; }
	bool empty() { return (size() == 0); }

	void clear();

	void push_front(const Object x);
	void push_back(const Object x);

	Object pop_front();
	Object pop_back();

	Object find_kth(int pos);

	void insert_at(Object x, int pos);
	Object remove_at(int pos);

	bool exists(Object x);

	void print();
};

#include "simple_list.tpp"

#endif
