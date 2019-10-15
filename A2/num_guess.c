/*
A program that lets a player vs the computer in a guess a number game.
Initalize variables and have the computer come up with a random number,
then have the computer give a range and ask for an input.
Record the input and adjust the given ranges, record the users best guess.
After the user is out of guesses or guesses correctly allow the user to play again
and reset variables.  
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>

void  main()
{
	//initalize variables
	char var1[3];
	char smin[3] = "1";
	char smax[3] = "20";
	char min[3];
	char max[3];

	int bestguess;
	int bestdif;
	int guessnum;
	int guess = 0;
	int guessdif = 0;
	bool playagain = true;
	int ans = 0;;	

	while(playagain)//loop to play multiple times
	{
		//set variables at the begining of each loop
		strncpy(min, smin, 3);
		strncpy(max, smax, 3);
		guessnum = 4;
		bestguess = 0;
		bestdif = 100;
		srand(time(0));	
		ans = rand()%20;	
		
		//loop while the user has guesses remaning
		while(guessnum > 0)
		{
			//interact with user	
			printf("\nGuess a number from %s to %s: ", min , max);
			scanf("%s" , var1);	
			if(atoi(var1) < ans)
			{
				strncpy(min, var1, 3);
			}
			if(atoi(var1) > ans)
			{
				strncpy(max, var1, 3);
			}
			if(atoi(var1) == ans)
			{
				printf("\nCongratulations %s was the right number!\n", var1);
				guessnum = 0;
			}
			//record guess and compare to record best guess
			guess = atoi(var1);
			if(ans > guess)
			{
				guessdif = ans - guess;
			}
			if(ans < guess)
			{
				guessdif = guess - ans;
			}
			if(guessdif < 0)
			{
				guessdif = guessdif * -1;
			}  
			if(guessdif < bestdif)
			{
				bestdif = guessdif;
				bestguess = guess;
			}
			//increment remaning guesses
			guessnum--;
		}
		//tell the user if they lost and their best guess 
		//then give option to play again
		if(guessnum == 0)
		{
			printf("\nGame over %d was the right number!\n", ans);
			printf("\n%d was your closest guess\n", bestguess);
			printf("\nType 1 to play again, or anything else to exit\n");
			scanf("%s", var1);
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
