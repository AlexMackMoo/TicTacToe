#include <iostream>
#include <string>
#include <conio.h>
#include <ctime>
using namespace std;


char grid[3][3] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' };
int row;
int column;
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


// input the players chosen move
void playerInput()
{
	char letter;
	cout << " \n \t Please choose your move: ";
	cin >> letter;

	switch (letter)															// Use a switch statment to enter numbers into a row and column
	{
	case 'a':
		row = 0;
		column = 0;
			break;
	case 'b':
		row = 0;
		column = 1;
			break;
	case 'c':
		row = 0;
		column = 2;
		break;
	case 'd':
		row = 1;
		column = 0;
		break;
	case 'e':
		row = 1;
		column = 1;
		break;
	case 'f':
		row = 1;
		column = 2;
		break;
	case 'g':
		row = 2;
		column = 0;
		break;
	case 'h':
		row = 2;
		column = 1;
		break;
	case 'i':
		row = 2;
		column = 2;
		break;
	default:
		cout << "Seriously how do you always end up here? Leave. \n";
			break;
	}

	if (grid[row][column] != 'X' && grid[row][column] != 'O')				// insert row and column into array, check if clear location
	{
		grid[row][column] = sign;											// if location is clear, let player go
	}
	else																	// if spot is not clear, give player another go
	{
		cout << "\n\n \t Mate you can't dooooo that. You know this. Don't be naughty.";
		playerInput();
	}

	if (letter == 't')
	{
		QUIT = true;
		return;
	}
	system("cls");
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
void computerPlays()
{
	unsigned int seed = time(0);
	srand(seed);
	int randomNumMax = 9;
	int randomNumMin = 2;
	int randomNumber;
	int letter;
		
	for (int comp = 0; comp < 1; comp++)
	{
		randomNumber = rand();
		letter = randomNumber % (randomNumMax - randomNumMin) + randomNumMin;
	}


	switch (letter)															// Use a switch statment to enter numbers into a row and column
	{
	case 1:
		row = 0;
		column = 0;
		break;
	case 2:
		row = 0;
		column = 1;
		break;
	case 3:
		row = 0;
		column = 2;
		break;
	case 4:
		row = 1;
		column = 0;
		break;
	case 5:
		row = 1;
		column = 1;
		break;
	case 6:
		row = 1;
		column = 2;
		break;
	case 7:
		row = 2;
		column = 0;
		break;
	case 8:
		row = 2;
		column = 1;
		break;
	case 9:
		row = 2;
		column = 2;
		break;
	default:
		cout << "Seriously how do you always end up here? Leave. \n";
		break;
	}

	if (grid[row][column] != 'X' && grid[row][column] != 'O')				// insert row and column into array, check if clear location
	{
		grid[row][column] = 'O';											// if location is clear, let player go
	}
	else																	// if spot is not clear, give computer another go
	{
		cout << "\n\n \t Mate you can't dooooo that. You know this. Don't be naughty.";
		computerPlays();
	}

	if (letter == 't')
	{
		QUIT = true;
		return;
	}
	
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

// reset the board after the game so it is ready to play again
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
// okay my idea half worked that's fine I will just check manually
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