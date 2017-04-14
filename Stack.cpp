#include "Stack.h"

//Constructor for stack object. Note: note = size of array, top = number of objects stored in stack
Stack::Stack(int size) {
	sArray = new std::string[size];
	this->size = size;
	top = 0;
}

//Push ie LIFO
void Stack::push(std::string string) {
	sArray[top] = string;
	top++;
}

//Pop ie LIFO
std::string Stack::pop() {
	top--;
	return sArray[top];
	sArray[top] = nullptr;
}

Stack::~Stack() {
	delete [] sArray;
}