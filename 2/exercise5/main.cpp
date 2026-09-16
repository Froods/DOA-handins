#include <iostream>
#include "set_class.h"

// Main function to demonstrate the functionality of the Set list ADT
int main() {
    Set<int> intSet;
    Set<std::string> stringSet;

    // Working with integer set
    std::cout << "Integer Set:" << std::endl;
    intSet.insert(10);
    intSet.insert(20);
    intSet.insert(30);
    intSet.insert(40);
    intSet.display();

    std::cout << "Contains 20: " << (intSet.contains(20) ? "Yes" : "No") << std::endl;
    intSet.remove(30);
    intSet.display();

    // Working with string set
    std::cout << "\nString Set:" << std::endl;
    stringSet.insert("apple");
    stringSet.insert("banana");
    stringSet.insert("cherry");
    stringSet.display();

    std::cout << "Contains 'banana': " << (stringSet.contains("banana") ? "Yes" : "No") << std::endl;
    stringSet.remove("banana");
    stringSet.display();

    return 0;
}
