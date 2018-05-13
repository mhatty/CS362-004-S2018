/* cardtest1.c tests the functionality of the smithy function  in 
	dominion.c
*/

#include <stdbool.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "rngs.h"
#include <time.h>

bool cardCheck(struct gameState, struct gameState);

int main()
{

	struct gameState stateBefore;
	struct gameState stateAfter;
	int numPlayers;
	int currentPlayer;
	int k[10] = {adventurer, council_room, feast,  gardens, mine, remodel, smithy, village, baron, great_hall };
	int handCount;
	int playedCardCount;
	int deckCount;
	
	srand(time(NULL));
	
	
	
	/*Start Testing  Smithy Card Effect Function*/
	printf("Start Smithy Card Random Tests \n");
	printf("-------------------------------------------\n");
	//set gameState
	
	
	for(int i = 0; i < 100000; i++)
	{
		int randomSeed = rand();
		numPlayers = rand()%(MAX_PLAYERS-1) + 2 ;
		initializeGame(numPlayers, k, randomSeed, &stateBefore);
		
		//randomly initialize game variables
		for(int i = 0; i < numPlayers; i++)
		{
			stateBefore.deckCount[i] = rand() % MAX_DECK;
			stateBefore.handCount[i] = rand() % MAX_HAND;
		}
		
		stateBefore.whoseTurn = rand() % numPlayers;
		memcpy(&stateAfter,&stateBefore,sizeof(struct gameState));
		
		
		//run Smithy Card Effect
		cardEffect(smithy, 0, 0, 0, &stateAfter, 1, 0);	
		if(!cardCheck(stateBefore,stateAfter))
		{
			printf("seed: %d\n",randomSeed);
			printf("<---------------------------------------------->\n\n");
		}
	}
	
	return 0;	
}


//check before and after game state
bool cardCheck(struct gameState before, struct gameState after)
{
		int currentPlayer = before.whoseTurn;
		bool flag = true;
		
		//verify handcount increase by 2, 
		if(!(before.handCount[currentPlayer] + 2 == after.handCount[currentPlayer]))
		{
			printf("HandCount increased by 2 fail\n");
			flag = false;
		}
		//verify playedCards increases by 1
		if(!(before.playedCardCount + 1 == after.playedCardCount))
		{
			printf("playedCards increased by 1 fail\n");
			flag = false;
		}
		//verify deckCount decreases by 3
		if(!(before.deckCount[currentPlayer] - 3 == after.deckCount[currentPlayer]))
		{
			printf("deck decreased by 3 fail\n");
			flag = false;
		}
		
		if(flag)
		{
			return true;
		}
		else
		{
			printf("Test Failed\nGame State: \n");
			printf("whoseTurn: %d\n",currentPlayer);
			printf("deckCount: %d\n",before.deckCount[currentPlayer]);
			printf("handCount: %d\n",before.handCount[currentPlayer]);
			return false;
		}
}


