#include "Ai.h"

Ai::Ai(std::string difficulty) : targets(4)
{
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

	if (targets.pop()) {

		attack[0] = targets.pop()[0];
		attack[1] = targets.pop()[1];

//		for (int i = -1; i = 1; i += 2) {
//			for (int j = -1; i = 1; i += 2) {
//				if (board[i + target[0]][j + target[1]]) {
//					continue;
//				}
//				else {
//					attack[0] = i;
//					attack[1] = j;
//				}
//			}
//		}
	}
	else {
		return easyAttack(board);
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

void Ai::fitAircraftcarrier(int board[10][10])
{
	int count = 0;
	for (int i = 0; i < 10; i++) {		//ready all the possible space for Carrier first(still working)
		for (int j = 0; j < 10; j++) {
			if (i < 10 && j < 6) {
				if (board[i][j] == board[i][j + 1]== board[i][j + 2]== board[i][j + 3]== board[i][j + 4]) { count++; }
			}

			if (i < 6 && j < 10) {
				if (board[i][j] == board[i + 1][j] == board[i + 2][j] == board[i + 3][j] == board[i + 4][j]) { count++; }
			}
		}
	}
}
void Ai::fitBattleship(int board[10][10])
{
	int count = 0;
	for (int i = 0; i < 10; i++) {			//read all the possible space for Battleship first(still working)
		for (int j = 0; j < 10; j++) {
			if (i < 10 && j < 7) {
				if (board[i][j] == board[i][j + 1]== board[i][j + 2]== board[i][j + 3]) { count++; }
			}

			if (i < 7 && j < 10) {
				if (board[i][j] == board[i + 1][j]== board[i + 2][j]== board[i + 3][j]) { count++; }
			}
		}
	}
}
void Ai::fitSubmarine(int board[10][10])
{
	int count = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (i < 10 && j < 8) {
				if (board[i][j] == board[i][j + 1]== board[i][j + 2]) { count++; }
			}

			if (i < 8 && j < 10) {
				if (board[i][j] == board[i + 1][j]== board[i + 2][j]) { count++; }
			}
		}
	}
}
void Ai::fitCruiser(int board[10][10])
{
	int count = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (i < 10 && j < 8) {
				if (board[i][j] == board[i][j + 1] == board[i][j + 2]) { count++; }
			}

			if (i < 8 && j < 10) {
				if (board[i][j] == board[i + 1][j] == board[i + 2][j]) { count++; }
			}
		}
	}
}

void Ai::fitDestroyer(int board[10][10])
{
	int count = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (i < 10 && j < 9) {
				if (board[i][j] == board[i][j + 1]) { count++; }
			}

			if (i < 9 && j < 10) {
				if (board[i][j] == board[i + 1][j]) { count++; }
			}
		}
	}
}

void probabilityCalculate(int board[10][10], int a, int b) {
	int iAttack = a, jAttack = b;
	int probabilityBoard[10][10] = { { 1,2,3,4,5,5,4,3,2,1 },{ 2,3,4,5,6,6,5,4,3,2 },
	{ 3,4,5,6,7,7,6,5,4,3 },{ 4,5,6,7,8,8,7,6,5,4 },
	{ 5,6,7,8,9,9,8,7,6,5 },{ 5,6,7,8,9,9,8,7,6,5 },
	{ 4,5,6,7,8,8,7,6,5,4 },{ 3,4,5,6,7,7,6,5,4,3 },
	{ 2,3,4,5,6,6,5,4,3,2 },{ 1,2,3,4,5,5,4,3,2,1 } };

	if (target) {
		probabilityBoard[iAttack][jAttack] = -999; //set this square's probability to -999 because this square cannot be hit anymore
												   //When a hit on the target, we can set all the probaility is 1 except those squares has been hit but not on the target
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (probabilityBoard[i][j] != -999) {
					probabilityBoard[i][j] = 1;
				}
			}
		}

		for (int i = 0; i < iAttack; i++) {	   //then here, we will change the probability around the target square, once distance is closer to target, the probability is larger
			if (probabilityBoard[i][jAttack] != -999) {
				probabilityBoard[i][jAttack] = i + 2; //the reason to add 2 is that will always bigger than 1 which is other unrelated square's probability
			}
		}

		for (int i = 9; i > iAttack; i--) {
			if (probabilityBoard[i][jAttack] != -999) {
				probabilityBoard[i][jAttack] = i + 2;
			}
		}

		for (int j = 0; j < jAttack; j++) {
			if (probabilityBoard[iAttack][j] != -999) {
				probabilityBoard[iAttack][j] = j + 2;
			}
		}

		for (int j = 9; j > jAttack; j--) {
			if (probabilityBoard[iAttack][j] != -999) {
				probabilityBoard[iAttack][j] = j + 2;
			}
		}
	} //still working on !target
	else if (!target) // STILL WORKING!!!
	{
		probabilityBoard[iAttack][jAttack] = -999;
		for (int i = iAttack; i >0; i--) { //如果我miss了这部分，周围的都要从中心横竖扩散出去约减越小，走的越远减的越少
			if (probabilityBoard[i][jAttack] != -999) {
				probabilityBoard[i - 1][jAttack] = probabilityBoard[i - 1][jAttack] - (iAttack - i); //i-1是在最开始的时候就是[i][j]的上面一格
			}
		}

	}
}


