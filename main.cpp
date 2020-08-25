#include <iostream>
#include <string>
#include <conio.h>
using namespace std;


char grid[3][3] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' };
bool QUIT;
bool KEEP_GOING;
bool VS_HUMAN;
bool VS_COMP;
bool GAME_RESET;
char sign = 'X';
int gamesPlayed = 0;


// draw the tictactoe grid
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

	return;

}

// tell player the move is invalid and give them another try
void invalidMove()
{
	cout << "\n \n \t Hey! Don't be trying to play over each other. Naughty. Try again.";
	cout << "\n \t Now. I'm watching you. Press any key to try again.";
	_getch();
	system("cls");
	ticTacToe();

}

// get playerinput
// check to see if valid position
// if no, send to invalidMove and try again
// if yes, allow player to move
// if multiPlayer, player goes again
// if computer, wait before player goes again
// check to see if player wins
void playerInput()
{
	char letter;
	cout << " \n \t Please choose your move: ";
	cin >> letter;

	switch (letter)
	{
	case 'a':
		if (grid[0][0] != 'X' && grid[0][0] != 'O')
		{
			grid[0][0] = sign;
		}
		else
		{
			invalidMove();
		}
			break;
	case 'b':
		if (grid[0][1] != 'X' && grid[0][1] != 'O')
		{
			grid[0][1] = sign;
		}
		else
		{
			invalidMove();
		}
			break;
	case 'c':
		if (grid[0][2] != 'X' && grid[0][2] != 'O')
		{
			grid[0][2] = sign;
		}
		else
		{
			invalidMove();
		}
		break;
	case 'd':
		if (grid[1][0] != 'X' && grid[1][0] != 'O')
		{
			grid[1][0] = sign;
		}
		else
		{
			invalidMove();
		}
		break;
	case 'e':
		if (grid[1][1] != 'X' && grid[1][1] != 'O')
		{
			grid[1][1] = sign;
		}
		else
		{
			invalidMove();
		}
		break;
	case 'f':
		if (grid[1][2] != 'X' && grid[1][2] != 'O')
		{
			grid[1][2] = sign;
		}
		else
		{
			invalidMove();
		}
		break;
	case 'g':
		if (grid[2][0] != 'X' && grid[2][0] != 'O')
		{
			grid[2][0] = sign;
		}
		else
		{
			invalidMove();
		}
		break;
	case 'h':
		if (grid[2][1] != 'X' && grid[2][1] != 'O')
		{
			grid[2][1] = sign;
		}
		else
		{
			invalidMove();
		}
		break;
	case 'i':
		if (grid[2][2] != 'X' && grid[2][2] != 'O')
		{
			grid[2][2] = sign;
		}
		else
		{
			invalidMove();
		}
		break;
	default:
		cout << "Seriously how do you always end up here? Leave. \n";
			break;
	}

	if (letter == 't')
	{
		QUIT = true;
		return;
	}
	system("cls");
	//if ()
}

// switch the signs if VS Human
void multiPlayer()
{
	if (sign == 'X')
	{
		sign = 'O';
	}
	else
	{
		sign = 'X';
	}
}

// Computer plays second
// find position to play
// check if position is avaliable
// if position is not, find another 
// if position is, check if best possible move
// if yes, play
// if no, find another spot
// when finished, hand back to player
void computerPlays()
{

}

// welcome the player to the game
// give choice of playing with human or computer
// if human, run multiPlayer
// if computer, run computerPlays
// if t is pressed, terminate the game
void startScreen()
{
	char decision;
	bool gameIsRunning = true;

	cout << "\t Games Played: " << gamesPlayed << endl;
	cout << "\n \n \t \t Welcome to Tic Tac Toe! \t \n \n \n" << endl;
	cout << "\t If you would like to Play against another Person, press P \n" << endl;
	cout << "\t If you would like to Play against a computer, press C \n" << endl;
	cout << "\t If you would like to Leave, press T \n" << endl;
	cout << "\t Don't forget to press enter too! >> ";
	cin >> decision;
	gamesPlayed += 1;

	if (decision == 'p')
	{
		system("cls");
		KEEP_GOING = true;
		VS_HUMAN = true;
		return;
	}
	else if (decision == 'c')
	{
		system("cls");
		KEEP_GOING = true;
		VS_COMP = true;
		return;
	}
	else if (decision == 't')
	{
		QUIT = true;
		return;
	}
	else if (decision != 'p' && decision != 't' && decision != 'c')
	{
		cout << "\n \t Uhhhh that wasn't a choice??? Come onnnnn P or T";
		cout << "\n \t Now, press anything to try again";
		_getch();
		system("cls");
		startScreen();
	}

	return;
}


// player has won
// add sign of winning player
// ask player if they want to play again
// if yes, repeat the same game
// if no, return to startScreen
void winScreen()
{
	char playAgain;
	cout << "\n \n \n \t Congrats, you won player " << sign << " \n" << endl;
	cout << "\t If you would like to play again, press R to go back to the StartScreen\n" << endl;
	cout << "\t If you would to exit, press T to terminate the game\n" << endl;
	cout << "\t >>>>>>";
	cin >> playAgain;

	if (playAgain == 'r')
	{
		system("cls");
		KEEP_GOING = true;
		GAME_RESET = true;
		startScreen();
	}
	else if (playAgain == 't')
	{
		system("cls");
		QUIT = true;
	}
}

