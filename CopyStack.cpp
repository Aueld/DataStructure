#include <iostream>
using namespace std;

class Stack {
private:
	int size;
	int top;
	int* buffer;

public:
	Stack() {}
	
	Stack(int size, int top, int* buffer) {
		this->size = size;
		this->top = top;
		this->buffer = buffer
	}

	Stack(Stack& s) {
		this->size = s.size;
		this->top = s.top;
		this->buffer[this->size] = s.buffer[s.size];
	}

	~Stack() {
		delete[] buffer;
	}

};
