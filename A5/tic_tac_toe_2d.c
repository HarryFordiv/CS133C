#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>


int NPCturn();
int gamestate(char*, int);
char board[3][3];


void  main()
{
	
	char col[2];
	char row[2];

	int count = 0;
	int count1 = 0;
	int rn = 0;
	int rn1 = 0;
	int n;
	int error = 0;
	bool playagain = true;	

	while(playagain)//loop to play multiple times
	{
		//set variables at the begining of each loop	
		n = 1;
		int rn = 0;
		srand(time(0));	
		rn = rand()%3;
		int rn1 = 0;
		srand(time(0));	
		rn1 = rand()%3;
		//reset board
		
		board[0][0] = '0';	
		board[0][1] = '1';	
		board[0][2] = '2';	
		board[1][0] = '3';
		board[1][1] = '4';	
		board[1][2] = '5';	
		board[2][0] = '6';	
		board[2][1] = '7';
		board[2][2] = '8';	
		//loop
		while(n == 1)
		{

			printf("\nNPC turn ");
			if(rn == 0)
			{
				error = NPCturn();
			}
			if(rn != 0)
			{
				board[rn][rn1] = 'X';
			}
			rn = 0;
			//interact with user	
			printf("\nBoard so far:\n  %c   %c   %c \n\n  %c   %c   %c \n\n  %c   %c   %c \n", 				board[0][0],board[0][1],board[0][2],
			board[1][0],board[1][1],board[1][2],board[2][0],
			board[2][1],board[2][2]);

			n = gamestate(&board[0][0], 0);
			if(n != 1){break;}

			col[0] = '\0';
			row[0] = '\0';
			printf("\nPick a column 0-2: ");
			scanf("%s" , col);
			getchar();
			while(atoi(col) < 0 || atoi(col) > 2)
			{
				col[0] = '\0';
				printf("\nPick a column 0-2: ");
				scanf("%s" , col);
				getchar();
				
			}
			printf("\nPick a row 0-2: ");
			scanf("%s" , row);
			getchar();
			while(atoi(row) < 0 || atoi(row) > 2)
			{
				row[0] = '\0';
				printf("\nPick a row 0-2: ");
				scanf("%s" , row);
				getchar();
				
			}
			while(board[atoi(row)][atoi(col)] == 'O' || board[atoi(row)][atoi(col)] == 'X')
			{
				col[0] = '\0';
				row[0] = '\0';
				printf("\nPick an empty zone: ");
				printf("\nPick a column: ");
				scanf("%s" , col);
				getchar();
				while(atoi(col) < 0 || atoi(col) > 2)
				{
					col[0] = '\0';
					printf("\nPick a column 0-2: ");
					scanf("%s" , col);
					getchar();
				
				}
				printf("\nPick a row: ");
				scanf("%s" , row);
				getchar();
				while(atoi(row) < 0 || atoi(row) > 2)
				{
					row[0] = '\0';
					printf("\nPick a row 0-2: ");
					scanf("%s" , row);
					getchar();
				
				}
			}
			board[atoi(row)][atoi(col)] = 'O';
			n = gamestate(&board[0][0], 0);
			
		}
		//tell the user if they lost 
		//then give option to play again
		if(n == 0)
		{
			printf("\nGame over!\n");
			printf("\nType 1 to play again, or anything else to exit\n");
			scanf("%s", col);
			getchar();
			if(atoi(col) == 1)
			{
				playagain = true;
			}
			else
			{
				playagain = false;
			}
		}
		//tell user if they won and give option to play again
		if(n == -1)
		{
			printf("\nYou Won!\n");
			printf("\nType 1 to play again, or anything else to exit\n");
			scanf("%s", col);
			getchar();
			if(atoi(col) == 1)
			{
				playagain = true;
			}
			else
			{
				playagain = false;
			}
		}
		//tell user it was a tie and give option to play again
		if(n == 2)
		{
			printf("\nIt was a tie!\n");
			printf("\nType 1 to play again, or anything else to exit\n");
			scanf("%s", col);
			getchar();
			if(atoi(col) == 1)
			{
				playagain = true;
			}
			else
			{
				playagain = false;
			}
		}
		
	}
}	

