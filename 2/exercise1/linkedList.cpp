#include "linkedList.h"
#include "node.h"
#include <iostream>

LinkedList::LinkedList(int head) : size_(1) {
	head_ = new Node(head, nullptr);
	tail_ = head_;
}

void LinkedList::push_back(int node) {
	head_->next = new Node(node, nullptr);
	head_ = head_->next;
	size_++;
}

int LinkedList::pop_back() {
	int popped = -1;
	if (size_ <= 0) {
		std::cout << "Can't pop, list empty!" << std::endl;
		return popped;
	}
	if (size_ == 1) {
		popped = head_->val;
		delete head_;
		head_ = nullptr;
		tail_ = nullptr;
		size_ = 0;
		return popped;
	}

	Node* curNode = tail_;
	for (int i = 0; i < size_; i++) {
		if (curNode->next == head_) {
			popped = head_->val;
			delete head_;
			curNode->next = nullptr;
			head_ = curNode;
			size_--;
			return popped;
		}
		curNode = curNode->next;
	}
	return popped;
}

void LinkedList::insert_at(int val, int index) {
	if (size_ <= 0) {
		std::cout << "List is empty! Please use push_back() to insert first element." << std::endl;
		return;
	}
	if (index < 0 || index > size_) {
		std::cout << "Index can only range from: 0-" << size_ << "!" << std::endl;
		return;
	}
	
	Node* toInsert = new Node(val, nullptr);

	if (index == 0) {
		toInsert->next = tail_;
		tail_ = toInsert;
		size_++;
		return;
	}

	if (index == size_) {
		head_->next = toInsert;
		head_ = toInsert;
		size_++;
		return;
	}

	Node* curNode = tail_;
	for (int i = 0; i < index-1; i++) {
		curNode = curNode->next;
	}
	
	toInsert->next = curNode->next;
	curNode->next = toInsert;
	size_++;
}

int LinkedList::remove_at(int index) {
	int popped = -1;
	
	if (size_ <= 0) {
		std::cout << "List is empty, nothing to remove" << std::endl;
		return popped;
	}
	if (index < 0 || index >= size_) {
		std::cout << "Index can only range from: 0-" << size_-1 << "!" << std::endl;
		return popped;
	}

	Node* to_remove = nullptr;

	if (index == 0) {
		return pop_front();
	}

	if (index == size_-1) {
		return pop_back();
	}

	Node* prev = tail_;
	for (int i = 0; i < index-1; i++) {
		prev = prev->next;
	}
	
	to_remove = prev->next;
	popped = to_remove->val;
	prev->next = to_remove->next;
	delete to_remove;

	size_--;
	return popped;

}

void LinkedList::push_front(int node) {
	Node* toInsert = new Node(node, tail_);
	tail_ = toInsert;
	size_++;
}

int LinkedList::pop_front() {
	int popped = -1;
	
	if (size_ <= 0) {
		std::cout << "Can't pop, list empty!" << std::endl;
		return popped;
	}
	if (size_ == 1) {
		popped = head_->val;
		delete head_;
		head_ = nullptr;
		tail_ = nullptr;
		size_ = 0;
		return popped;
	}

	Node* toPop = tail_;
	popped = toPop->val;
	tail_ = tail_->next;
	delete toPop;
	size_--;
	
	return popped;
}

void LinkedList::print() {
	Node* curNode = tail_;
	for (int i = 0; i < size_; i++) {
		std::cout << curNode->val << ", ";
		curNode = curNode->next;
	}
	std::cout << std::endl;
}

Node LinkedList::get_head() {
	return *head_;
}

int LinkedList::get_size() {
	return size_;
}

Node LinkedList::get_tail() {
	return *tail_;
}

bool LinkedList::exists(int val) {
	Node* curNode = tail_;
	for (int i = 0; i < size_; i++) {
		if (curNode->val == val) return true;
		curNode = curNode->next;
	}
	return false;
}