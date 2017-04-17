#include <iostream>
#include <string>
//#include "Game.h"
#ifndef BOARD_H
#define BOARD_H
#include "Board.cpp"
#endif

//#include "Ai.cpp"
#ifndef SHIP_H
#define SHIP_H
#include "Ship.cpp"
#endif // SHIP_H

#include <string>
#include <windows.h>

const int player = 1;
const int opponent = 2;


void type_text(const std::string& text)
{
	// loop through each character in the text
	for (std::size_t i = 0; i < text.size(); ++i)
	{
		// output one character
		// flush to make sure the output is not delayed
		std::cout << text[i] << std::flush;

		Sleep(40); // use Sleep on windows
	}
}

/*nt fire(std::string playerName, Board &opponentBoard)
{
	std::cout << "Commander " << playerName << ", standing by to fire" << std::endl
		<< "command format is [A-F][01-10]:" << std::endl;
	std::string target;
	std::cin >> target;
	int result = opponentBoard.markShot(target);
	printBoard(opponentBoard, opponent);

	return result;
}

std::string checkWinner(int shipsDestroyed, int maxShips, std::string playerName)
{
	std::string winner = " ";
	if (maxShips <= shipsDestroyed)
    {
		winner = playerName;
	}
	else
	{
        winner = "Enemy";
	}
	return winner;
}*/

bool gameOver(Board* playerBoard, Board* aiBoard)
{
    int pShips = 0;
    int aShips = 0;
    for(int i = 0; i < 5; i++)
    {
        if(playerBoard->checkShip(i))
        {
            pShips++;
        }
        if(aiBoard->checkShip(i))
        {
            aShips++;
        }
    }
    if (aShips >= 5)
    {
        type_text("Congratulations! You win!");
        exit(0);
		return false;
	}
	if (pShips >= 5)
    {
        type_text("You've been defeated!");
        exit(0);
		return false;
	}
	else
    {
        return true;
    }
}

void placeShips(Board* board)
{
    std::string temp[5] = {"Destroyer", "Submarine", "Cruiser", "Carrier", "Battleship"};
    int sizes[5] = {2,3,3,4,5};
    int x;
    int y;
    int dir;
    for(int i = 0; i < 5; i++)
    {
        type_text("Deploying "+temp[i]+"\n");
        type_text("Enter X Coordinate: ");
        while(1)
        {
            cin >> x;
            if(x>10||x<1)
            {
                type_text("Deploy the ship within the BattleField (1-10): ");
            }
            else
            {
                break;
            }
        }
        type_text("Enter Y Coordinate: ");
        while(1)
        {
            cin >> y;
            if(y>10||y<1)
            {
                type_text("Deploy the ship within the BattleField (1-10): ");
            }
            else
            {
                break;
            }
        }
        type_text("Enter the direction the ship will face (0 = North, 1 = East, 2 = South, 3 = West): ");
        while(1)
        {
            cin >> dir;
            if(dir<0||dir>3)
            {
                type_text("This is not a valid direction! We're running out of time (0 = North, 1 = East, 2 = South, 3 = West): ");
            }
            else
            {
                break;
            }
        }
        if(!board->placeShip(x-1,y-1,dir,sizes[i]))
        {
            type_text("There's no room to deploy the ship there! Try again!\n");
            i--;
        }
    }

}

int main()
{
	Board* playerBoard = new Board();
	Board* opponentBoard = new Board();
	//Ai enemy;


	std::cout << "   ___  ___ ______________   __________ _________ " << std::endl;
	std::cout << "  / _ )/ _ /_  __/_  __/ /  / __/ __/ // /  _/ _ \\" << std::endl;
	std::cout << " / _  / __ |/ /   / / / /__/ _/_\\ \\/ _  // // ___/" << std::endl;
	std::cout << "/____/_/ |_/_/   /_/ /____/___/___/_//_/___/_/    " << std::endl;


	type_text("Welcome to BATTLESHIP!\nPlease enter your name\nName: ");

	std::string playerName;
	std::cin >> playerName;


	type_text("Okay " + playerName + " the enemies fleet is quickly approaching.\n");
	type_text("Get ready to place your ships.\n");
	type_text("You are at the command of 5 ships:\n");
	type_text("Destroyer - Size 2\n");
	type_text("Submarine - Size 3\n");
	type_text("Cruiser - Size 3\n");
	type_text("Carrier - Size 4\n");
	type_text("Battleship - Size 5\n");

    placeShips(playerBoard);

    //PLACE AI SHIPS

	type_text("Displaying the battlefield...\n");

	playerBoard->printBoard();

	int xval;
    int yval;
	while (!gameOver(playerBoard, opponentBoard))
    {
		type_text("Prepare to fire!\nInput the x-value of the attack (1-10): ");
		std::cin>>xval;
		type_text("Input the y-value of the attack (1-10): ");
		std::cin>>yval;
		std::cout << "Firing at coordinates " << xval << ", " << yval << "." << std::endl;
		playerBoard->fire(xval-1, yval-1, opponentBoard);
		type_text("Enemy fire detected!\n");
		//AI ATTACK STUFF
		std::cout << "----" << "PLAYER BOARD" << "----" << std::endl;
		playerBoard->printBoard();
	};
	return 0;
}
