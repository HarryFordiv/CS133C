#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>


int NPCturn(int);
int gamestate(char*,char*);
void NPCrecord(int,int);

char board[10][10];
char boardo[10][10];
char NPClastshot[10][10];
int ships[5];
int shipso[5];
int sunk = 0;


void  main()
{
	
	char col[2];
	char row[2];
	char d[2];
	char a,b;
	int di;

	int count = 0;
	int count1 = 0;
	int i,j;
	int rn = 0;
	int n;
	int hitDe = 0;
	bool playagain = true;	
	srand(time(0));

	while(playagain)//loop to play multiple times
	{
		ships[5] = (0,1,2,3,4);
		shipso[5] = (0,1,2,3,4);
		//set variables at the begining of each loop	
		n = 1;
		//reset board
		while(count < 10)
		{
			while(count1 < 10)
			{
				board[count][count1] = '0';
				boardo[count][count1] = '0';
				count1++;	
			}
			count1 = 0;
			count++;			
		}		
		printf("\nBoard so far:\n  0 1 2 3 4 5 6 7 8 9\n");
		for(i = 0; i < 10; i++)
		{
			for(j = 0; j < 10; j++)
			{
				if(j == 0){printf("%d ", i);}
				printf("%c ", board[i][j]);
				if(j == 9){printf("\n");}
			}
				
		}
		count = 0;
		count1 = 0;
		//set board
		printf("Place your size 5 carrier, pick a zone to start\n");
		col[0] = '\0';
		row[0] = '\0';
		printf("Pick a column 0-9: \n");
		scanf("%s" , col);
		getchar();
		while(atoi(col) < 0 || atoi(col) > 9)
		{
			col[0] = '\0';
			printf("Pick a column 0-9: \n");
			scanf("%s" , col);
			getchar();
				
		}
		printf("Pick a row 0-9: \n");
		scanf("%s" , row);
		getchar();
		while(atoi(row) < 0 || atoi(row) > 9)
		{
			row[0] = '\0';
			printf("Pick a row 0-9: \n");
			scanf("%s" , row);
			getchar();
				
		}
		while(board[atoi(row)][atoi(col)] != '0')
		{
			col[0] = '\0';
			row[0] = '\0';
			printf("Please pick an empty zone: \n");
			printf("Pick a column 0-9: \n");
			scanf("%s" , col);
			getchar();
			while(atoi(col) < 0 || atoi(col) > 9)
			{
				col[0] = '\0';
				printf("Pick a column 0-9: \n");
				scanf("%s" , col);
				getchar();
				
			}
			printf("Pick a row 0-9: \n");
			scanf("%s" , row);
			getchar();
			while(atoi(row) < 0 || atoi(row) > 9)
			{
				row[0] = '\0';
				printf("Pick a row 0-9: \n");
				scanf("%s" , row);
				getchar();
			
			}
		}
		printf("Pick a direction for it to go\n");
		while(board[atoi(row)][atoi(col)] != '1')
		{

			row[0] = '\0';
			printf("0:up 1:left 2:down 3:right:\n");
			scanf("%s" , d);
			getchar();	
			
			printf("%d\n", di);
			if(d[0] == '0')
			{
				j = 0;
				if(atoi(row) > 3)
				{
					for(i = 0; i < 4; i++)
					{
						if(board[atoi(row)+i][atoi(col)] != '0'){j++;}
					}
					if(j > 0){printf("Not enough space another ship is in the way\n");}
					if(j == 0)
					{
						for(i = 0; i < 4; i++)
						{
							board[atoi(row)+i][atoi(col)] = '1';
						}
					}
				}
				if(atoi(row) < 3)
				{
					printf("Not enough space\n");
				} 
			}
			if(d[0] == '1')
			{
				j = 0;
				if(atoi(col) > 3)
				{
					for(i = 0; i < 4; i++)
					{
						if(board[atoi(row)+i][atoi(col)] != '0'){j++;}
					}
					if(j > 0){printf("Not enough space another ship is in the way\n");}
					if(j == 0)
					{
						for(i = 0; i < 4; i++)
						{
							board[atoi(row)][atoi(col)+i] = '1';
						}
					}
				}
				if(atoi(col) < 3)
				{
					printf("Not enough space\n");
				} 
			}
			if(d[0] == '2')
			{
				j = 0;
				if(atoi(row) < 6)
				{
					for(i = 0; i < 4; i++)
					{
						if(board[atoi(row)-i][atoi(col)] != '0'){j++;}
					}
					if(j > 0){printf("Not enough space another ship is in the way\n");}
					if(j == 0)
					{
						for(i = 0; i < 4; i++)
						{
							board[atoi(row)+i][atoi(col)] = '1';
						}
					}
				}
				if(atoi(row) > 6)
				{
					printf("Not enough space\n");
				} 
			}
			if(d[0] == '3')
			{
				j = 0;
				if(atoi(col) < 6)
				{
					for(i = 0; i < 4; i++)
					{
						if(board[atoi(row)][atoi(col)-i] != '0'){j++;}
					}
					if(j > 0){printf("Not enough space another ship is in the way\n");}
					if(j == 0)
					{
						for(i = 0; i < 4; i++)
						{
							board[atoi(row)][atoi(col)-i] = '1';
						}
					}
				}
				if(atoi(col) > 6)
				{
					printf("Not enough space\n");
				} 
			}
		}

		printf("Board so far:\n  0 1 2 3 4 5 6 7 8 9\n");
		for(i = 0; i < 10; i++)
		{
			for(j = 0; j < 10; j++)
			{
				if(j == 0){printf("%d ", i);}
				printf("%c ", board[i][j]);
				if(j == 9){printf("\n");}
			}
				
		}
		printf("Place your size 4 battleship, pick a zone to start\n");
		col[0] = '\0';
		row[0] = '\0';
		printf("Pick a column 0-9: \n");
		scanf("%s" , col);
		getchar();
		while(atoi(col) < 0 || atoi(col) > 9)
		{
			col[0] = '\0';
			printf("Pick a column 0-9: \n");
			scanf("%s" , col);
			getchar();
				
		}
		printf("Pick a row 0-9: \n");
		scanf("%s" , row);
		getchar();
		while(atoi(row) < 0 || atoi(row) > 9)
		{
			row[0] = '\0';
			printf("Pick a row 0-9: \n");
			scanf("%s" , row);
			getchar();
				
		}
		while(board[atoi(row)][atoi(col)] != '0')
		{
			col[0] = '\0';
			row[0] = '\0';
			printf("Please pick an empty zone: \n");
			printf("Pick a column 0-9: \n");
			scanf("%s" , col);
			getchar();
			while(atoi(col) < 0 || atoi(col) > 9)
			{
				col[0] = '\0';
				printf("Pick a column 0-9: \n");
				scanf("%s" , col);
				getchar();
				
			}
			printf("Pick a row 0-9: \n");
			scanf("%s" , row);
			getchar();
			while(atoi(row) < 0 || atoi(row) > 9)
			{
				row[0] = '\0';
				printf("Pick a row 0-9: \n");
				scanf("%s" , row);
				getchar();
			
			}
		}
		printf("Pick a direction for it to go\n");
		while(board[atoi(row)][atoi(col)] != '2')
		{
			
			row[0] = '\0';
			printf("0:up 1:left 2:down 3:right:\n");
			scanf("%s" , d);
			getchar();	
			
			if(d[0] == '0')
			{
				j = 0;
				if(atoi(row) > 2)
				{
					for(i = 0; i < 3; i++)
					{
						if(board[atoi(row)+i][atoi(col)] != '0'){j++;}
					}
					if(j > 0){printf("Not enough space another ship is in the way\n");}
					if(j == 0)
					{
						for(i = 0; i < 3; i++)
						{
							board[atoi(row)+i][atoi(col)] = '2';
						}
					}
				}
				if(atoi(row) < 2)
				{
					printf("Not enough space\n");
				} 
			}
			if(d[0] == '1')
			{
				j = 0;
				if(atoi(col) > 2)
				{
					for(i = 0; i < 3; i++)
					{
						if(board[atoi(row)+i][atoi(col)] != '0'){j++;}
					}
					if(j > 0){printf("Not enough space another ship is in the way\n");}
					if(j == 0)
					{
						for(i = 0; i < 3; i++)
						{
							board[atoi(row)][atoi(col)+i] = '2';
						}
					}
				}
				if(atoi(col) < 2)
				{
					printf("Not enough space\n");
				} 
			}
			if(d[0] == '2')
			{
				j = 0;
				if(atoi(row) < 7)
				{
					for(i = 0; i < 3; i++)
					{
						if(board[atoi(row)-i][atoi(col)] != '0'){j++;}
					}
					if(j > 0){printf("Not enough space another ship is in the way\n");}
					if(j == 0)
					{
						for(i = 0; i < 3; i++)
						{
							board[atoi(row)+i][atoi(col)] = '2';
						}
					}
				}
				if(atoi(row) > 7)
				{
					printf("Not enough space\n");
				} 
			}
			if(d[0] == '3')
			{
				j = 0;
				if(atoi(col) < 7)
				{
					for(i = 0; i < 3; i++)
					{
						if(board[atoi(row)][atoi(col)-i] != '0'){j++;}
					}
					if(j > 0){printf("Not enough space another ship is in the way\n");}
					if(j == 0)
					{
						for(i = 0; i < 3; i++)
						{
							board[atoi(row)][atoi(col)-i] = '2';
						}
					}
				}
				if(atoi(col) > 7)
				{
					printf("Not enough space\n");
				} 
			}
		}

		printf("Board so far:\n  0 1 2 3 4 5 6 7 8 9\n");
		for(i = 0; i < 10; i++)
		{
			for(j = 0; j < 10; j++)
			{
				if(j == 0){printf("%d ", i);}
				printf("%c ", board[i][j]);
				if(j == 9){printf("\n");}
			}
				
		}
		printf("Place your size 3 destroyer, pick a zone to start\n");
		col[0] = '\0';
		row[0] = '\0';
		printf("Pick a column 0-9: \n");
		scanf("%s" , col);
		getchar();
		while(atoi(col) < 0 || atoi(col) > 9)
		{
			col[0] = '\0';
			printf("Pick a column 0-9: \n");
			scanf("%s" , col);
			getchar();
				
		}
		printf("Pick a row 0-9: \n");
		scanf("%s" , row);
		getchar();
		while(atoi(row) < 0 || atoi(row) > 9)
		{
			row[0] = '\0';
			printf("Pick a row 0-9: \n");
			scanf("%s" , row);
			getchar();
				
		}
		while(board[atoi(row)][atoi(col)] != '0')
		{
			col[0] = '\0';
			row[0] = '\0';
			printf("Please pick an empty zone: \n");
			printf("Pick a column 0-9: \n");
			scanf("%s" , col);
			getchar();
			while(atoi(col) < 0 || atoi(col) > 9)
			{
				col[0] = '\0';
				printf("Pick a column 0-9: \n");
				scanf("%s" , col);
				getchar();
				
			}
			printf("Pick a row 0-9: \n");
			scanf("%s" , row);
			getchar();
			while(atoi(row) < 0 || atoi(row) > 9)
			{
				row[0] = '\0';
				printf("Pick a row 0-9: \n");
				scanf("%s" , row);
				getchar();
			
			}
		}
		printf("Pick a direction for it to go\n");
		while(board[atoi(row)][atoi(col)] != '3')
		{
			
			row[0] = '\0';
			printf("0:up 1:left 2:down 3:right:\n");
			scanf("%s" , d);
			getchar();	
						
			if(d[0] == '0')
			{
				j = 0;
				if(atoi(row) > 1)
				{
					for(i = 0; i < 2; i++)
					{
						if(board[atoi(row)+i][atoi(col)] != '0'){j++;}
					}
					if(j > 0){printf("Not enough space another ship is in the way\n");}
					if(j == 0)
					{
						for(i = 0; i < 2; i++)
						{
							board[atoi(row)+i][atoi(col)] = '3';
						}
					}
				}
				if(atoi(row) < 1)
				{
					printf("Not enough space\n");
				} 
			}
			if(d[0] == '1')
			{
				j = 0;
				if(atoi(col) > 1)
				{
					for(i = 0; i < 2; i++)
					{
						if(board[atoi(row)+i][atoi(col)] != '0'){j++;}
					}
					if(j > 0){printf("Not enough space another ship is in the way\n");}
					if(j == 0)
					{
						for(i = 0; i < 2; i++)
						{
							board[atoi(row)][atoi(col)+i] = '3';
						}
					}
				}
				if(atoi(col) < 1)
				{
					printf("Not enough space\n");
				} 
			}
			if(d[0] == '2')
			{
				j = 0;
				if(atoi(row) < 8)
				{
					for(i = 0; i < 2; i++)
					{
						if(board[atoi(row)-i][atoi(col)] != '0'){j++;}
					}
					if(j > 0){printf("Not enough space another ship is in the way\n");}
					if(j == 0)
					{
						for(i = 0; i < 2; i++)
						{
							board[atoi(row)+i][atoi(col)] = '3';
						}
					}
				}
				if(atoi(row) > 8)
				{
					printf("Not enough space\n");
				} 
			}
			if(d[0] == '3')
			{
				j = 0;
				if(atoi(col) < 8)
				{
					for(i = 0; i < 2; i++)
					{
						if(board[atoi(row)][atoi(col)-i] != '0'){j++;}
					}
					if(j > 0){printf("Not enough space another ship is in the way\n");}
					if(j == 0)
					{
						for(i = 0; i < 2; i++)
						{
							board[atoi(row)][atoi(col)-i] = '3';
						}
					}
				}
				if(atoi(col) > 8)
				{
					printf("Not enough space\n");
				} 
			}
		}

		printf("Board so far:\n  0 1 2 3 4 5 6 7 8 9\n");
		for(i = 0; i < 10; i++)
		{
			for(j = 0; j < 10; j++)
			{
				if(j == 0){printf("%d ", i);}
				printf("%c ", board[i][j]);
				if(j == 9){printf("\n");}
			}
				
		}
		printf("Place your size 3 submarine, pick a zone to start\n");
		col[0] = '\0';
		row[0] = '\0';
		printf("Pick a column 0-9: \n");
		scanf("%s" , col);
		getchar();
		while(atoi(col) < 0 || atoi(col) > 9)
		{
			col[0] = '\0';
			printf("Pick a column 0-9: \n");
			scanf("%s" , col);
			getchar();
				
		}
		printf("Pick a row 0-9: \n");
		scanf("%s" , row);
		getchar();
		while(atoi(row) < 0 || atoi(row) > 9)
		{
			row[0] = '\0';
			printf("Pick a row 0-9: \n");
			scanf("%s" , row);
			getchar();
				
		}
		while(board[atoi(row)][atoi(col)] != '0')
		{
			col[0] = '\0';
			row[0] = '\0';
			printf("Please pick an empty zone: \n");
			printf("Pick a column 0-9: \n");
			scanf("%s" , col);
			getchar();
			while(atoi(col) < 0 || atoi(col) > 9)
			{
				col[0] = '\0';
				printf("Pick a column 0-9: \n");
				scanf("%s" , col);
				getchar();
				
			}
			printf("Pick a row 0-9: \n");
			scanf("%s" , row);
			getchar();
			while(atoi(row) < 0 || atoi(row) > 9)
			{
				row[0] = '\0';
				printf("Pick a row 0-9: \n");
				scanf("%s" , row);
				getchar();
			
			}
		}
		printf("Pick a direction for it to go\n");
		while(board[atoi(row)][atoi(col)] != '4')
		{

			row[0] = '\0';
			printf("0:up 1:left 2:down 3:right:\n");
			scanf("%s" , d);
			getchar();	

			if(d[0] == '0')
			{
				j = 0;
				if(atoi(row) > 1)
				{
					for(i = 0; i < 2; i++)
					{
						if(board[atoi(row)+i][atoi(col)] != '0'){j++;}
					}
					if(j > 0){printf("Not enough space another ship is in the way\n");}
					if(j == 0)
					{
						for(i = 0; i < 2; i++)
						{
							board[atoi(row)+i][atoi(col)] = '4';
						}
					}
				}
				if(atoi(row) < 1)
				{
					printf("Not enough space\n");
				} 
			}
			if(d[0] == '1')
			{
				j = 0;
				if(atoi(col) > 1)
				{
					for(i = 0; i < 2; i++)
					{
						if(board[atoi(row)+i][atoi(col)] != '0'){j++;}
					}
					if(j > 0){printf("Not enough space another ship is in the way\n");}
					if(j == 0)
					{
						for(i = 0; i < 2; i++)
						{
							board[atoi(row)][atoi(col)+i] = '4';
						}
					}
				}
				if(atoi(col) < 1)
				{
					printf("Not enough space\n");
				} 
			}
			if(d[0] == '2')
			{
				j = 0;
				if(atoi(row) < 8)
				{
					for(i = 0; i < 2; i++)
					{
						if(board[atoi(row)-i][atoi(col)] != '0'){j++;}
					}
					if(j > 0){printf("Not enough space another ship is in the way\n");}
					if(j == 0)
					{
						for(i = 0; i < 2; i++)
						{
							board[atoi(row)+i][atoi(col)] = '4';
						}
					}
				}
				if(atoi(row) > 8)
				{
					printf("Not enough space\n");
				} 
			}
			if(d[0] == '3')
			{
				j = 0;
				if(atoi(col) < 8)
				{
					for(i = 0; i < 2; i++)
					{
						if(board[atoi(row)][atoi(col)-i] != '0'){j++;}
					}
					if(j > 0){printf("Not enough space another ship is in the way\n");}
					if(j == 0)
					{
						for(i = 0; i < 2; i++)
						{
							board[atoi(row)][atoi(col)-i] = '4';
						}
					}
				}
				if(atoi(col) > 8)
				{
					printf("Not enough space\n");
				} 
			}
		}

		printf("Board so far:\n  0 1 2 3 4 5 6 7 8 9\n");
		for(i = 0; i < 10; i++)
		{
			for(j = 0; j < 10; j++)
			{
				if(j == 0){printf("%d ", i);}
				printf("%c ", board[i][j]);
				if(j == 9){printf("\n");}
			}
				
		}
		printf("Place your size 2 patrol boat, pick a zone to start\n");
		col[0] = '\0';
		row[0] = '\0';
		printf("Pick a column 0-9: \n");
		scanf("%s" , col);
		getchar();
		while(atoi(col) < 0 || atoi(col) > 9)
		{
			col[0] = '\0';
			printf("Pick a column 0-9: \n");
			scanf("%s" , col);
			getchar();
				
		}
		printf("Pick a row 0-9: \n");
		scanf("%s" , row);
		getchar();
		while(atoi(row) < 0 || atoi(row) > 9)
		{
			row[0] = '\0';
			printf("Pick a row 0-9: \n");
			scanf("%s" , row);
			getchar();
				
		}
		while(board[atoi(row)][atoi(col)] != '0')
		{
			col[0] = '\0';
			row[0] = '\0';
			printf("Please pick an empty zone: \n");
			printf("Pick a column 0-9: \n");
			scanf("%s" , col);
			getchar();
			while(atoi(col) < 0 || atoi(col) > 9)
			{
				col[0] = '\0';
				printf("Pick a column 0-9: \n");
				scanf("%s" , col);
				getchar();
				
			}
			printf("Pick a row 0-9: \n");
			scanf("%s" , row);
			getchar();
			while(atoi(row) < 0 || atoi(row) > 9)
			{
				row[0] = '\0';
				printf("Pick a row 0-9: \n");
				scanf("%s" , row);
				getchar();
			
			}
		}
		printf("Pick a direction for it to go\n");
		while(board[atoi(row)][atoi(col)] != '5')
		{
			
			row[0] = '\0';
			printf("0:up 1:left 2:down 3:right:\n");
			scanf("%s" , d);
			getchar();	
			
			if(d[0] == '0')
			{
				j = 0;
				if(atoi(row) > 0)
				{
					for(i = 0; i < 1; i++)
					{
						if(board[atoi(row)+i][atoi(col)] != '0'){j++;}
					}
					if(j > 0){printf("Not enough space another ship is in the way\n");}
					if(j == 0)
					{
						for(i = 0; i < 1; i++)
						{
							board[atoi(row)+i][atoi(col)] = '5';
						}
					}
				}
				if(atoi(row) < 0)
				{
					printf("Not enough space\n");
				} 
			}
			if(d[0] == '1')
			{
				j = 0;
				if(atoi(col) > 0)
				{
					for(i = 0; i < 1; i++)
					{
						if(board[atoi(row)+i][atoi(col)] != '0'){j++;}
					}
					if(j > 0){printf("Not enough space another ship is in the way\n");}
					if(j == 0)
					{
						for(i = 0; i < 1; i++)
						{
							board[atoi(row)][atoi(col)+i] = '5';
						}
					}
				}
				if(atoi(col) < 0)
				{
					printf("Not enough space\n");
				} 
			}
			if(d[0] == '2')
			{
				j = 0;
				if(atoi(row) < 9)
				{
					for(i = 0; i < 1; i++)
					{
						if(board[atoi(row)-i][atoi(col)] != '0'){j++;}
					}
					if(j > 0){printf("Not enough space another ship is in the way\n");}
					if(j == 0)
					{
						for(i = 0; i < 1; i++)
						{
							board[atoi(row)+i][atoi(col)] = '5';
						}
					}
				}
				if(atoi(row) > 9)
				{
					printf("Not enough space\n");
				} 
			}
			if(d[0] == '3')
			{
				j = 0;
				if(atoi(col) < 9)
				{
					for(i = 0; i < 1; i++)
					{
						if(board[atoi(row)][atoi(col)-i] != '0'){j++;}
					}
					if(j > 0){printf("Not enough space another ship is in the way\n");}
					if(j == 0)
					{
						for(i = 0; i < 1; i++)
						{
							board[atoi(row)][atoi(col)-i] = '5';
						}
					}
				}
				if(atoi(col) > 9)
				{
					printf("Not enough space\n");
				} 
			}
		}

		//set NPC board
		while(boardo[atoi(row)][atoi(col)] != '0')
		{
			a = rand()%10;
			b = rand()%10;
			row[0] = a;
			col[0] = b;
		}
		
		while(boardo[atoi(row)][atoi(col)] != '1')
		{
			
			di = rand()%4;
			d[0] = di;
			if(d[0] == '0')
			{
				j = 0;
				if(atoi(row) > 3)
				{
					for(i = 0; i < 4; i++)
					{
						if(boardo[atoi(row)+i][atoi(col)] != '0'){j++;}
					}
					if(j == 0)
					{
						for(i = 0; i < 4; i++)
						{
							boardo[atoi(row)+i][atoi(col)] = '1';
						}
					}
				}
			}
			if(d[0] == '1')
			{
				j = 0;
				if(atoi(col) > 3)
				{
					for(i = 0; i < 4; i++)
					{
						if(boardo[atoi(row)+i][atoi(col)] != '0'){j++;}
					}
					if(j == 0)
					{
						for(i = 0; i < 4; i++)
						{
							boardo[atoi(row)][atoi(col)+i] = '1';
						}
					}
				}

			}
			if(d[0] == '2')
			{
				j = 0;
				if(atoi(row) < 6)
				{
					for(i = 0; i < 4; i++)
					{
						if(boardo[atoi(row)-i][atoi(col)] != '0'){j++;}
					}
					if(j == 0)
					{
						for(i = 0; i < 4; i++)
						{
							boardo[atoi(row)+i][atoi(col)] = '1';
						}
					}
				}

			}
			if(d[0] == '3')
			{
				j = 0;
				if(atoi(col) < 6)
				{
					for(i = 0; i < 4; i++)
					{
						if(boardo[atoi(row)][atoi(col)-i] != '0'){j++;}
					}
					if(j == 0)
					{
						for(i = 0; i < 4; i++)
						{
							boardo[atoi(row)][atoi(col)-i] = '1';
						}
					}
				}

			}
		}

		
		while(boardo[atoi(row)][atoi(col)] != '0')
		{
			a = rand()%10;
			b = rand()%10;
			row[0] = a;
			col[0] = b;
		}
		
		while(boardo[atoi(row)][atoi(col)] != '2')
		{
			di = rand()%4;
			d[0] = di;
			if(d[0] == '0')
			{
				j = 0;
				if(atoi(row) > 2)
				{
					for(i = 0; i < 3; i++)
					{
						if(boardo[atoi(row)+i][atoi(col)] != '0'){j++;}
					}
					if(j == 0)
					{
						for(i = 0; i < 3; i++)
						{
							boardo[atoi(row)+i][atoi(col)] = '2';
						}
					}
				}

			}
			if(d[0] == '1')
			{
				j = 0;
				if(atoi(col) > 2)
				{
					for(i = 0; i < 3; i++)
					{
						if(boardo[atoi(row)+i][atoi(col)] != '0'){j++;}
					}
					if(j == 0)
					{
						for(i = 0; i < 3; i++)
						{
							boardo[atoi(row)][atoi(col)+i] = '2';
						}
					}
				}

			}
			if(d[0] == '2')
			{
				j = 0;
				if(atoi(row) < 7)
				{
					for(i = 0; i < 3; i++)
					{
						if(boardo[atoi(row)-i][atoi(col)] != '0'){j++;}
					}
					if(j == 0)
					{
						for(i = 0; i < 3; i++)
						{
							boardo[atoi(row)+i][atoi(col)] = '2';
						}
					}
				}

			}
			if(d[0] == '3')
			{
				j = 0;
				if(atoi(col) < 7)
				{
					for(i = 0; i < 3; i++)
					{
						if(boardo[atoi(row)][atoi(col)-i] != '0'){j++;}
					}
					if(j == 0)
					{
						for(i = 0; i < 3; i++)
						{
							boardo[atoi(row)][atoi(col)-i] = '2';
						}
					}
				}
			}
		}
		while(boardo[atoi(row)][atoi(col)] != '0')
		{
			a = rand()%10;
			b = rand()%10;
			row[0] = a;
			col[0] = b;
		}
		
		while(boardo[atoi(row)][atoi(col)] != '3')
		{
			di = rand()%4;
			d[0] = di;
			if(d[0] == '0')
			{
				j = 0;
				if(atoi(row) > 1)
				{
					for(i = 0; i < 2; i++)
					{
						if(boardo[atoi(row)+i][atoi(col)] != '0'){j++;}
					}
					if(j == 0)
					{
						for(i = 0; i < 2; i++)
						{
							boardo[atoi(row)+i][atoi(col)] = '3';
						}
					}
				}
			}
			if(d[0] == '1')
			{
				j = 0;
				if(atoi(col) > 1)
				{
					for(i = 0; i < 2; i++)
					{
						if(boardo[atoi(row)+i][atoi(col)] != '0'){j++;}
					}
					if(j == 0)
					{
						for(i = 0; i < 2; i++)
						{
							boardo[atoi(row)][atoi(col)+i] = '3';
						}
					}
				}
			}
			if(d[0] == '2')
			{
				j = 0;
				if(atoi(row) < 8)
				{
					for(i = 0; i < 2; i++)
					{
						if(boardo[atoi(row)-i][atoi(col)] != '0'){j++;}
					}
					if(j == 0)
					{
						for(i = 0; i < 2; i++)
						{
							boardo[atoi(row)+i][atoi(col)] = '3';
						}
					}
				}
			}
			if(d[0] == '3')
			{
				j = 0;
				if(atoi(col) < 8)
				{
					for(i = 0; i < 2; i++)
					{
						if(boardo[atoi(row)][atoi(col)-i] != '0'){j++;}
					}
					if(j == 0)
					{
						for(i = 0; i < 2; i++)
						{
							boardo[atoi(row)][atoi(col)-i] = '3';
						}
					}
				}
			}
		}
		while(boardo[atoi(row)][atoi(col)] != '0')
		{
			a = rand()%10;
			b = rand()%10;
			row[0] = a;
			col[0] = b;
		}
		
		while(boardo[atoi(row)][atoi(col)] != '4')
		{
			di = rand()%4;
			d[0] = di;
			if(d[0] == '0')
			{
				j = 0;
				if(atoi(row) > 1)
				{
					for(i = 0; i < 2; i++)
					{
						if(boardo[atoi(row)+i][atoi(col)] != '0'){j++;}
					}
					if(j == 0)
					{
						for(i = 0; i < 2; i++)
						{
							boardo[atoi(row)+i][atoi(col)] = '4';
						}
					}
				}

			}
			if(d[0] == '1')
			{
				j = 0;
				if(atoi(col) > 1)
				{
					for(i = 0; i < 2; i++)
					{
						if(boardo[atoi(row)+i][atoi(col)] != '0'){j++;}
					}
					if(j == 0)
					{
						for(i = 0; i < 2; i++)
						{
							boardo[atoi(row)][atoi(col)+i] = '4';
						}
					}
				}
			}
			if(d[0] == '2')
			{
				j = 0;
				if(atoi(row) < 8)
				{
					for(i = 0; i < 2; i++)
					{
						if(boardo[atoi(row)-i][atoi(col)] != '0'){j++;}
					}
					if(j == 0)
					{
						for(i = 0; i < 2; i++)
						{
							boardo[atoi(row)+i][atoi(col)] = '4';
						}
					}
				} 
			}
			if(d[0] == '3')
			{
				j = 0;
				if(atoi(col) < 8)
				{
					for(i = 0; i < 2; i++)
					{
						if(boardo[atoi(row)][atoi(col)-i] != '0'){j++;}
					}
					if(j == 0)
					{
						for(i = 0; i < 2; i++)
						{
							boardo[atoi(row)][atoi(col)-i] = '4';
						}
					}
				}
 
			}
		}
		while(boardo[atoi(row)][atoi(col)] != '0')
		{
			a = rand()%10;
			b = rand()%10;
			row[0] = a;
			col[0] = b;
		}
		
		while(boardo[atoi(row)][atoi(col)] != '5')
		{
			di = rand()%4;
			d[0] = di;
			if(d[0] == '0')
			{
				j = 0;
				if(atoi(row) > 0)
				{
					for(i = 0; i < 1; i++)
					{
						if(boardo[atoi(row)+i][atoi(col)] != '0'){j++;}
					}
					if(j == 0)
					{
						for(i = 0; i < 1; i++)
						{
							boardo[atoi(row)+i][atoi(col)] = '5';
						}
					}
				}

			}
			if(d[0] == '1')
			{
				j = 0;
				if(atoi(col) > 0)
				{
					for(i = 0; i < 1; i++)
					{
						if(boardo[atoi(row)+i][atoi(col)] != '0'){j++;}
					}
					if(j == 0)
					{
						for(i = 0; i < 1; i++)
						{
							boardo[atoi(row)][atoi(col)+i] = '5';
						}
					}
				}
			}
			if(d[0] == '2')
			{
				j = 0;
				if(atoi(row) < 9)
				{
					for(i = 0; i < 1; i++)
					{
						if(boardo[atoi(row)-i][atoi(col)] != '0'){j++;}
					}
					if(j == 0)
					{
						for(i = 0; i < 1; i++)
						{
							boardo[atoi(row)+i][atoi(col)] = '5';
						}
					}
				}
			}
			if(d[0] == '3')
			{
				j = 0;
				if(atoi(col) < 9)
				{
					for(i = 0; i < 1; i++)
					{
						if(boardo[atoi(row)][atoi(col)-i] != '0'){j++;}
					}
					if(j == 0)
					{
						for(i = 0; i < 1; i++)
						{
							boardo[atoi(row)][atoi(col)-i] = '5';
						}
					}
				}
			}
		}

		
				
		
		//loop
		while(n == 1)
		{
			
			hitDe = NPCturn(hitDe);

			//interact with user	
			printf("Board so far:\n  0 1 2 3 4 5 6 7 8 9\n");
			for(i = 0; i < 10; i++)
			{
				for(j = 0; j < 10; j++)
				{
					if(j == 0){printf("%d ", i);}
					printf("%c ", board[i][j]);
					if(j == 9){printf("\n");}
				}
				
			}
			

			n = gamestate(&board[0][0], &boardo[0][0]);
			if(n != 1){break;}
			//tell NPC to change targets if it sinks a ship
			if(sunk != 0){hitDe = 0;sunk = 0;}

			col[0] = '\0';
			row[0] = '\0';
			printf("Pick a column 0-9: \n");
			scanf("%s" , col);
			getchar();
			while(atoi(col) < 0 || atoi(col) > 9)
			{
				col[0] = '\0';
				printf("Pick a column 0-9: \n");
				scanf("%s" , col);
				getchar();
				
			}
			printf("Pick a row 0-9: \n");
			scanf("%s" , row);
			getchar();
			while(atoi(row) < 0 || atoi(row) > 9)
			{
				row[0] = '\0';
				printf("Pick a row 0-9: \n");
				scanf("%s" , row);
				getchar();
				
			}
			while(boardo[atoi(row)][atoi(col)] == 'O' || boardo[atoi(row)][atoi(col)] == 'X')
			{
				col[0] = '\0';
				row[0] = '\0';
				printf("Please pick an empty zone: \n");
				printf("Pick a column 0-9: \n");
				scanf("%s" , col);
				getchar();
				while(atoi(col) < 0 || atoi(col) > 9)
				{
					col[0] = '\0';
					printf("Pick a column 0-9: \n");
					scanf("%s" , col);
					getchar();
				
				}
				printf("Pick a row 0-9: \n");
				scanf("%s" , row);
				getchar();
				while(atoi(row) < 0 || atoi(row) > 9)
				{
					row[0] = '\0';
					printf("Pick a row 0-9: \n");
					scanf("%s" , row);
					getchar();
				
				}
			}
			if(boardo[atoi(row)][atoi(col)] == '0'){boardo[atoi(row)][atoi(col)] = 'O';}
			else{boardo[atoi(row)][atoi(col)] = 'X';}
			n = gamestate(&board[0][0], &boardo[0][0]);
			
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
	}
}	



int gamestate(char* in,char* ino)
{
	int s,i,j,n = 0;
	char a;
	char stateo[10][10];
	memcpy(stateo, ino,sizeof(char*) * 10);
	char state[10][10];
	memcpy(state, in,sizeof(char*) * 10);
	//check if NPC has won
	for(s = 0; s < 5; s++)
	{
		for(i = 0; i < 10; i++)
		{
			for(j = 0; j < 10; j++)
			{
				if(ships[s] == 7)
				{
					a = ships[s];
					if(state[i][j] == a)
					{
						n++;
					}
				}
				if(ships[s] == 7){n = 1;}
			}	
		}
		if(n == 0)
		{
			sunk = 1;
			ships[s] = 7;
			return 0;
		}
		n = 0;	
	}

	//check if player has won

	for(s = 0; s < 5; s++)
	{
		for(i = 0; i < 10; i++)
		{
			for(j = 0; j < 10; j++)
			{
				if(shipso[s] == 7)
				{
					a = ships[s];
					if(stateo[i][j] == a)
					{
						n++;
					}
				}
				if(shipso[s] == 7){n = 1;}
			}	
		}
		if(n == 0)
		{
			sunk = 1;
			shipso[s] = 7;
			return -1;
		}
		n = 0;	
	}

	
	return 1;
}


int NPCturn(int hitDe)
{
	int i,j;
	int n = 1;
	int rn = 0;
	int rn1 = 0;
	int tn1 = 0;
	srand(time(0));	
	//find last hit location
	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 10; j++)
		{
			if(NPClastshot[i][j] == 'X'){break;}
		}
		if(NPClastshot[i][j] == 'X'){break;}			
	}
	//if multiple shots landed in a row
	if(hitDe == 3)
	{
		while(true)
		{
			rn = 0;
			rn = rand()%2;
			n = 1;
			if(rn == 0)
			{
				
				if(board[i][j+1] != 'O' && board[i][j+1] != 'X' && j < 9)
				{
					if(board[i][j+1] == '0'){board[i][j+1] = 'O';return 3;}
					board[i][j+1] = 'X';
					NPCrecord(i,j+1);
					return 3;
				}
				while(board[i][j+n] == 'X')
				{
					n++;
					if(board[i][j+n] != 'O' && board[i][j+n] != 'X' && j +(n-1) < 9)
					{
						if(board[i][j+n] == '0'){board[i][j+n] = 'O';return 3;}
						board[i][j+n] = 'X';
						NPCrecord(i,j+n);
						return 3;
					}
				}
			}
			if(rn == 1)
			{
				
				if(board[i][j-1] != 'O' && board[i][j-1] != 'X' && j  > 0)
				{
					if(board[i][j-1] == '0'){board[i][j-1] = 'O';return 3;}
					board[i][j-1] = 'X';
					NPCrecord(i,j-1);
					return 3;
				}
				while(board[i][j-n] == 'X')
				{
					n++;
					if(board[i][j-n] != 'O' && board[i][j-n] != 'X' && j-(n-1) > 0)
					{
						if(board[i][j-n] == '0'){board[i][j-n] = 'O';return 3;}
						board[i][j-n] = 'X';
						NPCrecord(i,j-n);
						return 3;
					}
				}
			}
		}
	}
	//if multiple shots landed in a column
	if(hitDe == 2)
	{
		while(true)
		{
			rn = 0;
			rn = rand()%2;
			n = 1;
			if(rn == 0)
			{
				
				if(board[i+1][j] != 'O' && board[i+1][j] != 'X' && i < 9)
				{
					if(board[i+1][j] == '0'){board[i+1][j] = 'O';return 2;}
					board[i+1][j] = 'X';
					NPCrecord(i+1,j);
					return 2;
				}
				while(board[i+n][j] == 'X')
				{
					n++;
					if(board[i+n][j] != 'O' && board[i+n][j] != 'X' && i +(n-1) < 9)
					{
						if(board[i+n][j] == '0'){board[i+n][j] = 'O';return 2;}
						board[i+n][j] = 'X';
						NPCrecord(i+n,j);
						return 2;
					}
				}
			}
			if(rn == 1)
			{
				
				if(board[i-1][j] != 'O' && board[i-1][j] != 'X' && i > 0)
				{
					if(board[i-1][j] == '0'){board[i-1][j] = 'O';return 2;}
					board[i-1][j] = 'X';
					NPCrecord(i-1,j);
					return 2;
				}
				while(board[i-n][j] == 'X')
				{
					n++;
					if(board[i-n][j] != 'O' && board[i-n][j] != 'X' && i-(n-1) > 0)
					{
						if(board[i-n][j] == '0'){board[i-n][j] = 'O';return 2;}
						board[i-n][j] = 'X';
						NPCrecord(i-n,j);
						return 2;
					}
				}
			}
		}	
	}
	//if last shot hit
	if(hitDe == 1)
	{
		while(true)
		{
			//pick one of four directions to shoot
			rn = 0;
			rn = rand()%4;
			if(rn == 0)
			{
				if(board[i-1][j] != 'O' && board[i-1][j] != 'X' && i > 0)
				{
					if(board[i-1][j] == '0'){board[i-1][j] = 'O';return 1;}
					board[i-1][j] = 'X';
					NPCrecord(i-1,j);
					return 2;
				}
			}
			if(rn == 1)
			{
				if(board[i][j-1] != 'O' && board[i][j-1] != 'X' && j > 0)
				{
					if(board[i][j-1] == '0'){board[i][j-1] = 'O';return 1;}
					board[i][j-1] = 'X';
					NPCrecord(i,j-1);
					return 3;
				}
			}
			if(rn == 2)
			{
				if(board[i+1][j] != 'O' && board[i+1][j] != 'X' && i < 9)
				{
					if(board[i+1][j] == '0'){board[i+1][j] = 'O';return 1;}
					board[i+1][j] = 'X';
					NPCrecord((i+1),j);
					return 2;
				}
			}
			if(rn == 3)
			{
				if(board[i][j+1] != 'O' && board[i][j+1] != 'X' && j < 9)
				{
					if(board[i][j+1] == '0'){board[i][j+1] = 'O';return 1;}
					board[i][j+1] = 'X';
					NPCrecord((i),j+1);
					return 3;
				}
			}
		}
	}
	//if last shot missed or sank a ship
	if(hitDe == 0)
	{
		while(true)
		{
			rn = 0;
			rn1 = 0;
			rn = rand()%10;
			rn1 = rand()%10;
			if(board[rn][rn1] != 'O' && board[rn][rn1] != 'X')
			{
				if(board[rn][rn1] == '0'){board[rn][rn1] = 'O';return 0;}
				board[rn][rn1] = 'X';
				NPCrecord(rn,rn1);
				return 1;
			}
		}
	}
}


void NPCrecord(int i, int j)
{
	int count = 0;
	int count1 = 0;
	while(count < 10)
	{
		while(count1 < 10)
		{
			NPClastshot[count][count1] = '0';
			count1++;	
		}
		count1 = 0;
		count++;			
	}		
	NPClastshot[i][j] = 'X';
}





