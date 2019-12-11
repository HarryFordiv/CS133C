#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>


int NPCturn();
int gamestate(char*, int);
char board[9];


void  main()
{
	char letter[2];

	int count = 0;
	int rn = 0;
	int n;
	int error = 0;
	bool playagain = true;	

	while(playagain)//loop to play multiple times
	{
		//set variables at the begining of each loop	
		n = 1;
		int rn = 0;
		srand(time(0));	
		rn = rand()%9;
		//reset board
		
		board[0] = '0';	
		board[1] = '1';	
		board[2] = '2';	
		board[3] = '3';
		board[4] = '4';	
		board[5] = '5';	
		board[6] = '6';	
		board[7] = '7';
		board[8] = '8';	
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
				board[rn] = 'X';
			}
			rn = 0;
			//interact with user	
			printf("\nBoard so far:\n  %c   %c   %c \n\n  %c   %c   %c \n\n  %c   %c   %c \n", 				board[0],board[1],board[2],
			board[3],board[4],board[5],board[6],
			board[7],board[8]);

			n = gamestate(board, 1);
			if(n != 1){break;}

			letter[0] = '\0';
			printf("\nPick an empty zone 0 through 8: ");
			scanf("%s" , letter);
			getchar();
			while(board[atoi(letter)] == 'O' || board[atoi(letter)] == 'X')
			{
				printf("\nPick an empty zone 0 through 8: ");
				scanf("%s" , letter);
				getchar();
			}
			board[atoi(letter)] = 'O';
			n = gamestate(board, 1);
			
		}
		//tell the user if they lost 
		//then give option to play again
		if(n == 0)
		{
			printf("\nGame over!\n");
			printf("\nType 1 to play again, or anything else to exit\n");
			scanf("%s", letter);
			getchar();
			if(atoi(letter) == 1)
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
			scanf("%s", letter);
			getchar();
			if(atoi(letter) == 1)
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
			scanf("%s", letter);
			getchar();
			if(atoi(letter) == 1)
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
	//else game is a tie
	return 2;
}



