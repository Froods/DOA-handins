#include "library.h"
#include <vector>
#include "book.h"
#include <iostream>

Library::Library() : booksInCategories_(16, 0) {
}

void Library::addBook(int id, int category) 
{
	// Tjek om kategori er valid
	if (category < 0 || category > 15) {
		std::cout << "Please enter a valid category." << std::endl;
		return;
	}

	// Se om ID allerede er optaget
	for (auto& b : books_) {
		if (b.get_id() == id) {
			std::cout << "Book id already taken!" << std::endl;
			return;
		}
	}
	// Hvis ikke det er optaget, tilføj bog, og inkrementer tælleren hos dens kategori
    books_.push_back({id,category});
	booksInCategories_[category] += 1; // Inkrementer antallet af bøger i den givne kategori
	
	// Tjek om antallet i en kategori overstiger gennemsnittet af bøger i en kategori gange 2
	int nonEmptyCategories = 0;
	for (int i = 0; i <= 15; i++) {
		if (booksInCategories_[i] > 0) nonEmptyCategories++;
	}

	if (nonEmptyCategories > 0) {
		float twiceAvg = (books_.size() / nonEmptyCategories) * 2; // Kategori kan være fra 0 - 15, hvilket giver os 16 kategorier
		if (booksInCategories_[category] > twiceAvg) {
			std::cout << "Category " << category << " has twice as many books as the average of each category!" << std::endl;
		}
	}

}                


bool Library::borrowBook(int id) {
	for (auto& b : books_) {
		if (b.get_id() == id) {
			if (b.get_borrowed() == false) {
				b.set_borrowed(true);
				return true;
			} else {
				std::cout << "Book already borrowed" << std::endl;
				return false;
			}
		}
	}
	std::cout << "Book id not in library";
	return false;
}

bool Library::returnBook(int id) {
    for (auto& b : books_) {
		if (b.get_id() == id) {
			if(b.get_borrowed()) {
				b.set_borrowed(false);
				std::cout << "Book with id: " << id << " returned!" << std::endl;
				return true;
			} else {
				std::cout << "Book not borrowed yet, so can't return" << std::endl;
				return false;
			}
		}
	}
	return false;
}

void Library::displayAvailableBooks() {
	for (auto& b : books_) {
		if (b.get_borrowed() == false) {
			std::cout << "Book id: " << b.get_id() << " | Category: " << b.get_category() << "\n";
		}
    }
}

void Library::displayBorrowedBooks() {
	for (auto& b : books_) {
		if (b.get_borrowed() == true) {
			std::cout << "Book id: " << b.get_id() << " | Category: " << b.get_category() << "\n";
		}

	}
}

void Library::displayAllBooks() {
	for (auto& b : books_) {
		if (b.get_borrowed()) {
			std::cout << "Book id: " << b.get_id() << " | Category: " << b.get_category() << " | Currently borrowed" << "\n";
		} else {
			std::cout << "Book id: " << b.get_id() << " | Category: " << b.get_category() << " | Available" << "\n";
		}
	}
}

int Library::getBookAmount() {
	return books_.size();
}

int Library::countBooksInCategory(int category) {
	return booksInCategories_[category];
}