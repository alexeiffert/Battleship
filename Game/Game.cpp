#include "Game.h"

const int player = 1;
const int opponent = 2;

int fire(std::string playerName, Board &opponentBoard) {
	std::cout << "Commander " << playerName << ", standing by to fire" << std::endl
		<< "command format is [A-F][01-10]:" << std::endl;
	std::string target;
	std::cin >> target;
	int result = opponentBoard.markShot(target);
	printBoard(opponentBoard, opponent);

	return result;
}

std::string checkWinner(int shipsDestroyed, int maxShips, std::string playerName) {
	std::string winner = " ";
	if (maxShips <= shipsDestroyed) {
		winner = playerName;
	}
	else winner = "Enemy";
		
	return winner;
}

bool gameOver(int shipsDestroyed, int maxShips)
{
	if (maxShips <= shipsDestroyed) {
		return true;
	}
	else return false;
}


int main() {
	Board playerBoard;
	Board opponentBoard;
	Ai enemy;
	int shipsDestroyed;
	int maxShips;


	std::cout << "   ___  ___ ______________   __________ _________ " << std::endl;
	std::cout << "  / _ )/ _ /_  __/_  __/ /  / __/ __/ // /  _/ _ \\" << std::endl;
	std::cout << " / _  / __ |/ /   / / / /__/ _/_\\ \\/ _  // // ___/" << std::endl;
	std::cout << "/____/_/ |_/_/   /_/ /____/___/___/_//_/___/_/    " << std::endl;

	
	std::cout << "Welcome to BATTLESHIP!" << std::endl
		<< "Please enter your name" << std::endl
		<< "Name: " << std::endl;

	std::string playerName;
	std::cin >> playerName; 

	std::cout << "Okay " << playerName << " the enemies fleet is quickly approaching." << std::endl;
	std::cout << "Get ready to place your ships." << std::endl;
	std::cout << "You are at the command of 5 ships:" << std::endl;
	std::cout << "Destroyer - Size 2" << std::endl;
	std::cout << "Submarine - Size 3" << std::endl;
	std::cout << "Cruiser - Size 3" << std::endl;
	std::cout << "Carrier - Size 4" << std::endl;
	std::cout << "Battleship - Size 5" << std::endl;

	std::cout << "Displaying the battlefield..." << std::endl;
	std::cin.ignore();
	std::cin.get();

	std::cout << "----" << "PLAYER BOARD" << "----" << std::endl;
	printBoard(playerBoard, player);


	std::cout << "----" << "ENEMY BOARD" << "----" << std::endl;
	displayBoard(opponentBoard, opponent);

	int battle = 1;
	while (battle == 1 && !gameOver) {
		int move = 1;
		while (move == 1) {
			move = fire(playerName, opponentBoard);
		};
		enemy.fireShot(playerBoard);
		std::cout << "----" << "You've Been Hit" << "----" << std::endl;
		std::cout << "----" << "Player Board" << "----" << std::endl;
		printBoard(playerBoard, player);
	};

	if (checkWinner(shipsDestroyed, maxShips, playerName)==playerName) {
		std::cout << "Congratulations, you defeated the enemy!" << std::endl;
	}
	else std::cout << "You've been defeated!" << std::endl;
	return 0;
}