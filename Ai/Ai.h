#ifndef AI
#define AI

#include <string>
#include <stdlib.h> 

class Ai {
private:
	std::string difficulty;
	int target[2];

	Ship carrier;
	Ship battleship;
	Ship cruiser;
	Ship submarine;
	Ship destroyer;

	int nextAttack[2];

	int board [10][10];
public:

	//Constructs an Ai object with default difficulty "easy"
	Ai(std::string difficulty = "easy");

	//Arranges ships at the start of the game only
	void arrangeShip();

	//Uses appropriate algorithm to pick attack square. Returns pointer to int[] with values (x,y)
	int* easyAttack(int board[10][10]);
	int* normalAttack(int board[10][10]);
	int* hardAttack(int board[10][10]);
	int* insaneAttack(int board[10][10]);

	int getX();
};

#endif