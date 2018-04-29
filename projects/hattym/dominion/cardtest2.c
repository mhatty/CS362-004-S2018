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
	int discardCount;
	int deckCount;
	
	
	//set gameState
	initializeGame(numPlayers, k, randomSeed, &preservedState);
	
	/*Start Testing  adventurer card effect Function*/
	printf("Start Adventurer Card Unit Tests \n");
	printf("-------------------------------------------\n");
	
	
	//copy newGameState 
	memcpy(&currentState,&preservedState,sizeof(struct gameState));
	printf("First Test Set: Top 2 Deck Cards Are Treasures\n");
	
	//set top 2 to copper
	currentState.deck[currentPlayer][currentState.deckCount[currentPlayer]-1] = copper;
	currentState.deck[currentPlayer][currentState.deckCount[currentPlayer]-2] = copper;
	
	//preserve initial values
	playedCardCount = currentState.playedCardCount;
	deckCount = currentState.deckCount[currentPlayer];
	handCount = currentState.handCount[currentPlayer];
	discardCount = currentState.discardCount[currentPlayer];
	
	//run Adventurer Card Effect
	cardEffect(adventurer, 0, 0, 0, &currentState, 1, 0);	
	
	//Test #1
	printf("Adventurer Test 1: Hand Contains +1 Cards Overall\n");
	printf("Cards in Hand before Adventurer: %d\n",handCount);
	printf("Cards in Hand after Adventurer: %d\n",currentState.handCount[currentPlayer]);
	assertTrue(handCount + 1 == currentState.handCount[currentPlayer]);
	
	//Test #2
	printf("Adventurer Test 2: Played Cards Contains +1 Cards Overall\n");
	printf("Cards in Played Cards before Adventurer: %d\n",playedCardCount);
	printf("Cards in Played Cards after Adventurer: %d\n",currentState.playedCardCount);
	assertTrue(playedCardCount + 1 == currentState.playedCardCount);
	
	//Test #3
	printf("Adventurer Test 3: Deck Contains 2 Less Cards Overall\n");
	printf("Cards in Deck before Adventurer: %d\n",deckCount);
	printf("Cards in Deck after Adventurer: %d\n",currentState.deckCount[currentPlayer]);
	assertTrue(deckCount - 2 == currentState.deckCount[currentPlayer]);
	
	//Test #4
	printf("Adventurer Test 4: Discard Pile is Unchanged \n");
	printf("Cards in Discard Pile before Adventurer: %d\n",discardCount);
	printf("Cards in Discard Pile after Adventurer: %d\n",currentState.discardCount[currentPlayer]);
	assertTrue(discardCount == currentState.discardCount[currentPlayer]);
	
	//copy newGameState 
	memcpy(&currentState,&preservedState,sizeof(struct gameState));
	printf("Second Test Set: 2 Cards drawn before any treasurers drawn \n");
	
	//set top 2 to copper
	currentState.deck[currentPlayer][currentState.deckCount[currentPlayer]-1] = estate;
	currentState.deck[currentPlayer][currentState.deckCount[currentPlayer]-2] = estate;
	currentState.deck[currentPlayer][currentState.deckCount[currentPlayer]-3] = copper;
	currentState.deck[currentPlayer][currentState.deckCount[currentPlayer]-4] = copper;
	
	//preserve initial values
	playedCardCount = currentState.playedCardCount;
	deckCount = currentState.deckCount[currentPlayer];
	handCount = currentState.handCount[currentPlayer];
	discardCount = currentState.discardCount[currentPlayer];
	
	//run Adventurer Card Effect
	cardEffect(adventurer, 0, 0, 0, &currentState, 1, 0);	
	
	//Test #5
	printf("Adventurer Test 5: Hand Contains +1 Cards Overall\n");
	printf("Cards in Hand before Adventurer: %d\n",handCount);
	printf("Cards in Hand after Adventurer: %d\n",currentState.handCount[currentPlayer]);
	assertTrue(handCount + 1 == currentState.handCount[currentPlayer]);
	
	//Test #6
	printf("Adventurer Test 6: Played Cards Contains +1 Cards Overall\n");
	printf("Cards in Played Cards before Adventurer: %d\n",playedCardCount);
	printf("Cards in Played Cards after Adventurer: %d\n",currentState.playedCardCount);
	assertTrue(playedCardCount + 1 == currentState.playedCardCount);
	
	//Test #7
	printf("Adventurer Test 7: Deck Contains 4 Less Cards Overall\n");
	printf("Cards in Deck before Adventurer: %d\n",deckCount);
	printf("Cards in Deck after Adventurer: %d\n",currentState.deckCount[currentPlayer]);
	assertTrue(deckCount - 4 == currentState.deckCount[currentPlayer]);
	
	//Test #8
	printf("Adventurer Test 8: Discard Pile contains +2 Cards Overall \n");
	printf("Cards in Discard Pile before Adventurer: %d\n",discardCount);
	printf("Cards in Discard Pile after Adventurer: %d\n",currentState.discardCount[currentPlayer]);
	assertTrue(discardCount +2 == currentState.discardCount[currentPlayer]);
		
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
	