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

bool assertTrue(bool);
int main()
{

	struct gameState currentState;
	struct gameState preservedState;
	int numPlayers = 2;
	int currentPlayer = 0;
	int k[10] = {adventurer, council_room, feast,  gardens, mine, remodel, smithy, village, baron, great_hall };
	int randomSeed = 100;
	int handCount;
	int playedCardCount;
	int deckCount;
	
	
	//set gameState
	initializeGame(numPlayers, k, randomSeed, &preservedState);
	
	/*Start Testing  Smithy Card Effect Function*/
	printf("Start Smithy Card Unit Tests \n");
	printf("-------------------------------------------\n");
	
	
	//copy newGameState 
	memcpy(&currentState,&preservedState,sizeof(struct gameState));
	
	
	//preserve initial values
	playedCardCount = currentState.playedCardCount;
	deckCount = currentState.deckCount[currentPlayer];
	handCount = currentState.handCount[currentPlayer];
	
	//run Smithy Card Effect
	cardEffect(smithy, 0, 0, 0, &currentState, 1, 0);	
	
	//Test #1
	printf("Smithy Test 1: Hand Contains +2 Cards Overall\n");
	printf("Cards in Hand before Smithy: %d\n",handCount);
	printf("Cards in Hand after Smithy: %d\n",currentState.handCount[currentPlayer]);
	assertTrue(handCount + 2 == currentState.handCount[currentPlayer]);
	
	//Test #2
	printf("Smithy Test 2: Played Cards Contains +1 Cards Overall\n");
	printf("Cards in Played Cards before Smithy: %d\n",playedCardCount);
	printf("Cards in Played Cards after Smithy: %d\n",currentState.playedCardCount);
	assertTrue(playedCardCount + 1 == currentState.playedCardCount);
	
	//Test #3
	printf("Smithy Test 3: Deck Contains 3 Less Cards Overall\n");
	printf("Cards in Deck before Smithy: %d\n",deckCount);
	printf("Cards in Deck after Smithy: %d\n",currentState.deckCount[currentPlayer]);
	assertTrue(deckCount - 3 == currentState.deckCount[currentPlayer]);
		
}


bool assertTrue(bool test)
{
	if(test)
	{
		printf("Test Passed!\n");
		printf("-------------------------------------------\n");
		return true;
	}
	else
	{
		printf("Test Failed!\n");
		printf("-------------------------------------------\n");
		return false;
	}	
}
	