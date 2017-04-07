#include "Ai.h"
#include <iostream>
#include <time.h>

int main() {

	int board[10][10];

	int c = 0;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			board[i][j] = c++;
		}
	}


	Ai Ai("easy");
	Ai.arrangeShip();

	srand(time(NULL));
	int randomx = rand();
	int randomy = rand();

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
//			std::cout << board[(i + randomx) % 10][(j + randomy) % 10] << " ";
			std::cout << board[(i + randomx) % 10][(j + randomy) % 10];
			if (!board[(i + randomx) % 10][(j + randomy) % 10]) {
				std::cout << board[(i + randomx) % 10][(j + randomy) % 10] << std::endl;
			}
		}
	}

//	int* attack = Ai.easyAttack(board);
//	std::cout << attack;

	/*
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			std::cout << board[i][j] << "  ";
		}
		std::cout << std::endl;
	}
	*/
}