int gamestate(char * state1, int type)
{
	if(type = 1)
	{
		char state[10];
		strcpy(state, state1);
		int num = 0;
		//check for winner X
		if(state[0] == 'X')
		{
			if(state[1] == 'X' && state[2] == 'X'){return 0;}
			if(state[3] == 'X' && state[6] == 'X'){return 0;}
		}
		if(state[8] == 'X')
		{
			if(state[7] == 'X' && state[6] == 'X'){return 0;}
			if(state[2] == 'X' && state[5] == 'X'){return 0;}
		}
		if(state[4] == 'X')
		{
			if(state[0] == 'X' && state[8] == 'X'){return 0;}
			if(state[3] == 'X' && state[5] == 'X'){return 0;}
			if(state[6] == 'X' && state[2] == 'X'){return 0;}
			if(state[7] == 'X' && state[1] == 'X'){return 0;}
		}
		//check for winner O
		if(state[0] == 'O')
		{
			if(state[1] == 'O' && state[2] == 'O'){return -1;}
			if(state[3] == 'O' && state[6] == 'O'){return -1;}
		}
		if(state[8] == 'O')
		{
			if(state[7] == 'O' && state[6] == 'O'){return -1;}
			if(state[2] == 'O' && state[5] == 'O'){return -1;}
		}
		if(state[4] == 'O')
		{
			if(state[0] == 'O' && state[8] == 'O'){return -1;}
			if(state[3] == 'O' && state[5] == 'O'){return -1;}
			if(state[6] == 'O' && state[2] == 'O'){return -1;}
			if(state[7] == 'O' && state[1] == 'O'){return -1;}
		}
		//check if any moves remain
		while(num < 9)
		{
			if(state[num] < 57){return 1;}
			num++;
		}
	}
	
	if(type = 0)
	{
		char state0[3][3];
		memcpy(state0, state1,sizeof(char*) * 3);
		int col = 0;
		int row = 0;
		//check for winner X
		if(state0[0][0] == 'X')
		{
			if(state0[0][1] == 'X' && state0[0][2] == 'X'){return 0;}
			if(state0[1][0] == 'X' && state0[2][0] == 'X'){return 0;}
		}
		if(state0[2][2] == 'X')
		{
			if(state0[2][1] == 'X' && state0[2][0] == 'X'){return 0;}
			if(state0[0][2] == 'X' && state0[1][2] == 'X'){return 0;}
		}
		if(state0[1][1] == 'X')
		{
			if(state0[0][0] == 'X' && state0[2][2] == 'X'){return 0;}
			if(state0[1][0] == 'X' && state0[1][2] == 'X'){return 0;}
			if(state0[2][0] == 'X' && state0[0][2] == 'X'){return 0;}
			if(state0[2][1] == 'X' && state0[0][1] == 'X'){return 0;}
		}
		//check for winner O
		if(state0[0][0] == 'O')
		{
			if(state0[1][0] == 'O' && state0[2][0] == 'O'){return -1;}
			if(state0[0][1] == 'O' && state0[0][2] == 'O'){return -1;}
		}
		if(state0[2][2] == 'O')
		{
			if(state0[2][1] == 'O' && state0[2][0] == 'O'){return -1;}
			if(state0[0][2] == 'O' && state0[1][2] == 'O'){return -1;}
		}
		if(state0[1][1] == 'O')
		{
			if(state0[0][0] == 'O' && state0[2][2] == 'O'){return 0;}
			if(state0[1][0] == 'O' && state0[1][2] == 'O'){return 0;}
			if(state0[2][0] == 'O' && state0[0][2] == 'O'){return 0;}
			if(state0[2][1] == 'O' && state0[0][1] == 'O'){return 0;}
		}
		//check if any moves remain
		while(col < 3)	
		{			
			while(row < 3)
			{
				if(state0[row][col] < 57){return 1;}
				row++;
			}
			row = 0;
			col++;
		}
	}
	//else game is a tie
	return 2;
}



