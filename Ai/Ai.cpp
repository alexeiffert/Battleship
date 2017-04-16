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

void Ai::printRadar() {

	//Calculates the average probability on the probability board
	double avProbability = 0;
	int count = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (probabilityBoard[i][j]) {
				avProbability += probabilityBoard[i][j];
				count++;
			}
		}
	}

	avProbability = avProbability / double(count);
	std::cout << avProbability;

	//For formatting purposes
	for (int i = 0; i < 5; i++)
		std::cout << std::endl;

	//Outputs numbers for X axis
	std::cout << "           ";
	for (int i = 0; i < 10; i++)
		std::cout << std::setw(5) << i;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	//Outputs letters for Y axis
	for (int i = 0; i < 10; i++) {
		std::cout << "     " << char('A' + i) << "     ";

		//Outputs appropriate visual character for that square's probability compared with the average for the board
		for (int j = 0; j < 10; j++) {
			if (probabilityBoard[i][j] < avProbability / 2)
				std::cout << std::setw(4) << char(32) << char(248);
			else if (probabilityBoard[i][j] > avProbability / 2 && probabilityBoard[i][j] < avProbability)
				std::cout << std::setw(4) << char(176) << char(176);
			else if (probabilityBoard[i][j] > avProbability && probabilityBoard[i][j] < avProbability * 3 / 2)
				std::cout << std::setw(4) << char(177) << char(177);
			else if (probabilityBoard[i][j] > avProbability * 3 / 2)
				std::cout << std::setw(4) << char(178) << char(178);
			else
				std::cout << std::setw(4) << char(219) << char(219);
		}

		std::cout << std::endl;

		std::cout << std::endl;
	}
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

//Selects the correct attack for the difficulty level
int* Ai::attack(int board[10][10]) {
	if (difficulty == "easy") {
		return easyAttack(board);
	}
	if (difficulty == "normal") {
		return normalAttack(board);
	}
	if (difficulty == "insane") {
		return insaneAttack(board);
	}
	std::cout << "Error! You have chosen an invalid difficulty.";

	return nullptr;
}

int* Ai::easyAttack(int board[10][10]) {

	int attack[2];

	//Generates two pseudo-random numbers for each coordinate
	srand(time(NULL)*time(NULL));
	int randX = rand();
	srand(time(NULL)*time(NULL));
	int randY = rand();

	//Generates and returns 2 random empty coordinates
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (!board[(i + randX) % 10][(j + randY) % 10]) {
				attack[0] = (i + rand()) % 10;
				attack[1] = (j + rand()) % 10;
				return attack;
			}
		}
			
	}

	std::cout << "Unknown error. Please terminate program.";
	return nullptr;
};

int* Ai::normalAttack(int board[10][10]) {

	int* getAddress;
	int attack[2];

	//If target in stack, return coordinates and override search code
	if (targetStack.getTop()) {
		getAddress = targetStack.pop();
		attack[0] = getAddress[0];
		attack[1] = getAddress[1];
		return attack;
	}
	//Else, return easy attack
	else {
		return easyAttack(board);
	}

	std::cout << "Unknown Error.";
	return nullptr;
}

//Note: Each time this function is run, the probability board is reset and recalculated
int* Ai::insaneAttack(int board[10][10]) {

	//If target in stack, choose first. Else, continue with probability calculations
	int* getAddress;
	int attack[2];

	if (targetStack.getTop()) {
		getAddress = targetStack.pop();
		attack[0] = getAddress[0];
		attack[1] = getAddress[1];
		return attack;
	}

	//Resets the probability matrix for each calculation
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			probabilityBoard[i][j] = 0;
		}
	}

		//Calculates the tallies for all remaining ships
	if (true/*carrier*/){
		enumerateTallies(board, 5);
	}
	if (true/*battleship*/) {
		enumerateTallies(board, 4);
	}
	if (true/*cruiser*/) {
		enumerateTallies(board, 3);
	}
	if (true/*submarine*/) {
		enumerateTallies(board, 3);
	}
	if (true/*destroyer*/) {
		enumerateTallies(board, 2);
	}

	//Factors in parity for even squares, ie sets "probability" to 0	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if ((i + j) % 2 == 0) {
				probabilityBoard[i][j] = 0;
			}
		}
	}

	//From the remaining even squares, calculates probabilities based on tallies
	double total = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			total += probabilityBoard[i][j];
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			probabilityBoard[i][j] = probabilityBoard[i][j] / total;
		}
	}
	
	//Searches for and returns the coordinates of the square with the highest probability
	double max = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (probabilityBoard[i][j] > max) {
				max = probabilityBoard[i][j];
				attack[0] = i;
				attack[1] = j;
			}
		}
	}

	return attack;
}

//This function is utilized in hardAttack to enumerate the possibilities a ship is in a certain location
void Ai::enumerateTallies(int board[10][10], int shipSize) {
	
	int emptyCount = 100;	//ie the maximum empty squares on the board
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board[i][j]) {	//This counts the squares that were fired upon, changes their probability to 0, and also decreases the square count
				probabilityBoard[i][j] = 0;
				emptyCount--;
			}
		}
	}

	//Counts tallies horizontally
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
					probabilityBoard[i][j + k]++;
				}
			}
		}
	}

	//Counts tallies vertically
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
					probabilityBoard[i + k][j]++;
				}
			}
		}
	}
}
