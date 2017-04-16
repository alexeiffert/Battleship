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

	
	Ai A("easy");
	std::cout << A.attack(board)[0] << ", " << A.attack(board)[1];



	
	return 0;
}