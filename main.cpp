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


void playerInput()
{

}

void computerPlays()
{

}


void ticTacToe()
{
	cout << "How did I get here os quick?" << endl;
}

void startScreen(char play)
{

	int yes = 1;
	int no = 2;
	int decision;

	cout << "\t Welcome to Tic Tac Toe! \t \n" << endl;
	cout << "\t If you would like to Play, press P \n" << endl;
	cout << "\t If you would like to Leave, press T \n" << endl;
	cin >> play;

	if (play == 'P')
	{
		play = yes;
		yes = decision;
	}
	else if (play == 'T')
	{
		play == no;
		no = decision;
	}

	return(decision);
}

void winScreen()
{
	char playAgain;
	cout << "/t Congrats, you won! /n" << endl;
	cout << "/t If you would like to play again, press R /n" << endl;
	cout << "/t If you would to exit, press T /n" << endl;
	cin >> playAgain;

	if (playAgain == 'R')
	{
		ticTacToe();
	}
	else if (playAgain == 'T')
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

	if (playAgain == 'R')
	{
		ticTacToe();
	}
	else if (playAgain == 'T')
	{
		return;
	}
}


int main()
{
	int doesPlayerPlay;

	startScreen(doesPlayerPlay);
	
		
	return(0);
}