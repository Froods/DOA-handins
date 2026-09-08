#pragma once

struct Node {
	int val;
	Node* next;

	Node(int x, Node* nextNode) : val(x), next(nextNode) {}
};