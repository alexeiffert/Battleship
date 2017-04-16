#include "Ai.h"

Ai::Ai(std::string difficulty) : targetStack(4)
{
	this->difficulty = difficulty;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			probabilityBoard[i][j] = 0;
		}
	}
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

	if (targetStack.getSize()) {
		attack[0] = targetStack.pop()[0];
		attack[1] = targetStack.pop()[1];

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

//Note: Each time this function is run, the probability board is reset and recalculated
int* Ai::hardAttack(int board[10][10]) {
	
	//Resets the probability matrix
	for (int i = 0; i < 10; i++) {
		for (int j = 0; i < 10; j++) {
			probabilityBoard[i][j] = 0;
		}
	}

	//Calculates the probabilities for all remaining ships
	calculateProbabilities(board, 5);
	calculateProbabilities(board, 4);
	calculateProbabilities(board, 3);
	calculateProbabilities(board, 3);
	calculateProbabilities(board, 2);
	
	//Returns the coordinates of the square with the highest probability
	double max = 0;
	int attack[2];

	for (int i = 0; i < 10; i++) {
		for (int j = 0; i < 10; j++) {
			if (probabilityBoard[i][j] < max) {
				max = probabilityBoard[i][j];
				attack[0] = i;
				attack[1] = j;
			}
		}
	}
	return attack;
}


//----------------------------------------------------------------------------//



void Ai::calculateProbabilities(int board[10][10], int shipSize) {
	
	int emptyCount = 100;	//ie the maximum empty squares on the board
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board[i][j]) {	//This counts the squares that were fired upon and changes their probability to 0 and also decreases the square count
				probabilityBoard[i][j] = 0;
				emptyCount--;
			}
		}
	}
//	std::cout << emptyCount << std::endl;

	double probability = 17 / double(emptyCount);	//ie ship squares left/number of squares total

	//Counts probabilities horizontally
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j <= 10 - shipSize; j++) {
			int count = 0;
			for (int k = 0; k < shipSize; k++){
				if (!board[i][j + k]) {		//Counts number of adjacent empty squares from an empty square
					count++;
				}
			}
			if (count >= shipSize) {
				for (int k = 0; k < count; k++) {
					probabilityBoard[i][j + k] += probability;
				}
			}
		}
	}

	//Counts probabilities vertically
	for (int i = 0; i <= 10 - shipSize; i++) {
		for (int j = 0; j < 10; j++) {
			int count = 0;
			for (int k = 0; k < shipSize; k++) {
				if (!board[i + k][j]) {		//Counts number of adjacent empty squares from an empty square
					count++;
				}
			}
			if (count >= shipSize) {
				for (int k = 0; k < count; k++) {
					probabilityBoard[i + k][j] += probability;
				}
			}
		}
	}
}

//void Ai::fitAircraftcarrier(int board[10][10])
//{
//	int count = 0;
//	for (int i = 0; i < 10; i++) {		//read all the possible space for Carrier first(still working)
//		for (int j = 0; j < 10; j++) {
//			if (i < 10 && j < 6) {
//				if (board[i][j] == board[i][j + 4]) {
//					count++; }
//			}
//
//			if (i < 6 && j < 10) {
//				if (board[i][j] == board[i + 4][j]) {
//					count++; }
//			}
//		}
//	}
//}
//
//void Ai::fitBattleship(int board[10][10])
//{
//	int count = 0;
//	for (int i = 0; i < 10; i++) {			//read all the possible space for Battleship first(still working)
//		for (int j = 0; j < 10; j++) {
//			if (i < 10 && j < 7) {
//				if (board[i][j] == board[i][j + 3]) {
//					count++; }
//			}
//
//			if (i < 7 && j < 10) {
//				if (board[i][j] == board[i + 3][j]) {
//					count++; }
//			}
//		}
//	}
//}
//
//void Ai::fitSubmarine(int board[10][10])
//{
//	int count = 0;
//	for (int i = 0; i < 10; i++) {
//		for (int j = 0; j < 10; j++) {
//			if (i < 10 && j < 8) {
//				if (board[i][j] == board[i][j + 2]) { 
//					count++; }
//			}
//
//			if (i < 8 && j < 10) {
//				if (board[i][j] == board[i + 2][j]) { 
//					count++; }
//			}
//		}
//	}
//}
//
//void Ai::fitCruiser(int board[10][10])
//{
//	int count = 0;
//	for (int i = 0; i < 10; i++) {
//		for (int j = 0; j < 10; j++) {
//			if (i < 10 && j < 8) {
//				if (board[i][j] == board[i][j + 2]) {
//					count++; }
//			}
//
//			if (i < 8 && j < 10) {
//				if (board[i][j] == board[i + 2][j]) {
//					count++; }
//			}
//		}
//	}
//}
//
//void Ai::fitDestroyer(int board[10][10])
//{
//	int count = 0;
//	for (int i = 0; i < 10; i++) {
//		for (int j = 0; j < 10; j++) {
//			if (i < 10 && j < 9) {
//				if (board[i][j] == board[i][j + 1]) {
//					count++; }
//			}
//
//			if (i < 9 && j < 10) {
//				if (board[i][j] == board[i + 1][j]) {
//					count++; }
//			}
//		}
//	}
//}
//
//void probabilityCalculate(int board[10][10], int a, int b) {
//	int iAttack = a, jAttack = b;
//
//	if (target) {
//		probabilityBoard[iAttack][jAttack] = -999; //set this square's probability to -999 because this square cannot be hit anymore
//												   //When a hit on the target, we can set all the probaility is 1 except those squares has been hit but not on the target
//		for (int i = 0; i < 10; i++) {
//			for (int j = 0; j < 10; j++) {
//				if (probabilityBoard[i][j] != -999) {
//					probabilityBoard[i][j] = 1;
//				}
//			}
//		}
//
//		for (int i = 0; i < iAttack; i++) {	   //then here, we will change the probability around the target square, once distance is closer to target, the probability is larger
//			if (probabilityBoard[i][jAttack] != -999) {
//				probabilityBoard[i][jAttack] = i + 2; //the reason to add 2 is that will always bigger than 1 which is other unrelated square's probability
//			}
//		}
//
//		for (int i = 9; i > iAttack; i--) {
//			if (probabilityBoard[i][jAttack] != -999) {
//				probabilityBoard[i][jAttack] = i + 2;
//			}
//		}
//
//		for (int j = 0; j < jAttack; j++) {
//			if (probabilityBoard[iAttack][j] != -999) {
//				probabilityBoard[iAttack][j] = j + 2;
//			}
//		}
//
//		for (int j = 9; j > jAttack; j--) {
//			if (probabilityBoard[iAttack][j] != -999) {
//				probabilityBoard[iAttack][j] = j + 2;
//			}
//		}
//	} //still working on !target
//	else if (!target) // STILL WORKING!!!
//	{
//		probabilityBoard[iAttack][jAttack] = -999;
//		for (int i = iAttack; i >0; i--) { //�����miss���ⲿ�֣���Χ�Ķ�Ҫ�����ĺ����ɢ��ȥԼ��ԽС���ߵ�ԽԶ���Խ��
//			if (probabilityBoard[i][jAttack] != -999) {
//				probabilityBoard[i - 1][jAttack] = probabilityBoard[i - 1][jAttack] - (iAttack - i); //i-1�����ʼ��ʱ�����[i][j]������һ��
//			}
//		}
//
//	}
//}
//
//
