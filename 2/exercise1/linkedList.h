#pragma once
#include "node.h"

class LinkedList {
	public:
	LinkedList(int head);

	void push_back(int node);
	void push_front(int node);
	void insert_at(int val, int index);

	int pop_back();
	int pop_front();
	int remove_at(int index);

	int get_size();
	Node get_head();
	Node get_tail();

	bool exists(int val);

	void print();

	private:
	int size_;
	Node* head_;
	Node* tail_;

};