int NPCturn()
{
	int rn = 0;
	int num = 0;
	srand(time(0));	
	rn = rand()%2;
//look to win
	if(board[4] == 'X')
	{
		if(board[1] == 'X' && board[7] != 'O' && board[7] != 'X'){board[7] = 'X'; return 0;}
		if(board[7] == 'X' && board[1] != 'O' && board[1] != 'X'){board[1] = 'X'; return 0;}
		if(board[3] == 'X' && board[5] != 'O' && board[5] != 'X'){board[5] = 'X'; return 0;}
		if(board[5] == 'X' && board[3] != 'O' && board[3] != 'X'){board[3] = 'X'; return 0;}
		if(board[0] == 'X' && board[8] != 'O' && board[8] != 'X'){board[8] = 'X'; return 0;}
		if(board[8] == 'X' && board[0] != 'O' && board[0] != 'X'){board[0] = 'X'; return 0;}
		if(board[2] == 'X' && board[6] != 'O' && board[6] != 'X'){board[6] = 'X'; return 0;}
		if(board[6] == 'X' && board[2] != 'O' && board[2] != 'X'){board[2] = 'X'; return 0;}		
	}	
	if(board[0] == 'X')
	{
		if(board[3] == 'X' && board[6] != 'O' && board[6] != 'X'){board[6] = 'X'; return 0;}
		if(board[6] == 'X' && board[3] != 'O' && board[3] != 'X'){board[3] = 'X'; return 0;}
		if(board[4] == 'X' && board[8] != 'O' && board[8] != 'X'){board[8] = 'X'; return 0;}
		if(board[8] == 'X' && board[4] != 'O' && board[4] != 'X'){board[4] = 'X'; return 0;}
		if(board[1] == 'X' && board[2] != 'O' && board[2] != 'X'){board[2] = 'X'; return 0;}
		if(board[2] == 'X' && board[1] != 'O' && board[1] != 'X'){board[1] = 'X'; return 0;}	
	}	
	if(board[2] == 'X')
	{
		if(board[1] == 'X' && board[0] != 'O' && board[0] != 'X'){board[0] = 'X'; return 0;}
		if(board[0] == 'X' && board[1] != 'O' && board[1] != 'X'){board[1] = 'X'; return 0;}
		if(board[4] == 'X' && board[6] != 'O' && board[6] != 'X'){board[6] = 'X'; return 0;}
		if(board[6] == 'X' && board[4] != 'O' && board[4] != 'X'){board[4] = 'X'; return 0;}
		if(board[5] == 'X' && board[8] != 'O' && board[8] != 'X'){board[8] = 'X'; return 0;}
		if(board[8] == 'X' && board[5] != 'O' && board[5] != 'X'){board[5] = 'X'; return 0;}	
	}	
	if(board[6] == 'X')
	{
		if(board[3] == 'X' && board[0] != 'O' && board[0] != 'X'){board[0] = 'X'; return 0;}
		if(board[0] == 'X' && board[3] != 'O' && board[3] != 'X'){board[3] = 'X'; return 0;}
		if(board[4] == 'X' && board[2] != 'O' && board[2] != 'X'){board[2] = 'X'; return 0;}
		if(board[2] == 'X' && board[4] != 'O' && board[4] != 'X'){board[4] = 'X'; return 0;}
		if(board[7] == 'X' && board[8] != 'O' && board[8] != 'X'){board[8] = 'X'; return 0;}
		if(board[8] == 'X' && board[7] != 'O' && board[7] != 'X'){board[7] = 'X'; return 0;}	
	}
	if(board[8] == 'X')
	{
		if(board[4] == 'X' && board[0] != 'O' && board[0] != 'X'){board[0] = 'X'; return 0;}
		if(board[0] == 'X' && board[4] != 'O' && board[4] != 'X'){board[4] = 'X'; return 0;}
		if(board[7] == 'X' && board[6] != 'O' && board[6] != 'X'){board[6] = 'X'; return 0;}
		if(board[6] == 'X' && board[7] != 'O' && board[7] != 'X'){board[7] = 'X'; return 0;}
		if(board[5] == 'X' && board[2] != 'O' && board[2] != 'X'){board[2] = 'X'; return 0;}
		if(board[2] == 'X' && board[5] != 'O' && board[5] != 'X'){board[5] = 'X'; return 0;}	
	}
	if(board[1] == 'X')
	{
		if(board[2] == 'X' && board[0] != 'O' && board[0] != 'X'){board[0] = 'X'; return 0;}
		if(board[0] == 'X' && board[2] != 'O' && board[2] != 'X'){board[2] = 'X'; return 0;}
		if(board[4] == 'X' && board[7] != 'O' && board[7] != 'X'){board[7] = 'X'; return 0;}
		if(board[7] == 'X' && board[4] != 'O' && board[4] != 'X'){board[4] = 'X'; return 0;}	
	}			
	if(board[3] == 'X')
	{
		if(board[0] == 'X' && board[6] != 'O' && board[6] != 'X'){board[6] = 'X'; return 0;}
		if(board[6] == 'X' && board[0] != 'O' && board[0] != 'X'){board[0] = 'X'; return 0;}
		if(board[4] == 'X' && board[5] != 'O' && board[5] != 'X'){board[5] = 'X'; return 0;}
		if(board[5] == 'X' && board[4] != 'O' && board[4] != 'X'){board[4] = 'X'; return 0;}	
	}
	if(board[5] == 'X')
	{
		if(board[2] == 'X' && board[8] != 'O' && board[8] != 'X'){board[8] = 'X'; return 0;}
		if(board[8] == 'X' && board[2] != 'O' && board[2] != 'X'){board[2] = 'X'; return 0;}
		if(board[4] == 'X' && board[3] != 'O' && board[3] != 'X'){board[3] = 'X'; return 0;}
		if(board[3] == 'X' && board[4] != 'O' && board[4] != 'X'){board[4] = 'X'; return 0;}	
	}	
	if(board[7] == 'X')
	{
		if(board[6] == 'X' && board[8] != 'O' && board[8] != 'X'){board[8] = 'X'; return 0;}
		if(board[8] == 'X' && board[6] != 'O' && board[6] != 'X'){board[6] = 'X'; return 0;}
		if(board[4] == 'X' && board[1] != 'O' && board[1] != 'X'){board[1] = 'X'; return 0;}
		if(board[1] == 'X' && board[4] != 'O' && board[4] != 'X'){board[4] = 'X'; return 0;}	
	}
//look to prevent opponent from wining	
	if(board[4] == 'O')
	{
		if(board[1] == 'O' && board[7] != 'O' && board[7] != 'X'){board[7] = 'X'; return 0;}
		if(board[7] == 'O' && board[1] != 'O' && board[1] != 'X'){board[1] = 'X'; return 0;}
		if(board[3] == 'O' && board[5] != 'O' && board[5] != 'X'){board[5] = 'X'; return 0;}
		if(board[5] == 'O' && board[3] != 'O' && board[3] != 'X'){board[3] = 'X'; return 0;}
		if(board[0] == 'O' && board[8] != 'O' && board[8] != 'X'){board[8] = 'X'; return 0;}
		if(board[8] == 'O' && board[0] != 'O' && board[0] != 'X'){board[0] = 'X'; return 0;}
		if(board[2] == 'O' && board[6] != 'O' && board[6] != 'X'){board[6] = 'X'; return 0;}
		if(board[6] == 'O' && board[2] != 'O' && board[2] != 'X'){board[2] = 'X'; return 0;}		
	}	
	if(board[0] == 'O')
	{
		if(board[3] == 'O' && board[6] != 'O' && board[6] != 'X'){board[6] = 'X'; return 0;}
		if(board[6] == 'O' && board[3] != 'O' && board[3] != 'X'){board[3] = 'X'; return 0;}
		if(board[4] == 'O' && board[8] != 'O' && board[8] != 'X'){board[8] = 'X'; return 0;}
		if(board[8] == 'O' && board[4] != 'O' && board[4] != 'X'){board[4] = 'X'; return 0;}
		if(board[1] == 'O' && board[2] != 'O' && board[2] != 'X'){board[2] = 'X'; return 0;}
		if(board[2] == 'O' && board[1] != 'O' && board[1] != 'X'){board[1] = 'X'; return 0;}	
	}	
	if(board[2] == 'O')
	{
		if(board[1] == 'O' && board[0] != 'O' && board[0] != 'X'){board[0] = 'X'; return 0;}
		if(board[0] == 'O' && board[1] != 'O' && board[1] != 'X'){board[1] = 'X'; return 0;}
		if(board[4] == 'O' && board[6] != 'O' && board[6] != 'X'){board[6] = 'X'; return 0;}
		if(board[6] == 'O' && board[4] != 'O' && board[4] != 'X'){board[4] = 'X'; return 0;}
		if(board[5] == 'O' && board[8] != 'O' && board[8] != 'X'){board[8] = 'X'; return 0;}
		if(board[8] == 'O' && board[5] != 'O' && board[5] != 'X'){board[5] = 'X'; return 0;}	
	}	
	if(board[6] == 'O')
	{
		if(board[3] == 'O' && board[0] != 'O' && board[0] != 'X'){board[0] = 'X'; return 0;}
		if(board[0] == 'O' && board[3] != 'O' && board[3] != 'X'){board[3] = 'X'; return 0;}
		if(board[4] == 'O' && board[2] != 'O' && board[2] != 'X'){board[2] = 'X'; return 0;}
		if(board[2] == 'O' && board[4] != 'O' && board[4] != 'X'){board[4] = 'X'; return 0;}
		if(board[7] == 'O' && board[8] != 'O' && board[8] != 'X'){board[8] = 'X'; return 0;}
		if(board[8] == 'O' && board[7] != 'O' && board[7] != 'X'){board[7] = 'X'; return 0;}	
	}
	if(board[8] == 'O')
	{
		if(board[4] == 'O' && board[0] != 'O' && board[0] != 'X'){board[0] = 'X'; return 0;}
		if(board[0] == 'O' && board[4] != 'O' && board[4] != 'X'){board[4] = 'X'; return 0;}
		if(board[7] == 'O' && board[6] != 'O' && board[6] != 'X'){board[6] = 'X'; return 0;}
		if(board[6] == 'O' && board[7] != 'O' && board[7] != 'X'){board[7] = 'X'; return 0;}
		if(board[5] == 'O' && board[2] != 'O' && board[2] != 'X'){board[2] = 'X'; return 0;}
		if(board[2] == 'O' && board[5] != 'O' && board[5] != 'X'){board[5] = 'X'; return 0;}	
	}
	if(board[1] == 'O')
	{
		if(board[2] == 'O' && board[0] != 'O' && board[0] != 'X'){board[0] = 'X'; return 0;}
		if(board[0] == 'O' && board[2] != 'O' && board[2] != 'X'){board[2] = 'X'; return 0;}
		if(board[4] == 'O' && board[7] != 'O' && board[7] != 'X'){board[7] = 'X'; return 0;}
		if(board[7] == 'O' && board[4] != 'O' && board[4] != 'X'){board[4] = 'X'; return 0;}	
	}			
	if(board[3] == 'O')
	{
		if(board[0] == 'O' && board[6] != 'O' && board[6] != 'X'){board[6] = 'X'; return 0;}
		if(board[6] == 'O' && board[0] != 'O' && board[0] != 'X'){board[0] = 'X'; return 0;}
		if(board[4] == 'O' && board[5] != 'O' && board[5] != 'X'){board[5] = 'X'; return 0;}
		if(board[5] == 'O' && board[4] != 'O' && board[4] != 'X'){board[4] = 'X'; return 0;}	
	}
	if(board[5] == 'O')
	{
		if(board[2] == 'O' && board[8] != 'O' && board[8] != 'X'){board[8] = 'X'; return 0;}
		if(board[8] == 'O' && board[2] != 'O' && board[2] != 'X'){board[2] = 'X'; return 0;}
		if(board[4] == 'O' && board[3] != 'O' && board[3] != 'X'){board[3] = 'X'; return 0;}
		if(board[3] == 'O' && board[4] != 'O' && board[4] != 'X'){board[4] = 'X'; return 0;}	
	}	
	if(board[7] == 'O')
	{
		if(board[6] == 'O' && board[8] != 'O' && board[8] != 'X'){board[8] = 'X'; return 0;}
		if(board[8] == 'O' && board[6] != 'O' && board[6] != 'X'){board[6] = 'X'; return 0;}
		if(board[4] == 'O' && board[1] != 'O' && board[1] != 'X'){board[1] = 'X'; return 0;}
		if(board[1] == 'O' && board[4] != 'O' && board[4] != 'X'){board[4] = 'X'; return 0;}	
	}
	//make standard plays secure 4 first if possible for highest chance to win	
	if(board[4] != 'X' && board[4] != 'O'){board[4] = 'X'; return 0;}
	
	if(board[4] == 'X')
	{		
		if(rn = 0){if(board[1] == '1' && board[7] != 'O' && board[7] != 'X'){board[7] = 'X'; return 0;}}
		if(rn = 1){if(board[7] == '7' && board[1] != 'O' && board[1] != 'X'){board[1] = 'X'; return 0;}}
		if(rn = 0){if(board[3] == '3' && board[5] != 'O' && board[5] != 'X'){board[5] = 'X'; return 0;}}
		if(rn = 1){if(board[5] == '5' && board[3] != 'O' && board[3] != 'X'){board[3] = 'X'; return 0;}}
		if(rn = 0){if(board[0] == '0' && board[8] != 'O' && board[8] != 'X'){board[8] = 'X'; return 0;}}
		if(rn = 1){if(board[8] == '8' && board[0] != 'O' && board[0] != 'X'){board[0] = 'X'; return 0;}}
		if(rn = 0){if(board[2] == '2' && board[6] != 'O' && board[6] != 'X'){board[6] = 'X'; return 0;}}
		if(rn = 1){if(board[6] == '6' && board[2] != 'O' && board[2] != 'X'){board[2] = 'X'; return 0;}}		
	}	
	if(board[0] == 'X')
	{
		if(rn = 0){if(board[3] == '3' && board[6] != 'O' && board[3] != 'X'){board[6] = 'X'; return 0;}}
		if(rn = 1){if(board[6] == '6' && board[3] != 'O' && board[6] != 'X'){board[3] = 'X'; return 0;}}
		if(rn = 0){if(board[4] == '4' && board[8] != 'O' && board[8] != 'X'){board[8] = 'X'; return 0;}}
		if(rn = 1){if(board[8] == '8' && board[4] != 'O' && board[4] != 'X'){board[4] = 'X'; return 0;}}
		if(rn = 0){if(board[1] == '1' && board[2] != 'O' && board[2] != 'X'){board[2] = 'X'; return 0;}}
		if(rn = 1){if(board[2] == '2' && board[1] != 'O' && board[1] != 'X'){board[1] = 'X'; return 0;}}	
	}	
	if(board[2] == 'X')
	{
		if(rn = 0){if(board[1] == '1' && board[0] != 'O' && board[0] != 'X'){board[0] = 'X'; return 0;}}
		if(rn = 1){if(board[0] == '0' && board[1] != 'O' && board[1] != 'X'){board[1] = 'X'; return 0;}}
		if(rn = 0){if(board[4] == '4' && board[6] != 'O' && board[6] != 'X'){board[6] = 'X'; return 0;}}
		if(rn = 1){if(board[6] == '6' && board[4] != 'O' && board[4] != 'X'){board[4] = 'X'; return 0;}}
		if(rn = 0){if(board[5] == '5' && board[8] != 'O' && board[8] != 'X'){board[8] = 'X'; return 0;}}
		if(rn = 1){if(board[8] == '8' && board[5] != 'O' && board[5] != 'X'){board[5] = 'X'; return 0;}}	
	}	
	if(board[6] == 'X')
	{
		if(rn = 0){if(board[3] == '3' && board[0] != 'O' && board[0] != 'X'){board[0] = 'X'; return 0;}}
		if(rn = 1){if(board[0] == '0' && board[3] != 'O' && board[3] != 'X'){board[3] = 'X'; return 0;}}
		if(rn = 0){if(board[4] == '4' && board[2] != 'O' && board[2] != 'X'){board[2] = 'X'; return 0;}}
		if(rn = 1){if(board[2] == '2' && board[4] != 'O' && board[4] != 'X'){board[4] = 'X'; return 0;}}
		if(rn = 0){if(board[7] == '7' && board[8] != 'O' && board[8] != 'X'){board[8] = 'X'; return 0;}}
		if(rn = 1){if(board[8] == '8' && board[7] != 'O' && board[7] != 'X'){board[7] = 'X'; return 0;}}	
	}
	if(board[8] == 'X')
	{
		if(rn = 0){if(board[4] == '4' && board[0] != 'O' && board[0] != 'X'){board[0] = 'X'; return 0;}}
		if(rn = 1){if(board[0] == '0' && board[4] != 'O' && board[4] != 'X'){board[4] = 'X'; return 0;}}
		if(rn = 0){if(board[7] == '7' && board[6] != 'O' && board[6] != 'X'){board[6] = 'X'; return 0;}}
		if(rn = 1){if(board[6] == '6' && board[7] != 'O' && board[7] != 'X'){board[7] = 'X'; return 0;}}
		if(rn = 0){if(board[5] == '5' && board[2] != 'O' && board[2] != 'X'){board[2] = 'X'; return 0;}}
		if(rn = 1){if(board[2] == '2' && board[5] != 'O' && board[5] != 'X'){board[5] = 'X'; return 0;}}	
	}
	if(board[1] == 'X')
	{
		if(rn = 0){if(board[2] == '2' && board[0] != 'O' && board[0] != 'X'){board[0] = 'X'; return 0;}}
		if(rn = 1){if(board[0] == '0' && board[2] != 'O' && board[2] != 'X'){board[2] = 'X'; return 0;}}
		if(rn = 0){if(board[4] == '4' && board[7] != 'O' && board[7] != 'X'){board[7] = 'X'; return 0;}}
		if(rn = 1){if(board[7] == '7' && board[4] != 'O' && board[4] != 'X'){board[4] = 'X'; return 0;}}	
	}			
	if(board[3] == 'X')
	{
		if(rn = 0){if(board[0] == '0' && board[6] != 'O' && board[6] != 'X'){board[6] = 'X'; return 0;}}
		if(rn = 1){if(board[6] == '6' && board[0] != 'O' && board[0] != 'X'){board[0] = 'X'; return 0;}}
		if(rn = 0){if(board[4] == '4' && board[5] != 'O' && board[5] != 'X'){board[5] = 'X'; return 0;}}
		if(rn = 1){if(board[5] == '5' && board[4] != 'O' && board[4] != 'X'){board[4] = 'X'; return 0;}}	
	}
	if(board[5] == 'X')
	{
		if(rn = 0){if(board[2] == '2' && board[8] != 'O' && board[8] != 'X'){board[8] = 'X'; return 0;}}
		if(rn = 1){if(board[8] == '8' && board[2] != 'O' && board[2] != 'X'){board[2] = 'X'; return 0;}}
		if(rn = 0){if(board[4] == '4' && board[3] != 'O' && board[3] != 'X'){board[3] = 'X'; return 0;}}
		if(rn = 1){if(board[3] == '3' && board[4] != 'O' && board[4] != 'X'){board[4] = 'X'; return 0;}}	
	}	
	if(board[7] == 'X')
	{
		if(rn = 0){if(board[6] == '6' && board[8] != 'O' && board[8] != 'X'){board[8] = 'X'; return 0;}}
		if(rn = 1){if(board[8] == '8' && board[6] != 'O' && board[6] != 'X'){board[6] = 'X'; return 0;}}
		if(rn = 0){if(board[4] == '4' && board[1] != 'O' && board[1] != 'X'){board[1] = 'X'; return 0;}}
		if(rn = 1){if(board[1] == '1' && board[4] != 'O' && board[4] != 'X'){board[4] = 'X'; return 0;}}	
	}
	while(num < 9)
	{
		if(board[num] < 57){board[num] = 'X'; return 1;}
		num++;
	}
				
}








