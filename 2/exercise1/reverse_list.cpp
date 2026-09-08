#include "reverse_list.h"
#include "linkedList.h"
#include "node.h"
#include <iostream>
#include <vector>

void reverse_list(LinkedList& l) {
	if (l.get_size() <= 0) {
		std::cout << "List empty!" << std::endl;
		return;
	}
	if (l.get_size() == 1) {
		return;
	}

	std::vector<int> v;

	while (l.get_size() > 0) {
		v.push_back(l.get_tail()->val);
		l.pop_front();
	}

	for (int i = 0; i < v.size(); i++) {
		l.push_front(v[i]);
	}

}