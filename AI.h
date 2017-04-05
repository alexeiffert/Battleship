#ifndef AI
#define AI

#include <string>

class AI {
	std::string difficulty;
	int nextX;
	int nextY;

	AI(std::string difficulty = "easy");

	void arrangeShip();
	void decideAttack(int[] * board);
	int getX
};

#endif