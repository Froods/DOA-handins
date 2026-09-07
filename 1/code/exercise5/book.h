#pragma once

class Book
{
    public:
	Book(int id, int category) : id_(id), category_(category) {}
    
	int get_id();
	int get_category();
	int get_borrowed();
	void set_borrowed(bool y);
    
    private:
    int id_;
    int category_;
	bool borrowed_ = false;
};