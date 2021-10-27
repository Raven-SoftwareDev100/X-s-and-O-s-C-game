// X's and O's game in C++
#include <iostream>
using namespace std;

char square[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' }; // Array for game board
int checkWin(); // Checks for win condition
void drawBoard(); // Creates board for players

int main() // Determines player turns and how spaces on board are filled
{
	int player = 1, winCheckValue, choice; 
	char mark;

	do
	{
		drawBoard();
		player = player % 2 ? 1 : 2;

		cout << "\nPlayer " << player << "'s turn. Please enter a number: ";
		cin >> choice;
		mark = (player == 1) ? 'X' : 'O'; // Sets player's mark to X or a O

		if (choice == 1 && square[1] == '1') // If square chosen is unfilled, the number is replaced with player's mark
		{
			square[1] = mark;
		}
		else if (choice == 2 && square[2] == '2')
		{
			square[2] = mark;
		}
		else if (choice == 3 && square[3] == '3')
		{
			square[3] = mark;
		}
		else if (choice == 4 && square[4] == '4')
		{
			square[4] = mark;
		}
		else if (choice == 5 && square[5] == '5')
		{
			square[5] = mark;
		}
		else if (choice == 6 && square[6] == '6')
		{
			square[6] = mark;
		}
		else if (choice == 7 && square[7] == '7')
		{
			square[7] = mark;
		}
		else if (choice == 8 && square[8] == '8')
		{
			square[8] = mark;
		}
		else if (choice == 9 && square[9] == '9')
		{
			square[9] = mark;
		}

		else // Ignore move if space is already filled, give player another go to select unfilled space
		{
			cout << "\nInvalid move. Try again.";
			player--;
			cin.ignore();
			cin.get();
		}

		winCheckValue = checkWin(); // Gets value from checkWin()
		player++;

	} while (winCheckValue == -1); // Game keeps going as long as winCheckValue == -1

	drawBoard();

	if (winCheckValue == 1) // Ends game when player wins or draw occurs
	{
		cout << "\n==> \aPlayer " << --player << " wins! ";
	}
	else
	{
		cout << "\n==> \aGame Draw!";
	}

	cin.ignore();
	cin.get();
}

int checkWin() // Checks if any rows have the same value then returns game result
{
	if (square[1] == square[2] && square[2] == square[3]) // Checks if any horizontal rows all contain the same value; returns 1 for Game Over
	{
		return 1;
	}
	else if (square[4] == square[5] && square[5] == square[6])
	{
		return 1;
	}
	else if (square[7] == square[8] && square[8] == square[9])
	{
		return 1;
	}

	else if (square[1] == square[4] && square[4] == square[7]) // Checks if any vertical rows contain the same value; returns 1 for Game Over
	{
		return 1;
	}
	else if (square[2] == square[5] && square[5] == square[8])
	{
		return 1;
	}
	else if (square[3] == square[6] && square[6] == square[9])
	{
		return 1;
	} 

	else if (square[1] == square[5] && square[5] == square[9]) // Checks if any diagonal rows have been filled; returns 1 for Game Over
	{
		return 1;
	}
	else if (square[3] == square[5] && square[5] == square[7])
	{
		return 1;
	}

	else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
		&& square[4] != '4' && square[5] != '5' && square[6] != '6'
		&& square[7] != '7' && square[8] != '8' && square[9] != '9') 
	{
		return 0; // Returns 0 for Game Over and/or No Result
	} 

	else 
	{
		return -1; // Returns -1 for Game in progress
	}
}

void drawBoard() // Draws the board with the players marked
{
	system("cls");
	cout << "\n\n\tTIC-TAC-TOE\n\n";
	cout << "Player 1 (X) and Player 2 (O)\n\n";

	cout << "    |    |    " << endl;
	cout << " " << square[1] << "  | " << square[2] << "  | " << square[3] << endl;
	cout << "____|____|____" << endl;
	cout << "    |    |    " << endl;
	cout << " " << square[4] << "  | " << square[5] << "  | " << square[6] << endl;
	cout << "____|____|____" << endl;
	cout << "    |    |    " << endl;
	cout << " " << square[7] << "  | " << square[8] << "  | " << square[9] << endl;
	cout << "____|____|____" << endl;
	cout << "    |    |    " << endl;
	cout << "    |    |    " << endl;
}