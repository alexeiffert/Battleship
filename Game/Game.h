#include <string>
#include <iostream>
#include "Ai.h"
#include "Ship.h"
#include "Board.h"


class Game {
private: 
		int rows;
		int columns;
		int maxShips;
		int shipsDestroyed;

public: 
	void gameOver(int shipsDestroyed, int maxShips);
	std::string checkWinner(int shipsDestroyed, int maxShips, std::string playerName);

};