#include "dictionary.h"

// Main function to demonstrate the functionality of the generic Dictionary ADT
int main() {
    // Dictionary with integer keys and string values
    Dictionary<int, std::string> intToStringDict;
    intToStringDict.insert(1, "One");
    intToStringDict.insert(2, "Two");
    intToStringDict.insert(2, "Twoish");
    intToStringDict.insert(3, "Three");

    std::cout << "Integer to String Dictionary:" << std::endl;
    intToStringDict.display();

    std::cout << "Contains key 2: " << (intToStringDict.contains(2) ? "Yes" : "No") << std::endl;
    std::cout << "Value for key 2: " << intToStringDict.get(2) << std::endl;

    // Remove an item and display again
    intToStringDict.remove(2);
    intToStringDict.display();

    // Dictionary with string keys and double values
    Dictionary<std::string, double> stringToDoubleDict;
    stringToDoubleDict.insert("pi", 3.14159);
    stringToDoubleDict.insert("e", 2.71828);

    std::cout << "\nString to Double Dictionary:" << std::endl;
    stringToDoubleDict.display();

    std::cout << "Value for key 'pi': " << stringToDoubleDict.get("pi") << std::endl;

    return 0;
}
