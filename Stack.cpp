#include "Stack.h"

//Constructor for stack object. Note: note = size of array, top = number of objects stored in stack
Stack::Stack(int size) {
	this->size = size;
	int** sArray = new int*[size];
	top = 0;
}

//Push ie LIFO
void Stack::push(int square[2]) {
	top++;
	sArray[top] = *square;
}

//Pop ie LIFO
int* Stack::pop() {
	sArray[top] = 0;
	top--;
	return sArray[top + 1];
}

Stack::~Stack() {
	delete [] sArray;
}