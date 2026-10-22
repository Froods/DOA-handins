#include "avl_tree.h"
#include <iostream>

// TEST PROGRAM
int main()
{
    AvlTree<int> avl; // Making the avl tree

    std::cout << "Testing that an empty AVL is valid: " << avl.verify() << "\n";

    std::cout << "Inserting elements 10, 20, 5, 15, 25\n";

    avl.insert(10);
    avl.insert(20);
    avl.insert(5);
    avl.insert(15);
    avl.insert(25);

    std::cout << "Testing that AVL is valid: " << avl.verify() << "\n";

    // No test with an invalid AVL can be made, because the values will reorder themselves to always be valid
}