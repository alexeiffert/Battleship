//#ifndef AI
//#define AI

#include <string>

class AI {
private:
	std::string difficulty;
	int nextX;
	int nextY;

public:
	AI(std::string difficulty);

	void arrangeShip();
	void decideAttack(int[] board);
	int getX();
};

//#endif