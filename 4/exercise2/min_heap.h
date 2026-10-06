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
	Node<T>* root = nullptr;

	public :
	
	void
	insert(const T &x)
	{
		//If it's the first element, make x the root in the tree
		if (size == 0)
		{
			root = new Node<T>(x);
			size++;
			return;
		}

		//Get binary number of position for next node
		//Using the binary we can decipher the path to reach the empty position where the insertion happens
		std::string binary_path = std::bitset<32>(size).to_string();
		// Remove trailing zeroes
		binary_path = binary_path.substr(binary_path.find('1') == std::string::npos ? 31 : binary_path.find('1'));
		
		// Decipher the binary path to reach the posittion 
		// for the next node to be inserted.
		// Insert newNode at that position.
		// 0 = left
		// 1 = right
		Node<T>* curNode = root;
		for (std::size_t i = 1; i < binary_path.size(); i++){
			if (binary_path[i] == '0') {
				curNode = curNode->left;
			} else {
				curNode = curNode->right;
			}
		}
		(curNode->left == nullptr) ? curNode->left = new Node(x) : curNode->right = new Node(x);

		//Percolate up to maintain the min-heap property
		//Comparing the data of our current node to the data of the parent
		//For every instance where it's smaller the data is swapped keeping the nodes intact
		while (curNode->data < curNode->parent->data){
			std::swap(curNode->data, curNode->parent->data);
			curNode = curNode->parent;
		}
		size++;

	}

	
	void remove()
	{
		//
		//Node<T>
	}


	bool isEmpty() const
	{
		// YOUR CODE GOES HERE

		if (size == 0)
			return true;

		return false;
	}

	
	T peek()
	{
		return root->data;
	}
};