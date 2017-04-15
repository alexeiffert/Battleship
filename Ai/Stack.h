#ifndef STACK_H
#define STACK_H

#include <string>
#include <iostream>
#include <fstream>

struct Stack {
	int size;
	int top;
	int* sArray;

	//Constructor for stack object of size 'size'
	Stack(int size);
	
	//Push and pop ie LIFO methods
	void push(int square[2]);
	int* pop();

	//Destructor
	~Stack();

};

#endif
