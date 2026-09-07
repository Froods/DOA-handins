#pragma once
#include <vector>
#include "book.h"
#include <iostream>

class Library {

public:
    Library();
    
    void addBook(int id, int category);
    bool borrowBook(int id);
    bool returnBook(int id);

    void displayAllBooks();
    void displayBorrowedBooks();
    void displayAvailableBooks();

    int getBookAmount();

	int countBooksInCategory(int category);

private:
    std::vector<Book> books_;
	std::vector<int> booksInCategories_;

};