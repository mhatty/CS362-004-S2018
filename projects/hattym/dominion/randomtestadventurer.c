/* cardtest2.c tests the functionality of the adventurer card function  in 
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
	int k[10] = {adventurer, council_room, feast,  gardens, mine, remodel, smithy, village, baron, great_hall};

	
	srand(time(NULL));
	
	
	//randomly initialize game variables
	for(int i = 0; i < 10000; i++)
	{
		int randomSeed = rand();
		numPlayers = rand()%(MAX_PLAYERS-1) + 2 ;
		initializeGame(numPlayers, k, randomSeed, &stateBefore);
		stateBefore.whoseTurn = rand()%numPlayers;
		currentPlayer = stateBefore.whoseTurn;
		
		//set deckcounts
		for(int j = 0; j < numPlayers; j++)
		{
			stateBefore.deckCount[j] = rand() % MAX_DECK;
			stateBefore.handCount[j] = rand() % MAX_HAND;
			
			//set players decks
			for(int k = 0; k < stateBefore.deckCount[j]; k++)
			{
				stateBefore.deck[j][k] = rand()%27;
			}
			
			//set players hands
			for(int k = 0; k < stateBefore.handCount[j]; k++)
			{
				stateBefore.hand[j][k] = rand()%27;
			}
		}
		
		memcpy(&stateAfter,&stateBefore,sizeof(struct gameState));
		cardEffect(adventurer, 0, 0, 0, &stateAfter, 1, 0);	
		if(!cardCheck(stateBefore,stateAfter))
		{
			printf("seed: %d\n",randomSeed);
			printf("numPlayers: %d\n",numPlayers);
			printf("<---------------------------------------------->\n\n");
		}
	}
	
}


//check before and after game state
bool cardCheck(struct gameState before, struct gameState after)
{
		bool flag = true;
		
		int currentPlayer = before.whoseTurn;
		
		if(!(before.handCount[currentPlayer] + 1 == after.handCount[currentPlayer]))
		{
			printf("handCount increases by 1 failed\n");
			flag = false;
		}
		if(!(before.playedCardCount + 1 == after.playedCardCount))
		{
			printf("playedCardCount increases by 1 failed\n");
			flag = false;
		}
		if(!(before.deckCount[currentPlayer] - after.discardCount[currentPlayer] - 2 == after.deckCount[currentPlayer]))
		{
			printf("DeckCount did not decrease by 2 more than the number of discarded Cards \n");
			flag = false;
		}

			
		//verify handcount increase by 2, played cards increase by 1, and deckcount decreases by 3
		if(flag)
		{
			return true;
		}
		else
		{
			printf("Test Failed\nGame State: \n");
			printf("whoseTurn: %d\n",currentPlayer);
			printf("playedCardCount: %d\n",before.playedCardCount);
			printf("deckCount: %d\n",before.deckCount[currentPlayer]);
			printf("handCount: %d\n",before.handCount[currentPlayer]);
			return false;
		}
}


	