#ifndef AI
#define AI

#include <string>
#include <iostream>
#include <stdlib.h> 
#include <time.h>
#include <iomanip>
#include "Stack.h"

class Ship {
public:
	int size;
	int xStart;
	int yStart;
};

class Ai {

private:
	std::string difficulty;
	int target[2];
	Stack targetStack;

	//Each "Ai object" possesses the 5 standard ships
	Ship carrier;
	Ship battleship;
	Ship cruiser;
	Ship submarine;
	Ship destroyer;

	//Used in the Ai's Insane mode to calculate square probabilities
	void enumerateTallies(int board[10][10], int shipSize);
	double probabilityBoard[10][10];

public:
	//Constructs an Ai object with default difficulty "easy"
	Ai(std::string difficulty = "easy");

	//Prints a visualization of the Ai's probability density function
	void printRadar();

	//Blanket method for selecting the correct attack based on string difficulty
	int* attack(int board[10][10]);

	//Arranges ships at the start of the game only
	void arrangeShip();

	//Uses appropriate algorithm to pick attack square. Returns pointer to int[] with values (x,y)
	int* easyAttack(int board[10][10]);
	int* normalAttack(int board[10][10]);
	int* insaneAttack(int board[10][10]);

};

#endif