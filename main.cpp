#include <iostream>
#include <string>
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

void playerInput()
{
	char letter;
	cout << " \t \t Please choose your move: " << endl;
	cin >> letter;

	if (letter == 'A')
	{
		grid[0][0];
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
	cin >> decision;

	if (decision == 'p')
	{
		ticTacToe();
	}
	else if (decision == 't')
	{
		gameIsRunning = false;
		return;
	}

	return;
}

void winScreen()
{
	char playAgain;
	cout << "\t Congrats, you won! \n" << endl;
	cout << "\t If you would like to play again, press R \n" << endl;
	cout << "\t If you would to exit, press T \n" << endl;
	cin >> playAgain;

	if (playAgain == 'r')
	{
		ticTacToe();
	}
	else if (playAgain == 't')
	{
		return;
	}
}

void loseScreen()
{
	char playAgain;
	cout << "/t Oof, you lost. Tough Break./n" << endl;
	cout << "/t If you would like to play again, press R /n" << endl;
	cout << "/t If you would to exit, press T /n" << endl;
	cin >> playAgain;

	if (playAgain == 'r')
	{
		ticTacToe();
	}
	else if (playAgain == 't')
	{
		return;
	}
}


int main()
{
	int doesPlayerPlay;

	startScreen();
	
		
	return(0);
}