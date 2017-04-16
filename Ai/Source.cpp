//This is just a driver main to test Ai functions

#include "Ai.h"
#include <iostream>
#include <time.h>
#include <iomanip>

int main() {

	int board[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			board[i][j] = 0;
		}
	}

	board[4][0] = 1;
	board[4][1] = 1;
	board[4][2] = 1;
	board[4][3] = 1;
	board[4][4] = 1;
	board[0][4] = 1;
	board[1][4] = 1;
	board[2][4] = 1;
	board[3][4] = 1;

	board[4][5] = 1;
	board[4][6] = 1;
	board[4][7] = 1;
	board[4][8] = 1;
	board[4][9] = 1;

	
	Ai A("hard");

	A.enumerateTallies(board, 5);
	A.enumerateTallies(board, 4);
	A.enumerateTallies(board, 3);
	A.enumerateTallies(board, 3);
	A.enumerateTallies(board, 2);

	//Recalculates tallies as probability values
	double total = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			total += A.probabilityBoard[i][j];
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			A.probabilityBoard[i][j] = A.probabilityBoard[i][j]/total;
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			std::cout << std::setw(15) << A.probabilityBoard[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
	return 0;

	//	int c;
	//
	//	std::cout << c << std::endl;
	//
	//	for (int i = 0; i < 10; i++) {
	//		for (int j = 0; j < 10; j++) {
	//			board[i][j] = c++;
	//		}
	//	}
	//
	//
	//	Ai Ai("easy");
	//	Ai.arrangeShip();
	//
	//	srand(time(NULL));
	//	int randomx = rand();
	//	int randomy = rand();
	//	c = 0;
	//
	//	for (int i = 0; i < 10; i++) {
	//		for (int j = 0; j < 10; j++) {
	//			if (!board[(i + randomx) % 10][(j + randomy) % 10]) {
	//				
	//				std::cout << c << " ";
	//				std::cout << board[(i + randomx) % 10][(j + randomy) % 10] << std::endl;
	//			}
	//		}
	//	}

//		int* attack = Ai.easyAttack(board);
//		std::cout << attack;
//
//	for (int i = 0; i < 10; i++) {
//		for (int j = 0; j < 10; j++) {
//			std::cout << board[i][j] << "  ";
//		}
//		std::cout << std::endl;
//	}
}