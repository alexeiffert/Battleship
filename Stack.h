#ifndef PA3_H
#define PA3_H

#include <string>
#include <iostream>
#include <fstream>

struct Stack {
	int size;
	int top;
	std::string* sArray;

	//Constructor for stack object of size 'size'
	Stack(int size);
	
	//Push and pop ie LIFO methods
	void push(std::string string);
	std::string pop();

	//Destructor
	~Stack();

};

#endif
