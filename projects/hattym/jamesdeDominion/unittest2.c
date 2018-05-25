/* unittest2.c tests the functionality of the gainCard function  in 
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
	int toFlag;
	int card;
	int returnValue;
	int prevCount;
	
	//set gameState
	initializeGame(numPlayers, k, randomSeed, &preservedState);
	
	/*Start Testing  gainCard Function*/
	printf("Start gainCard Unit Tests \n");
	printf("-------------------------------------------\n");
	
	/*Add card that is not part of the game*/
	printf("gainCard Test 1: Try to gain a card that is not part of the game.\n");
	//copy newGameState 
	memcpy(&currentState,&preservedState,sizeof(struct gameState));
	card = steward;
	toFlag = 2;
	prevCount = currentState.handCount[currentPlayer];
	
	printf("Hand Count is unchanged:\n");
	printf("Starting Hand Count: %d\n",prevCount);
	returnValue = gainCard(card, &currentState,toFlag, currentPlayer);
	printf("Ending Hand Count: %d\n",currentState.handCount[currentPlayer]);
	
	printf("Return Value == -1:\n");
	printf("Return Value: %d\n",returnValue);
	
	assertTrue(returnValue == -1 && prevCount == currentState.handCount[currentPlayer]);
	
	/*Add card to player's deck */
	printf("gainCard Test 2: Gain card to deck.\n");
	//copy newGameState 
	memcpy(&currentState,&preservedState,sizeof(struct gameState));
	card = feast;
	toFlag = 1;
	prevCount = currentState.deckCount[currentPlayer];
	printf("Deck count increases by 1:\n");
	printf("Starting Deck Count: %d\n",prevCount);
	gainCard(card, &currentState,toFlag, currentPlayer);
	printf("Ending Deck Count: %d\n",currentState.deckCount[currentPlayer]);
	printf("Last Deck Card is added Card:\n");
	printf("Card Added: enum value %d\n",feast);
	printf("Last Added: enum value %d\n",currentState.deck[currentPlayer][currentState.deckCount[currentPlayer]-1]);
	assertTrue( prevCount + 1 == currentState.deckCount[currentPlayer] && feast == currentState.deck[currentPlayer][currentState.deckCount[currentPlayer]-1]);
	
	/*Add card to player's  hand*/
	printf("gainCard Test 3: Gain card to player's hand.\n");
	//copy newGameState 
	memcpy(&currentState,&preservedState,sizeof(struct gameState));
	card = feast;
	toFlag = 2;
	prevCount = currentState.handCount[currentPlayer];
	printf("Hand count increases by 1:\n");
	printf("Starting Hand Count: %d\n",prevCount);
	gainCard(card, &currentState,toFlag, currentPlayer);
	printf("Ending Hand Count: %d\n",currentState.handCount[currentPlayer]);
	printf("Last Hand Card is added Card:\n");
	printf("Card Added: enum value %d\n",feast);
	printf("Last Added: enum value %d\n",currentState.hand[currentPlayer][currentState.handCount[currentPlayer]-1]);
	assertTrue( prevCount + 1 == currentState.handCount[currentPlayer] && feast == currentState.hand[currentPlayer][currentState.handCount[currentPlayer]-1]);
	
	/*Add card to discard  pile*/
	printf("gainCard Test 4: Gain card to discard pile\n");
	//copy newGameState 
	memcpy(&currentState,&preservedState,sizeof(struct gameState));
	card = feast;
	toFlag = 0;
	prevCount = currentState.discardCount[currentPlayer];
	printf("Discard count increases by 1:\n");
	printf("Starting Discard Count: %d\n",prevCount);
	gainCard(card, &currentState,toFlag, currentPlayer);
	printf("Ending Discard Count: %d\n",currentState.discardCount[currentPlayer]);
	printf("Last Discarded Card is added Card:\n");
	printf("Card Added: enum value %d\n",feast);
	printf("Last Discarded: enum value %d\n",currentState.discard[currentPlayer][currentState.discardCount[currentPlayer]-1]);
	
	assertTrue( prevCount + 1 == currentState.discardCount[currentPlayer] && feast == currentState.discard[currentPlayer][currentState.discardCount[currentPlayer]-1]);
	
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
	