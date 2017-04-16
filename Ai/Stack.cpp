#include "Stack.h"

//Constructor for stack object. Note: note = size of array, top = number of objects stored in stack
Stack::Stack(int size) {
	this->size = size;
	sArray = new int*[size];
	for (int i = 0; i < size; i++) {
		sArray[i] = nullptr;
	}
	top = 0;
}

//Push ie LIFO
void Stack::push(int square[2]) {
	top++;
	sArray[top] = square;
}

//Pop ie LIFO
int* Stack::pop() {
	int* temp = sArray[top];
	sArray[top] = nullptr;
	top--;
	return temp;
}

int Stack::getSize() {
	return size;
}

Stack::~Stack() {
	delete[] sArray;
}