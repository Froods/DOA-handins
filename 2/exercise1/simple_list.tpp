#include <cassert>
#include <iostream>
#include "simple_list.h"

template <typename Object>
void List<Object>::clear() {
	Node *p = head->next;
	while (p != tail) {
		Node *t = p->next;
		delete p;
		p = t;
		head->next = t;
	}
}

template <typename Object>
void List<Object>::push_front(const Object x) {
	Node *p = new Node;
	p->data = x;
	p->next = head->next;
	head->next = p;
	theSize++;
}

template <typename Object>
void List<Object>::push_back(const Object x) {
	Node *p = new Node;
	p->data = x;
	p->next = tail;

	Node* cur = head;
	while (cur->next != tail) {
		cur = cur->next;
	}
	cur->next = p;
	theSize++;
}

template <typename Object>
Object List<Object>::pop_front() {
	Node *p = head->next;
	Object x = p->data;
	head->next = p->next;
	theSize--;
	delete p;
	return x;
}

template <typename Object>
Object List<Object>::pop_back() {
	Node *cur = head;
	while(cur->next->next != tail) {
		cur = cur->next;
	}

	Node *toDel = cur->next;
	Object x = toDel->data;
	cur->next = tail;

	theSize--;
	delete toDel;
	return x;
}

template <typename Object>
Object List<Object>::find_kth(int pos) {
	assert(pos >= 0 && pos < theSize);
	Node *p = head->next;
	while (pos > 0) {
		p = p->next;
		pos--;
	}
	return p->data;
}

template <typename Object>
void List<Object>::insert_at(Object x, int pos) {
	assert(pos >= 0 && pos < theSize);

	Node *newNode = new Node;
	newNode->data = x;

	Node *p = head;
	while (pos > 0) {
		p = p->next;
		pos--;
	}
	newNode->next = p->next;
	p->next = newNode;
	theSize++;
}

template <typename Object>
Object List<Object>::remove_at(int pos) {
	assert(pos >= 0 && pos < theSize);

	Node *p = head;
	while (pos > 0) {
		p = p->next;
		pos--;
	}
	Node *toDel = p->next;
	p->next = toDel->next;
	Object x = toDel->data;

	theSize--;
	delete toDel;
	return x;
}

template <typename Object>
bool List<Object>::exists(Object x) {
	Node *cur = head->next;

	while (cur != tail) {
		if (cur->data == x) return true;
		cur = cur->next;
	}
	return false;
}

template <typename Object>
void List<Object>::print() {
	Node *cur = head->next;

	while (cur != tail) {
		std::cout << cur->data << " ";
		cur = cur->next;
	}
	std::cout << std::endl;
}

