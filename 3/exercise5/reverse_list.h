#pragma once

#include "simple_list.h"
#include <iostream>
#include <vector>

template<typename Object>
void reverse_list(List<Object>& l) {
	if (l.size() <= 1) return;

	List<Object> temp;

	while (!l.empty()) {
		temp.push_front(l.pop_front());
	}

	while (!temp.empty()) {
        l.push_back(temp.pop_front());
    }
}