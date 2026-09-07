#include "book.h"

int Book::get_id() {
	return id_;
}

int Book::get_category() {
	return category_;
}

int Book::get_borrowed() {
	return borrowed_;
}

void Book::set_borrowed(bool y) {
	borrowed_ = y;

}