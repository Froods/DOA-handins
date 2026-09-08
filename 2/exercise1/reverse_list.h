#pragma once

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
		
	}

}