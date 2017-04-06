#ifndef AI
#define AI

#include <string>

class Ai {
private:
	std::string difficulty;
	int nextX;
	int nextY;

public:
	Ai(std::string difficulty = "easy");

	void arrangeShip();
	void decideAttack(int[] board);
	int getX();
};

#endif
