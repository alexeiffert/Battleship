#ifndef AI
#define AI

#include <string>

class Ai {
private:
	std::string difficulty;

	Ship carrier;
	Ship battleship;
	Ship cruiser;
	Ship submarine;
	Ship destroyer;

	int nextX;
	int nextY;

	int board [10][10];
public:

	//Constructs an AI object with default difficulty "easy"
	Ai(std::string difficulty = "easy");

	//Arranges ships at the start of the game only
	void arrangeShip();

	//Uses appropriate algorithm to pick attack square. Returns pointer to int[] with values (x,y)
	int* decideAttack(int board[10][10]);

	int getX();
};

#endif