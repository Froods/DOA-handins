#pragma once
#include <vector>
#include <cmath>
#include <bitset>
#include <string>
#include <iostream>

using namespace std;

template <typename T>
struct Node
{
	T data;
	Node *parent;
	Node *left;
	Node *right;
	// Constructor
	Node(T value)
	{
		data = value;
		parent = left = right = nullptr;
	}
};

template <typename T>
class MinHeap
{
private:
	int size = 0;
	Node<T> *root = nullptr;

public:
	void
	insert(const T &x)
	{
		// If it's the first element, make x the root in the tree
		if (size == 0)
		{
			root = new Node<T>(x);
			root->parent = nullptr;
			size++;
			return;
		}

		// Get binary number of position for next node
		// Using the binary we can decipher the path to reach the empty position where the insertion happens
		std::string binary_path = std::bitset<32>(size + 1).to_string();
		// Remove trailing zeroes
		binary_path = binary_path.substr(binary_path.find('1') == std::string::npos ? 31 : binary_path.find('1'));

		// Decipher the binary path to reach the posittion
		// for the next node to be inserted.
		// Insert newNode at that position.
		// 0 = left
		// 1 = right
		Node<T> *curNode = root;
		for (std::size_t i = 1; i < binary_path.size() - 1; i++)
		{
			if (binary_path[i] == '0')
			{
				curNode = curNode->left;
			}
			else
			{
				curNode = curNode->right;
			}
		}
		if (curNode->left == nullptr)
		{
			curNode->left = new Node<T>(x);
			curNode->left->parent = curNode;
			curNode = curNode->left;
		}
		else
		{
			curNode->right = new Node<T>(x);
			curNode->right->parent = curNode;
			curNode = curNode->right;
		}

		// Percolate up to maintain the min-heap property
		// Comparing the data of our current node to the data of the parent
		// For every instance where it's smaller the data is swapped keeping the nodes intact
		while (curNode->parent != nullptr && curNode->data < curNode->parent->data)
		{
			std::swap(curNode->data, curNode->parent->data);
			curNode = curNode->parent;
		}
		size++;
	}

	void remove()
	{
		// Check for size 0 and 1
		if (size == 0)
			return;
		if (size == 1)
		{
			delete root;
			root = nullptr;
			size--;
			return;
		}

		// First we get the binary number
		std::string binary_path = std::bitset<32>(size).to_string();
		// Remove trailing zeroes
		binary_path = binary_path.substr(binary_path.find('1') == std::string::npos ? 31 : binary_path.find('1'));

		// Finding the last element
		Node<T> *last = root;
		Node<T> *parent = nullptr;
		bool childIsLeft = true;
		for (std::size_t i = 1; i < binary_path.size(); i++)
		{
			if (binary_path[i] == '0')
			{
				parent = last;
				last = last->left;
				childIsLeft = true;
			}
			else
			{
				parent = last;
				last = last->right;
				childIsLeft = false;
			}
		}
		// Swapping data of last element and root
		std::swap(last->data, root->data);

		// Deleting the last element
		if (parent != nullptr) {
			if (childIsLeft) {
				parent->left = nullptr;
			} else {
				parent->right = nullptr;
			}
		}
		delete last;
		size--;

		// Percolating down from root to maintain the min-heap
		Node<T> *curNode = root;
		Node<T> *left = curNode->left;
		Node<T> *right = curNode->right;
		while (left != nullptr && right != nullptr && (right->data < curNode->data || left->data < curNode->data))
		{
			// Compare the childs data and swap data with the smallest one
			Node<T> *smallest = (left->data < right->data) ? left : right;
			std::swap(smallest->data, curNode->data);

			// Update pointers for next iteration
			curNode = smallest;
			left = curNode->left;
			right = curNode->right;
		}
		// If left still isn't a nullptr, check if there should be one last swap
		if (left != nullptr && curNode->data > left->data)
		{
			std::swap(curNode->data, left->data);
		}
	}

	// Returns true if the heap is empty, false if not
	bool isEmpty() const
	{
		if (size == 0)
			return true;

		return false;
	}

	// Returns the data of the root
	T peek()
	{
		return root->data;
	}
};