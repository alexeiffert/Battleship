#include "Ai.h"


Ai::Ai(std::string difficulty) {
	this->difficulty = difficulty;
};

Ship Ai::printShip() {
	return carrier;
}

//Arranges ships at the start of the game only
void Ai::arrangeShip() {
	carrier.yStart = 1;
	carrier.xStart = 1;

	battleship.yStart = 1;
	battleship.xStart = 1;

	cruiser.yStart = 1;
	cruiser.xStart = 1;

	submarine.yStart = 1;
	submarine.yStart = 1;

	destroyer.yStart = 1;
	destroyer.yStart = 1;
};

int* Ai::easyAttack(int board[10][10]) {

	int attack[2];

	for (int i = 0; i < 10; i++) {
		for (int j = 10; j < 10; j++)
			if (!board[i + rand() % 10][j + rand() % 10]) {
				attack[0] = i;
				attack[1] = j;
				return attack;
			}
	}
	return nullptr;
};

int* Ai::normalAttack(int board[10][10]) {

	int attack[2];

	if (!target) {
		return easyAttack(board);
	}
	else if (target) {
		for (int i = -1; i = 1; i += 2) {
			for (int j = -1; i = 1; i += 2) {
				if (board[i + target[0]][j + target[1]]) {
					continue;
				}
				else {
					attack[0] = i;
					attack[1] = j;
				}
			}
		}
	}
	return attack;
}

int* Ai::hardAttack(int board[10][10]) {
	//TODO
	int x[1];
	return x;
}

int Ai::getX() {
	return 1;
};
