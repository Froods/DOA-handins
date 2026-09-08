#ifndef _STACK_H_
#define _STACK_H_

template <typename Object>
class Stack {
  private:
	Object* array_;
	int capacity_;
	int counter_;

  public:
	Stack(int size = 100) {
		capacity_ = size;
		array_ = new Object[capacity_];
		counter_ = 0;
	}

	~Stack() { delete[] array_; }

	bool empty() { return counter_ == 0; }
	Object top() { return array_[counter_ - 1] }
	Object pop() { return array_; }

	void push(const Object x) {
		if (counter_ == capacity_) {				//Tjek om kapacitet er nået
			int newCapacity = capacity_ * 2;		//Opret ny kapacitet
			newArray_ = new Object[newCapacity];    //Nyt array med ny kapacitet
			for (int i = 0; i < capacity_; i++) {newArray_[i] = array_[i];}		//Kopier gamle værdier til nyt array
			~Stack();				    //Slet gammelt array
			array_ = newArray_;		    //Ret pointer til nyt array
			capacity_ = newCapacity;	//Opdater kapacitet
		}
		array_.[counter_] = x;	//Tilføjer element til array
		counter_++;				//Inkrementer counter
	}
};

#endif
