#ifndef AI
#define AI

#include <string>
#include <iostream>
#include <stdlib.h> 
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
	Stack targets;

	Ship carrier;
	Ship battleship;
	Ship cruiser;
	Ship submarine;
	Ship destroyer;

	int nextAttack[2];

	int board [10][10];

	void fitAircraftcarrier(int board[10][10]);
	void fitBattleship(int board[10][10]);
	void fitSubmarine(int board[10][10]);
	void fitCruiser(int board[10][10]);
	void fitDestroyer(int board[10][10]);
	void probabilityCalculate(string board[10][10], int a, int b);
	void hunt(int board[10][10]);
	void lockTarget(int board[10][10]);

public:
	
	//Constructs an Ai object with default difficulty "easy"
	Ai(std::string difficulty = "easy");

	Ship printShip();
	//Arranges ships at the start of the game only
	void arrangeShip();

	//Uses appropriate algorithm to pick attack square. Returns pointer to int[] with values (x,y)
	int* easyAttack(int board[10][10]);
	int* normalAttack(int board[10][10]);
	int* hardAttack(int board[10][10]);
//	int* insaneAttack(int board[10][10]);

	int getX();
};

#endif