#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

// TicTacToe
// welcome the player to the game
// press P to start the game
// press T to exit the game
// if space is pressed, wipe screen and create grid
// in grid show letters needing to be pressed to enter X or O
// player is X
// computer is O
// computer waits for player input before playing
// if X or O already in position, error message and try again
// if 3 X in a line, player wins
// if 3 O in a line, computer wins
// if grid is full and X or O is not equal to 3, game is draw
// Record results at top of screen
// Press R to replay the game
// Press Escape to close game
char grid[3][3] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' };
bool QUIT;
bool KEEP_GOING;

void playerInput()
{
	char letter;
	cout << " \n \t \t Please choose your move: ";
	cin >> letter;

	if (letter == 'a')
	{
		grid[0][0] = 'X';
	}
	if (letter == 'b')
	{
		grid[0][1] = 'X';
	}
	if (letter == 'c')
	{
		grid[0][2] = 'X';
	}
	if (letter == 'd')
	{
		grid[1][0] = 'X';
	}
	if (letter == 'e')
	{
		grid[1][1] = 'X';
	}
	if (letter == 'f')
	{
		grid[1][2] = 'X';
	}
	if (letter == 'g')
	{
		grid[2][0] = 'X';
	}
	if (letter == 'h')
	{
		grid[2][1] = 'X';
	}
	if (letter == 'i')
	{
		grid[2][2] = 'X';
	}
}

void computerPlays()
{

}


void ticTacToe()
{
	cout << "\n \n How did I get here so quick? \n \n" << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << "\t";
		for (int j = 0; j < 3; j++)
		{
			cout << " " << grid[i][j] << " |";
		}
		cout << "\n         ___________" << endl;
	}



}

void startScreen()
{
	char decision;
	bool gameIsRunning = true;

	cout << "\t Welcome to Tic Tac Toe! \t \n" << endl;
	cout << "\t If you would like to Play, press P \n" << endl;
	cout << "\t If you would like to Leave, press T \n" << endl;
	cout << "\t Don't forget to press enter too! ";
	cin >> decision;

	if (decision == 'p')
	{
		KEEP_GOING = true;
		return;
	}
	else if (decision == 't')
	{
		QUIT = true;
		return;
	}
	else if (decision != 'p' || decision != 't')
	{
		cout << "\n \t Uhhhh that wasn't a choice??? Come onnnnn P or T";
		cout << "\n \t Now, press anything to try again";
		_getch();
		system("cls");
		startScreen();
	}

	return;
}

void winScreen()
{
	char playAgain;
	cout << "\t Congrats, you won! \n" << endl;
	cout << "\t If you would like to play again, press R \n" << endl;
	cout << "\t If you would to exit, press T \n" << endl;
	cout << "\t >>>>>>";
	cin >> playAgain;

	if (playAgain == 'r')
	{
		KEEP_GOING = true;
	}
	else if (playAgain == 't')
	{
		QUIT = true;
		return;
	}
}

void loseScreen()
{
	char playAgain;
	cout << "\t Oof, you lost. Tough Break.\n" << endl;
	cout << "\t If you would like to play again, press R \n" << endl;
	cout << "\t If you would to exit, press T \n" << endl;
	cout << "\t >>>>>>";
	cin >> playAgain;

	if (playAgain == 'r')
	{
		KEEP_GOING = true;
	}
	else if (playAgain == 't')
	{
		QUIT = true;
		return;
	}
}


int main()
{
	
	while (QUIT != true)
	{
		startScreen();
		if (QUIT == true)
		{
			break;
		}
		while (KEEP_GOING == true)
		{
			ticTacToe();
			playerInput();
			if (QUIT == true)
			{
				break;
			}
		}
	}

	system("cls");
	cout << "\n\n\t Leaving me I see. Fine. I don't want you here anyway \n" << endl;
	cout << "\t\t BAAAAAAAAAAAAKA \n\n\n";
		
	return(0);
}