// player has lost against computer
// ask player if they want to play again
// if yes, repeat the same game
// if no, return to startScreen
void loseScreen()
{
	char playAgain;
	cout << "\n \n \n \t Oof, you lost. Tough Break.\n" << endl;
	cout << "\t If you would like to play again, press R to go back to the Start Screen \n" << endl;
	cout << "\t If you would to exit, press T to terminate the game\n" << endl;
	cout << "\t >>>>>>";
	cin >> playAgain;

	if (playAgain == 'r')
	{
		system("cls");
		KEEP_GOING = true;
		GAME_RESET = true;
		startScreen();
	}
	else if (playAgain == 't')
	{
		system("cls");
		QUIT = true;
	}
}

void resetTheGame()
{
	grid[0][0] = 'A';
	grid[0][1] = 'B';
	grid[0][2] = 'C';
	grid[1][0] = 'D';
	grid[1][1] = 'E';
	grid[1][2] = 'F';
	grid[2][0] = 'G';
	grid[2][1] = 'H';
	grid[2][2] = 'I';
}

// check to see if player has won
void hasPlayerWon()
{
	if (grid[0][0] == 'X' && grid[0][1] == 'X' && grid[0][2] == 'X')
	{
		winScreen();
	}
	else if (grid[1][0] == 'X' && grid[1][1] == 'X' && grid[1][2] == 'X')
	{
		winScreen();
	}
	else if (grid[2][0] == 'X' && grid[2][1] == 'X' && grid[2][2] == 'X')
	{
		winScreen();
	}
	else if (grid[0][0] == 'X' && grid[1][0] == 'X' && grid[2][0] == 'X')
	{
		winScreen();
	}
	else if (grid[0][1] == 'X' && grid[1][1] == 'X' && grid[2][1] == 'X')
	{
		winScreen();
	}
	else if (grid[0][2] == 'X' && grid[1][2] == 'X' && grid[2][2] == 'X')
	{
		winScreen();
	}
	else if (grid[0][0] == 'X' && grid[1][1] == 'X' && grid[2][2] == 'X')
	{
		winScreen();
	}
	else if (grid[2][0] == 'X' && grid[1][1] == 'X' && grid[0][2] == 'X')
	{
		winScreen();
	}

}

void hasPlayerLost()
{
	if (grid[0][0] == 'O' && grid[0][1] == 'O' && grid[0][2] == 'O')
	{
		if (VS_HUMAN == true)
		{
			winScreen();
		}
		loseScreen();
	}
	else if (grid[1][0] == 'O' && grid[1][1] == 'O' && grid[1][2] == 'O')
	{
		if (VS_HUMAN == true)
		{
			winScreen();
		}
		loseScreen();
	}
	else if (grid[2][0] == 'O' && grid[2][1] == 'O' && grid[2][2] == 'O')
	{
		if (VS_HUMAN == true)
		{
			winScreen();
		}
		loseScreen();
	}
	else if (grid[0][0] == 'O' && grid[1][0] == 'O' && grid[2][0] == 'O')
	{
		if (VS_HUMAN == true)
		{
			winScreen();
		}
		loseScreen();
	}
	else if (grid[0][1] == 'O' && grid[1][1] == 'O' && grid[2][1] == 'O')
	{
		if (VS_HUMAN == true)
		{
			winScreen();
		}
		loseScreen();
	}
	else if (grid[0][2] == 'O' && grid[1][2] == 'O' && grid[2][2] == 'O')
	{
		if (VS_HUMAN == true)
		{
			winScreen();
		}
		loseScreen();
	}
	else if (grid[0][0] == 'O' && grid[1][1] == 'O' && grid[2][2] == 'O')
	{
		if (VS_HUMAN == true)
		{
			winScreen();
		}
		loseScreen();
	}
	else if (grid[2][0] == 'O' && grid[1][1] == 'O' && grid[0][2] == 'O')
	{
		if (VS_HUMAN == true)
		{
			winScreen();
		}
		loseScreen();
	}
}

int main()
{
	
	while (QUIT != true)
	{
		startScreen(); // say hello to player
		ticTacToe(); // draw the grid
		if (QUIT == true) // if player chose to quit, terminate game
		{
			break;
		}
		while (KEEP_GOING == true && VS_HUMAN == true) // if player chose to vs human, run this program
		{
			playerInput();
			ticTacToe();
			hasPlayerWon();
			if (GAME_RESET == true)
			{
				resetTheGame();
				GAME_RESET = false;
			}
			hasPlayerLost();
			if (GAME_RESET == true)
			{
				resetTheGame();
				GAME_RESET = false;
			}
			multiPlayer();
			if (QUIT == true)
			{
				break;
			}
		}
		while (KEEP_GOING == true && VS_COMP == true) // if player chose to vs comp, run this program
		{
			playerInput();
			ticTacToe();
			hasPlayerWon();
			if (GAME_RESET == true)
			{
				resetTheGame();
				GAME_RESET = false;
			}
			hasPlayerLost();
			if (GAME_RESET == true)
			{
				resetTheGame();
				GAME_RESET = false;
			}
			computerPlays();
			hasPlayerLost();
			if (GAME_RESET == true)
			{
				resetTheGame();
				GAME_RESET = false;
			}
			if (QUIT == true)
			{
				break;
			}
		}
	}

	system("cls");
	cout << "\n\n\t Leaving me I see. Fine. I don't want you here anyway \n" << endl; // give player farewell message
	cout << "\t\t BAAAAAAAAAAAAKA \n\n\n";
		
	return(0);
}