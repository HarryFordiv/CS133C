/*
A program that lets a player vs the computer in a guess a word game.
Initalize variables and have the computer come up with a random number 
and then draw from a word bank text file using that number, 
then have the computer give the length of the word and ask for an input.
Record the input and fill in the blanks or if no matching letter minus the user one guess.
After the user is out of guesses or guesses correctly allow the user to play again
and reset variables.  
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>

int getword(int);
char word[10];

void  main()
{
	//initalize variables

	char wordBlanks[10];
	char letter[2];
	char var1[2];

	int error = 1;
	int comp;
	int count;
	int rn = 0;
	int guessnum;
	bool playagain = true;	

	while(playagain)//loop to play multiple times
	{
		//set variables at the begining of each loop
		srand(time(0));	
		rn = rand()%9;	
		count = 0; 
		guessnum = 7;
		error = getword(rn);
		

		//fill	wordBlanks  		
		while(word[count] != '\0')
		{
			wordBlanks[count] = '_';
			count++;
		}
		if(word[count] == '\0')
		{
			wordBlanks[count] = '\0';
			count = 0;
		}
		//loop while the user has guesses remaning
		while(guessnum > 0)
		{
			comp = 0;
			count = 0;
			//interact with user	
			printf("\nWord so far: %s", wordBlanks);
			letter[0] = '\0';
			printf("\nGuess a letter from a to z: ");
			scanf("%c" , letter);
			getchar();

	//loop through word to see if it contains letter
			while(word[count] != '\0')
			{
				if(word[count] == letter[0])
				{
					wordBlanks[count] = letter[0];
				}
				if(word[count] == (letter[0]+32))
				{
					wordBlanks[count] = (letter[0]+32);
				}
				count++;
			}
			count = 0;
			while(word[count] != '\0')
			{
				if(word[count] != wordBlanks[count])
				{
					
					comp++;
				}
				count++;
			}
			if(comp == 0)
			{
				printf("\nCongratulations %s was the word!\n", word);
				guessnum = 0;
			}	
			
			//increment remaning guesses
			guessnum--;
		}
		//tell the user if they lost 
		//then give option to play again
		if(guessnum == 0)
		{
			printf("\nGame over %s was the right word!\n", word);
			printf("\nType 1 to play again, or anything else to exit\n");
			scanf("%s", var1);
			getchar();
			if(atoi(var1) == 1)
			{
				playagain = true;
			}
			else
			{
				playagain = false;
			}
		}
		//tell user if they won and give option to play again
		if(guessnum == -1)
		{
			printf("\nType 1 to play again, or anything else to exit\n");
			scanf("%s", var1);
			getchar();
			if(atoi(var1) == 1)
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

int getword(int num)
{


	char * filename = "Wordbank.txt";
	FILE * fp = fopen(filename, "r");
	char c[2];
	int count = 0;
	if(fp == NULL) return 0;
	c[1] = '\0'; 
	while((c[0] = fgetc(fp)) != EOF)
	{
		if(atoi(c) == num)
		{
			while((c[0] = fgetc(fp)) != EOF)
			{
				if(c[0] == '.')
				{
					word[count] = '\0';
					break;
				}
				word[count] = c[0];
				count++;
			} 
		}
	}
	return 1;
}











