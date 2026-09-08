#pragma once

#include "linkedList.h"
#include "node.h"
#include <iostream>
#include <vector>

LinkedList reverse_list(LinkedList l) {
	if (l.get_size() <= 0) {
		std::cout << "List empty!" << std::endl;
		return false;
	}
	if (l.get_size() == 1) {
		return l;
	}


}