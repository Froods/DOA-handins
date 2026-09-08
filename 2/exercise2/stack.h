#ifndef _STACK_H_
#define _STACK_H_

#include "../list/double_list.h"

template <typename Object>
class Stack {
  private:
	Object* arr_[];
	int counter_;


  public:
	Stack(int size = 100) {
		arr_ = new Object*[100];
	}

	~Stack() { delete[] arr; }

	bool empty() { return (arr_->size() == 0); }
	Object top() { return arr_->find_kth(0); }
	Object pop() { return arr_->pop_front(); }

	void push(const Object x) {
		arr_->push_front(x);
	}
};

#endif
