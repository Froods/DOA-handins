#ifndef _QUEUE_TESTSTACK_H_
#define _QUEUE_TESTSTACK_H_

#include <cassert>
#include "stack_class.h"

// Queue (FIFO) implemented with two Stacks (LIFO).
// Implements the Queue interface from queue_class.h: empty(), front(), get(), put(x)
//
// INVARIANT: 'out' always holds the whole queue with the FRONT element on top.
//            'in' is scratch space and is empty between operations.
template <typename Object>
class QueueStack {
  private:
	Stack<Object> out;   // front of the queue is on top - we always read from here
	Stack<Object> in;    // scratch space, empty between operations

  public:
	bool empty() { return out.empty(); }

	Object front() {
		assert(!empty());
		return out.top();
	}

	Object get() {
		assert(!empty());
		return out.pop();   // pop() returns the element
	}

	// The new element is the newest, so it must end up at the BOTTOM of 'out'.
	// 1) Unload 'out' onto 'in'.
	// 2) Put x into the now-empty 'out' - it becomes the bottom element.
	// 3) Pour 'in' back on top of it. Reversing twice restores the original order.
	void put(const Object x) {
		while (!out.empty()) {
			in.push(out.pop());
		}

		out.push(x);

		while (!in.empty()) {
			out.push(in.pop());
		}
	}
};

#endif