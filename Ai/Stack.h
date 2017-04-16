#ifndef STACK_H
#define STACK_H

#include <string>
#include <iostream>
#include <fstream>

struct Stack {
private:
	int size;
	int top;
	int** sArray;

public:
	//Constructor for stack object of size 'size'
	Stack(int size);
	
	//Push and pop ie LIFO methods
	void push(int square[2]);
	int* pop();

	//return size of stack
	int getSize();

	//Destructor
	~Stack();

};

#endif
