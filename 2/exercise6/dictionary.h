#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <string>

template <typename KeyType, typename ValueType>
class Dictionary {
private:
    std::vector<std::pair<KeyType, ValueType>> dictionary_;  // Vector to store key-value pairs

public:
    // Function to add a key-value pair to the dictionary
    void insert(const KeyType& key, const ValueType& value) {
		if (!contains(key)) {
			dictionary_.push_back({key, value});
		} else {
			for (int i = 0; i < dictionary_.size(); i++) {
				if (dictionary_[i].first == key) {
					dictionary_[i] = {key, value};
					return;
				}
			}
		}
    }

    // Function to remove a key-value pair from the dictionary
    void remove(const KeyType& key) {
        for (int i = 0; i < dictionary_.size(); i++) {
			if (dictionary_[i].first == key) {
				dictionary_.erase(dictionary_.begin() + i);
				return;
			}
		}
    }

    // Function to check if a key exists in the dictionary
    bool contains(const KeyType& key) const {
        for (int i = 0; i < dictionary_.size(); i++) {
			if (dictionary_[i].first == key) {
				return true;
			}
		}
        return false;
    }

    // Function to get the value associated with a key
    ValueType get(const KeyType& key) const {
		for (int i = 0; i < dictionary_.size(); i++) {
			if (dictionary_[i].first == key) {
				return dictionary_[i].second;
			}
		}
        throw std::runtime_error("Key not found!");  // Throw an exception if key is not found
    }

    // Function to get the size of the dictionary
    size_t size() const {
        return dictionary_.size();
    }

    // Function to check if the dictionary is empty
    bool isEmpty() const {
        return dictionary_.empty();
    }

    // Function to display all key-value pairs in the dictionary
    void display() const {
        if (dictionary_.empty()) {
            std::cout << "Dictionary is empty!\n";
            return;
        }
        for (const auto& pair : dictionary_) {
            std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
        }
    }
};

unsigned int hashFunction(const std::string& key) {
    unsigned int sum = 0;
    for (char c : key) {
        sum += static_cast<int>(c);
    }
    return sum;
}

unsigned int M;
unsigned int hashToArray(const std::string& key)
{
    return hashFunction(key) % M;
}

