#include <iostream>
#include <cstdlib>

using namespace std;
void showcurrentboard(char (&board)[3][3])
{	
	cout << " _________________\n";
	cout << "|     |     |     | \n";
	cout << "|  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] <<
	"  |\n";
	cout << "|_____|_____|_____|\n";
	cout << "|     |     |     |\n";
	cout << "|  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] <<
	"  |\n";
	cout << "|_____|_____|_____|\n";
	cout << "|     |     |     |\n";
	cout << "|  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] <<
	"  |\n";
	cout << "|_____|_____|_____|\n";
	
}

void clearboard(char (&board)[3][3])
{
	int i, j;	
	
    for(i = 0; i <3; i++)
    {   
		for(j = 0; j <3; j++)
		{
			board[i][j] = ' ';			
		}
	}
	
}

void setx(int row, int col, char (&board)[3][3])
{
	
	char x='x';
	if(row > 2 || row < 0 || col > 2 || col < 0)
	{	
		cout << "\nNot on board, please try again\n"
			<< "Please enter another row: ";
		cin >> row;
		cout << " and column: ";
		cin >> col;
		setx(row-1,col-1,board);
	}
	else if (board[row][col] == ' ')	board[row][col] = x;
	else
	{	cout << "Spot taken, please enter another row: ";
		cin >> row;
		cout << " and column: ";
		cin >> col;
		setx(row-1,col-1,board);
	}
}


void seto(char (&board)[3][3])
{
	int row, col, i, j;
	char o='o';	
		
	random();
	row = rand()%3;
	random();
	col = rand()%3;
	cout << "\nmy turn\n";
	
	if (board[row][col] == ' ') board[row][col] = o;
	else seto(board);
	
	
}

void showindex()
{
	char board[3][3];
   
	cout << " _________________\n";
	cout << "|     |     |     | \n";
	cout << "| " << "11" << "  | " << "12" << "  | " << "13" <<
	"  |\n";
	cout << "|_____|_____|_____|\n";
	cout << "|     |     |     |\n";
	cout << "| " << "21" << "  | " << "22" << "  | " << "23" <<
	"  |\n";
	cout << "|_____|_____|_____|\n";
	cout << "|     |     |     |\n";
	cout << "| " << "31" << "  | " << "32" << "  | " << "33" <<
	"  |\n";
	cout << "|_____|_____|_____|\n";
	
	
}

void winnerdisplay(char c)
{
	if(c == 'x') cout << "You won!";
	else cout << "I win";
}

bool gamewon(char (&board)[3][3])
{
	bool row0_win = (board[0][0]!=' ' && (board[0][0] == board[0][1]) && (board[0][1] == board[0][2]));
	bool row1_win = (board[1][0]!=' ' && (board[1][0] == board[1][1]) && (board[1][1] == board[1][2]));
	bool row2_win = (board[2][0]!=' ' && (board[2][0] == board[2][1]) && (board[2][1] == board[2][2]));
	bool col0_win = (board[0][0]!=' ' && (board[0][0] == board[1][0]) && (board[1][0] == board[2][0]));
	bool col1_win = (board[0][1]!=' ' && (board[0][1] == board[1][1]) && (board[1][1] == board[2][1]));
	bool col2_win = (board[0][2]!=' ' && (board[0][2] == board[1][2]) && (board[1][2] == board[2][2]));
	bool diag1_win = (board[0][0]!=' ' && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2]));
	bool diag2_win = (board[0][2]!=' ' && (board[0][2] == board[1][1]) && (board[1][1] == board[2][0]));
	
	
	if(row0_win || col0_win || diag1_win)
	{
		winnerdisplay(board[0][0]);
		return true;
	}
	else if(row1_win || col1_win)
	{
		winnerdisplay(board[1][0]);
		return true;		
	}
	else if(row2_win || col2_win || diag2_win)
	{
		winnerdisplay(board[2][0]);
		return true;		
	}
	
	return false;
}


int playgame(char (&board)[3][3])
{
	int winner, row, col;
	
	while(!gamewon(board))
	{	cout << "Insert row: ";
		cin >> row; 
		cout << "Insert col: ";
		cin >> col;
		
		setx(row-1, col-1, board);
		seto(board);		
		
		showcurrentboard(board);
		
	}
	
	return winner;
}

bool playagain()
{
	int choice;
	
	cout << "\nWant to play again? Enter 1 to play again, 0 if not. ";
	cin >> choice;
	if(choice==1) return true;
	
	return false;
}


int main()
{
	char x='x', o='o';	
	char board[3][3];
	
	cout << "The game board is indexed as such:\n";
	showindex();
	
	clearboard(board);
	cout << "Let's start, you go first.\n";
	playgame(board);
	
	while(playagain())
	{ 
		clearboard(board);
		playgame(board);
	}
	
    
	return 0;
}