int NPCturn()
{
	int rn = 0;
	int col = 0;
	int row = 0;
	srand(time(0));	
	rn = rand()%2;
//look to win
	if(board[1][1] == 'X')
	{
		if(board[0][1] == 'X' && board[2][1] != 'O' && board[2][1] != 'X'){board[2][1] = 'X'; return 0;}
		if(board[2][1] == 'X' && board[0][1] != 'O' && board[0][1] != 'X'){board[0][1] = 'X'; return 0;}
		if(board[0][2] == 'X' && board[2][0] != 'O' && board[2][0] != 'X'){board[2][0] = 'X'; return 0;}
		if(board[2][0] == 'X' && board[0][2] != 'O' && board[0][2] != 'X'){board[0][2] = 'X'; return 0;}
		if(board[0][0] == 'X' && board[2][2] != 'O' && board[2][2] != 'X'){board[2][2] = 'X'; return 0;}
		if(board[2][2] == 'X' && board[0][0] != 'O' && board[0][0] != 'X'){board[0][0] = 'X'; return 0;}
		if(board[1][0] == 'X' && board[1][2] != 'O' && board[1][2] != 'X'){board[1][2] = 'X'; return 0;}
		if(board[1][2] == 'X' && board[1][0] != 'O' && board[1][0] != 'X'){board[1][0] = 'X'; return 0;}		
	}	
	if(board[0][0] == 'X')
	{
		if(board[1][0] == 'X' && board[2][0] != 'O' && board[2][0] != 'X'){board[2][0] = 'X'; return 0;}
		if(board[2][0] == 'X' && board[1][0] != 'O' && board[1][0] != 'X'){board[0][2] = 'X'; return 0;}
		if(board[1][1] == 'X' && board[2][2] != 'O' && board[2][2] != 'X'){board[2][2] = 'X'; return 0;}
		if(board[2][2] == 'X' && board[1][1] != 'O' && board[1][1] != 'X'){board[1][1] = 'X'; return 0;}
		if(board[0][1] == 'X' && board[0][2] != 'O' && board[0][2] != 'X'){board[0][2] = 'X'; return 0;}
		if(board[0][2] == 'X' && board[0][1] != 'O' && board[0][1] != 'X'){board[0][1] = 'X'; return 0;}	
	}	
	if(board[0][2] == 'X')
	{
		if(board[0][1] == 'X' && board[0][0] != 'O' && board[0][0] != 'X'){board[0][0] = 'X'; return 0;}
		if(board[0][0] == 'X' && board[0][1] != 'O' && board[0][1] != 'X'){board[0][1] = 'X'; return 0;}
		if(board[1][1] == 'X' && board[2][0] != 'O' && board[2][0] != 'X'){board[2][0] = 'X'; return 0;}
		if(board[2][0] == 'X' && board[1][1] != 'O' && board[1][1] != 'X'){board[1][1] = 'X'; return 0;}
		if(board[1][2] == 'X' && board[2][2] != 'O' && board[2][2] != 'X'){board[2][2] = 'X'; return 0;}
		if(board[2][2] == 'X' && board[1][2] != 'O' && board[1][2] != 'X'){board[1][2] = 'X'; return 0;}	
	}	
	if(board[2][0] == 'X')
	{
		if(board[1][0] == 'X' && board[0][0] != 'O' && board[0][0] != 'X'){board[0][0] = 'X'; return 0;}
		if(board[0][0] == 'X' && board[1][0] != 'O' && board[1][0] != 'X'){board[1][0] = 'X'; return 0;}
		if(board[1][1] == 'X' && board[0][2] != 'O' && board[0][2] != 'X'){board[0][2] = 'X'; return 0;}
		if(board[0][2] == 'X' && board[1][1] != 'O' && board[1][1] != 'X'){board[1][1] = 'X'; return 0;}
		if(board[2][1] == 'X' && board[2][2] != 'O' && board[2][2] != 'X'){board[2][2] = 'X'; return 0;}
		if(board[2][2] == 'X' && board[2][1] != 'O' && board[2][1] != 'X'){board[2][1] = 'X'; return 0;}	
	}
	if(board[2][2] == 'X')
	{
		if(board[1][1] == 'X' && board[0][0] != 'O' && board[0][0] != 'X'){board[0][0] = 'X'; return 0;}
		if(board[0][0] == 'X' && board[1][1] != 'O' && board[1][1] != 'X'){board[1][1] = 'X'; return 0;}
		if(board[2][1] == 'X' && board[2][0] != 'O' && board[2][0] != 'X'){board[2][0] = 'X'; return 0;}
		if(board[2][0] == 'X' && board[2][1] != 'O' && board[2][1] != 'X'){board[2][1] = 'X'; return 0;}
		if(board[1][2] == 'X' && board[0][2] != 'O' && board[0][2] != 'X'){board[0][2] = 'X'; return 0;}
		if(board[0][2] == 'X' && board[1][2] != 'O' && board[1][2] != 'X'){board[1][2] = 'X'; return 0;}	
	}
	if(board[0][1] == 'X')
	{
		if(board[0][2] == 'X' && board[0][0] != 'O' && board[0][0] != 'X'){board[0][0] = 'X'; return 0;}
		if(board[0][0] == 'X' && board[0][2] != 'O' && board[0][2] != 'X'){board[0][2] = 'X'; return 0;}
		if(board[1][1] == 'X' && board[2][1] != 'O' && board[2][1] != 'X'){board[2][1] = 'X'; return 0;}
		if(board[2][1] == 'X' && board[1][1] != 'O' && board[1][1] != 'X'){board[1][1] = 'X'; return 0;}	
	}			
	if(board[1][0] == 'X')
	{
		if(board[0][0] == 'X' && board[2][0] != 'O' && board[2][0] != 'X'){board[2][0] = 'X'; return 0;}
		if(board[2][0] == 'X' && board[0][0] != 'O' && board[0][0] != 'X'){board[0][0] = 'X'; return 0;}
		if(board[1][1] == 'X' && board[1][2] != 'O' && board[1][2] != 'X'){board[1][2] = 'X'; return 0;}
		if(board[1][2] == 'X' && board[1][1] != 'O' && board[1][1] != 'X'){board[1][1] = 'X'; return 0;}	
	}
	//interfere with opponent
	if(board[1][1] == 'O')
	{
		if(board[0][1] == 'O' && board[2][1] != 'O' && board[2][1] != 'X'){board[2][1] = 'X'; return 0;}
		if(board[2][1] == 'O' && board[0][1] != 'O' && board[0][1] != 'X'){board[0][1] = 'X'; return 0;}
		if(board[0][2] == 'O' && board[2][0] != 'O' && board[2][0] != 'X'){board[2][0] = 'X'; return 0;}
		if(board[2][0] == 'O' && board[0][2] != 'O' && board[0][2] != 'X'){board[0][2] = 'X'; return 0;}
		if(board[0][0] == 'O' && board[2][2] != 'O' && board[2][2] != 'X'){board[2][2] = 'X'; return 0;}
		if(board[2][2] == 'O' && board[0][0] != 'O' && board[0][0] != 'X'){board[0][0] = 'X'; return 0;}
		if(board[1][0] == 'O' && board[1][2] != 'O' && board[1][2] != 'X'){board[1][2] = 'X'; return 0;}
		if(board[1][2] == 'O' && board[1][0] != 'O' && board[1][0] != 'X'){board[1][0] = 'X'; return 0;}		
	}	
	if(board[0][0] == 'O')
	{
		if(board[1][0] == 'O' && board[2][0] != 'O' && board[2][0] != 'X'){board[2][0] = 'X'; return 0;}
		if(board[2][0] == 'O' && board[1][0] != 'O' && board[1][0] != 'X'){board[0][2] = 'X'; return 0;}
		if(board[1][1] == 'O' && board[2][2] != 'O' && board[2][2] != 'X'){board[2][2] = 'X'; return 0;}
		if(board[2][2] == 'O' && board[1][1] != 'O' && board[1][1] != 'X'){board[1][1] = 'X'; return 0;}
		if(board[0][1] == 'O' && board[0][2] != 'O' && board[0][2] != 'X'){board[0][2] = 'X'; return 0;}
		if(board[0][2] == 'O' && board[0][1] != 'O' && board[0][1] != 'X'){board[0][1] = 'X'; return 0;}	
	}	
	if(board[0][2] == 'O')
	{
		if(board[0][1] == 'O' && board[0][0] != 'O' && board[0][0] != 'X'){board[0][0] = 'X'; return 0;}
		if(board[0][0] == 'O' && board[0][1] != 'O' && board[0][1] != 'X'){board[0][1] = 'X'; return 0;}
		if(board[1][1] == 'O' && board[2][0] != 'O' && board[2][0] != 'X'){board[2][0] = 'X'; return 0;}
		if(board[2][0] == 'O' && board[1][1] != 'O' && board[1][1] != 'X'){board[1][1] = 'X'; return 0;}
		if(board[1][2] == 'O' && board[2][2] != 'O' && board[2][2] != 'X'){board[2][2] = 'X'; return 0;}
		if(board[2][2] == 'O' && board[1][2] != 'O' && board[1][2] != 'X'){board[1][2] = 'X'; return 0;}	
	}	
	if(board[2][0] == 'O')
	{
		if(board[1][0] == 'O' && board[0][0] != 'O' && board[0][0] != 'X'){board[0][0] = 'X'; return 0;}
		if(board[0][0] == 'O' && board[1][0] != 'O' && board[1][0] != 'X'){board[1][0] = 'X'; return 0;}
		if(board[1][1] == 'O' && board[0][2] != 'O' && board[0][2] != 'X'){board[0][2] = 'X'; return 0;}
		if(board[0][2] == 'O' && board[1][1] != 'O' && board[1][1] != 'X'){board[1][1] = 'X'; return 0;}
		if(board[2][1] == 'O' && board[2][2] != 'O' && board[2][2] != 'X'){board[2][2] = 'X'; return 0;}
		if(board[2][2] == 'O' && board[2][1] != 'O' && board[2][1] != 'X'){board[2][1] = 'X'; return 0;}	
	}
	if(board[2][2] == 'O')
	{
		if(board[1][1] == 'O' && board[0][0] != 'O' && board[0][0] != 'X'){board[0][0] = 'X'; return 0;}
		if(board[0][0] == 'O' && board[1][1] != 'O' && board[1][1] != 'X'){board[1][1] = 'X'; return 0;}
		if(board[2][1] == 'O' && board[2][0] != 'O' && board[2][0] != 'X'){board[2][0] = 'X'; return 0;}
		if(board[2][0] == 'O' && board[2][1] != 'O' && board[2][1] != 'X'){board[2][1] = 'X'; return 0;}
		if(board[1][2] == 'O' && board[0][2] != 'O' && board[0][2] != 'X'){board[0][2] = 'X'; return 0;}
		if(board[0][2] == 'O' && board[1][2] != 'O' && board[1][2] != 'X'){board[1][2] = 'X'; return 0;}	
	}
	if(board[0][1] == 'O')
	{
		if(board[0][2] == 'O' && board[0][0] != 'O' && board[0][0] != 'X'){board[0][0] = 'X'; return 0;}
		if(board[0][0] == 'O' && board[0][2] != 'O' && board[0][2] != 'X'){board[0][2] = 'X'; return 0;}
		if(board[1][1] == 'O' && board[2][1] != 'O' && board[2][1] != 'X'){board[2][1] = 'X'; return 0;}
		if(board[2][1] == 'O' && board[1][1] != 'O' && board[1][1] != 'X'){board[1][1] = 'X'; return 0;}	
	}			
	if(board[1][0] == 'O')
	{
		if(board[0][0] == 'O' && board[2][0] != 'O' && board[2][0] != 'X'){board[2][0] = 'X'; return 0;}
		if(board[2][0] == 'O' && board[0][0] != 'O' && board[0][0] != 'X'){board[0][0] = 'X'; return 0;}
		if(board[1][1] == 'O' && board[1][2] != 'O' && board[1][2] != 'X'){board[1][2] = 'X'; return 0;}
		if(board[1][2] == 'O' && board[1][1] != 'O' && board[1][1] != 'X'){board[1][1] = 'X'; return 0;}	
	}
	//make standard plays secure 4 first if possible for highest chance to win	
	if(board[1][1] != 'X' && board[1][1] != 'O'){board[1][1] = 'X'; return 0;}
	
	if(board[1][1] == 'X')
	{		
		if(rn = 0){if(board[0][1] == '1' && board[2][1] != 'O' && board[2][1] != 'X'){board[2][1] = 'X'; return 0;}}
		if(rn = 1){if(board[2][1] == '7' && board[0][1] != 'O' && board[0][1] != 'X'){board[0][1] = 'X'; return 0;}}
		if(rn = 0){if(board[1][0] == '3' && board[1][2] != 'O' && board[1][2] != 'X'){board[1][2] = 'X'; return 0;}}
		if(rn = 1){if(board[1][2] == '5' && board[1][0] != 'O' && board[1][0] != 'X'){board[1][0] = 'X'; return 0;}}
		if(rn = 0){if(board[0][0] == '0' && board[2][2] != 'O' && board[2][2] != 'X'){board[2][2] = 'X'; return 0;}}
		if(rn = 1){if(board[2][2] == '8' && board[0][0] != 'O' && board[0][0] != 'X'){board[0][0] = 'X'; return 0;}}
		if(rn = 0){if(board[0][2] == '2' && board[2][0] != 'O' && board[2][0] != 'X'){board[2][0] = 'X'; return 0;}}
		if(rn = 1){if(board[2][0] == '6' && board[0][2] != 'O' && board[0][2] != 'X'){board[0][2] = 'X'; return 0;}}		
	}	
	if(board[0][0] == 'X')
	{
		if(rn = 0){if(board[0][2] == '3' && board[2][0] != 'O' && board[2][0] != 'X'){board[2][0] = 'X'; return 0;}}
		if(rn = 1){if(board[2][0] == '6' && board[0][2] != 'O' && board[0][2] != 'X'){board[0][2] = 'X'; return 0;}}
		if(rn = 0){if(board[1][1] == '4' && board[2][2] != 'O' && board[2][2] != 'X'){board[2][2] = 'X'; return 0;}}
		if(rn = 1){if(board[2][2] == '8' && board[1][1] != 'O' && board[1][1] != 'X'){board[1][1] = 'X'; return 0;}}
		if(rn = 0){if(board[0][1] == '1' && board[0][2] != 'O' && board[0][2] != 'X'){board[0][2] = 'X'; return 0;}}
		if(rn = 1){if(board[0][2] == '2' && board[0][1] != 'O' && board[0][1] != 'X'){board[0][1] = 'X'; return 0;}}	
	}	
	if(board[0][2] == 'X')
	{
		if(rn = 0){if(board[0][1] == '1' && board[0][0] != 'O' && board[0][0] != 'X'){board[0][0] = 'X'; return 0;}}
		if(rn = 1){if(board[0][0] == '0' && board[0][1] != 'O' && board[0][1] != 'X'){board[0][1] = 'X'; return 0;}}
		if(rn = 0){if(board[1][1] == '4' && board[2][0] != 'O' && board[2][0] != 'X'){board[2][0] = 'X'; return 0;}}
		if(rn = 1){if(board[2][0] == '6' && board[1][1] != 'O' && board[1][1] != 'X'){board[1][1] = 'X'; return 0;}}
		if(rn = 0){if(board[1][2] == '5' && board[2][2] != 'O' && board[2][2] != 'X'){board[2][2] = 'X'; return 0;}}
		if(rn = 1){if(board[2][2] == '8' && board[1][2] != 'O' && board[1][2] != 'X'){board[1][2] = 'X'; return 0;}}	
	}	
	if(board[2][0] == 'X')
	{
		if(rn = 0){if(board[1][0] == '3' && board[0][0] != 'O' && board[0][0] != 'X'){board[0][0] = 'X'; return 0;}}
		if(rn = 1){if(board[0][0] == '0' && board[1][0] != 'O' && board[1][0] != 'X'){board[1][0] = 'X'; return 0;}}
		if(rn = 0){if(board[1][1] == '4' && board[0][2] != 'O' && board[0][2] != 'X'){board[0][2] = 'X'; return 0;}}
		if(rn = 1){if(board[0][2] == '2' && board[1][1] != 'O' && board[1][1] != 'X'){board[1][1] = 'X'; return 0;}}
		if(rn = 0){if(board[2][1] == '7' && board[2][2] != 'O' && board[2][2] != 'X'){board[2][2] = 'X'; return 0;}}
		if(rn = 1){if(board[2][2] == '8' && board[2][1] != 'O' && board[2][1] != 'X'){board[2][1] = 'X'; return 0;}}	
	}
	if(board[2][2] == 'X')
	{
		if(rn = 0){if(board[1][1] == '4' && board[0][0] != 'O' && board[0][0] != 'X'){board[0][0] = 'X'; return 0;}}
		if(rn = 1){if(board[0][0] == '0' && board[1][1] != 'O' && board[1][1] != 'X'){board[1][1] = 'X'; return 0;}}
		if(rn = 0){if(board[2][1] == '7' && board[2][0] != 'O' && board[2][0] != 'X'){board[2][0] = 'X'; return 0;}}
		if(rn = 1){if(board[2][0] == '6' && board[2][1] != 'O' && board[2][1] != 'X'){board[2][1] = 'X'; return 0;}}
		if(rn = 0){if(board[1][2] == '5' && board[0][2] != 'O' && board[0][2] != 'X'){board[0][2] = 'X'; return 0;}}
		if(rn = 1){if(board[0][2] == '2' && board[1][2] != 'O' && board[1][2] != 'X'){board[1][2] = 'X'; return 0;}}	
	}
	if(board[0][1] == 'X')
	{
		if(rn = 0){if(board[0][2] == '2' && board[0][0] != 'O' && board[0][0] != 'X'){board[0][0] = 'X'; return 0;}}
		if(rn = 1){if(board[0][0] == '0' && board[0][2] != 'O' && board[0][2] != 'X'){board[0][2] = 'X'; return 0;}}
		if(rn = 0){if(board[1][1] == '4' && board[2][1] != 'O' && board[2][1] != 'X'){board[2][1] = 'X'; return 0;}}
		if(rn = 1){if(board[2][1] == '7' && board[1][1] != 'O' && board[1][1] != 'X'){board[1][1] = 'X'; return 0;}}	
	}			
	if(board[1][0] == 'X')
	{
		if(rn = 0){if(board[0][0] == '0' && board[2][0] != 'O' && board[2][0] != 'X'){board[2][0] = 'X'; return 0;}}
		if(rn = 1){if(board[2][0] == '6' && board[0][0] != 'O' && board[0][0] != 'X'){board[0][0] = 'X'; return 0;}}
		if(rn = 0){if(board[1][1] == '4' && board[1][2] != 'O' && board[1][2] != 'X'){board[1][2] = 'X'; return 0;}}
		if(rn = 1){if(board[1][2] == '5' && board[1][1] != 'O' && board[1][1] != 'X'){board[1][1] = 'X'; return 0;}}	
	}
	if(board[1][2] == 'X')
	{
		if(rn = 0){if(board[0][2] == '2' && board[2][2] != 'O' && board[2][2] != 'X'){board[2][2] = 'X'; return 0;}}
		if(rn = 1){if(board[2][2] == '8' && board[0][2] != 'O' && board[0][2] != 'X'){board[0][2] = 'X'; return 0;}}
		if(rn = 0){if(board[1][1] == '4' && board[1][0] != 'O' && board[1][0] != 'X'){board[1][0] = 'X'; return 0;}}
		if(rn = 1){if(board[1][0] == '3' && board[1][1] != 'O' && board[1][1] != 'X'){board[1][1] = 'X'; return 0;}}	
	}	
	if(board[2][1] == 'X')
	{
		if(rn = 0){if(board[2][0] == '6' && board[2][2] != 'O' && board[2][2] != 'X'){board[2][2] = 'X'; return 0;}}
		if(rn = 1){if(board[2][2] == '8' && board[2][0] != 'O' && board[2][0] != 'X'){board[2][0] = 'X'; return 0;}}
		if(rn = 0){if(board[1][1] == '4' && board[0][1] != 'O' && board[0][1] != 'X'){board[0][1] = 'X'; return 0;}}
		if(rn = 1){if(board[0][1] == '1' && board[1][1] != 'O' && board[1][1] != 'X'){board[1][1] = 'X'; return 0;}}	
	}
	while(col < 3)	
	{			
		while(row < 3)
		{
			if(board[row][col] < 57){return 1;}
			row++;
		}
		row = 0;
		col++;
	}
				
}








