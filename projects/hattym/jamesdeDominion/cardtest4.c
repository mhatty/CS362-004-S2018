/* cardtest4.c tests the functionality of the remodel function  in 
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
	int supplyCount;
	int returnValue;
	int discardCount;
	int handPos;
	
	//set gameState
	initializeGame(numPlayers, k, randomSeed, &preservedState);
	
	/*Start Testing  Smithy Card Effect Function*/
	printf("Start Remodel Card Unit Tests \n");
	printf("-------------------------------------------\n");
	
	
	//copy newGameState 
	memcpy(&currentState,&preservedState,sizeof(struct gameState));
	printf("First Test Set: Gained Card Cost > +2 Trashed Card\n");
	//set trashed card to last card in hand, make trashed card an estate
	handPos = currentState.handCount[currentPlayer]-1;
	currentState.hand[currentPlayer][handPos] = copper;
	
	//preserve initial values
	playedCardCount = currentState.playedCardCount;
	deckCount = currentState.deckCount[currentPlayer];
	handCount = currentState.handCount[currentPlayer];
	supplyCount = currentState.supplyCount[duchy];
	discardCount = currentState.discardCount[currentPlayer];

	//run Remodel Card Effect
	cardEffect(remodel, copper, province, 0,&currentState, handPos , 0);	
	//Test #1
	printf("Remodel Test 1: Hand Contains Same Number of Cards Cards\n");
	printf("Cards in Hand before Remodel: %d\n",handCount);
	printf("Cards in Hand after Remodel: %d\n",currentState.handCount[currentPlayer]);
	assertTrue(handCount == currentState.handCount[currentPlayer]);
	
	//Test #2
	printf("Remodel Test 2: Played Cards Contains Same Number of Cards Overall\n");
	printf("Cards in Played Cards before Remodel: %d\n",playedCardCount);
	printf("Cards in Played Cards after Remodel: %d\n",currentState.playedCardCount);
	assertTrue(playedCardCount  == currentState.playedCardCount);
	
	//Test #3
	printf("Remodel Test 3: Deck Contains Same Number of Cards Overall\n");
	printf("Cards in Deck before Remodel: %d\n",deckCount);
	printf("Cards in Deck after Remodel: %d\n",currentState.deckCount[currentPlayer]);
	assertTrue(deckCount == currentState.deckCount[currentPlayer]);
	
	//Test #4
	printf("Remodel Test 4: Discard Pile Contains Same Number of Cards Overall\n");
	printf("Cards in Discard Pile before Remodel: %d\n",discardCount);
	printf("Cards in Discard Pile after Remodel: %d\n",currentState.discardCount[currentPlayer]);
	assertTrue(discardCount  == currentState.discardCount[currentPlayer]);
	
	//Test #5
	printf("Remodel Test 5: Duchy Supply Contains Same Number of Cards Overall\n");
	printf("Cards in Duchy Supply Pile before Remodel: %d\n",supplyCount);
	printf("Cards in Duchy Supply Pile after Remodel: %d\n",currentState.supplyCount[duchy]);
	assertTrue(supplyCount  == currentState.supplyCount[duchy]);
	
	//copy newGameState 
	memcpy(&currentState,&preservedState,sizeof(struct gameState));
	printf("Second Test Set: Gained Card Cost < 2 + Trashed Card Value\n");
	//set trashed card to last card in hand, make trashed card an estate
	handPos = currentState.handCount[currentPlayer]-1;
	currentState.hand[currentPlayer][handPos] = estate;
	
	//preserve initial values
	playedCardCount = currentState.playedCardCount;
	deckCount = currentState.deckCount[currentPlayer];
	handCount = currentState.handCount[currentPlayer];
	supplyCount = currentState.supplyCount[duchy];
	discardCount = currentState.discardCount[currentPlayer];
	
	//run Remodel Card Effect
	cardEffect(remodel, estate, duchy, 0,&currentState, handPos , 0);	
	//Test #6
	printf("Remodel Test 6: Hand Contains 2 Less Cards Cards\n");
	printf("Cards in Hand before Remodel: %d\n",handCount);
	printf("Cards in Hand after Remodel: %d\n",currentState.handCount[currentPlayer]);
	assertTrue(handCount - 2 == currentState.handCount[currentPlayer]);
	
	//Test #7
	printf("Remodel Test 7: Played Cards Contains +1 Card Overall\n");
	printf("Cards in Played Cards before Remodel: %d\n",playedCardCount);
	printf("Cards in Played Cards after Remodel: %d\n",currentState.playedCardCount);
	assertTrue(playedCardCount + 1  == currentState.playedCardCount);
	
	//Test #8
	printf("Remodel Test 8: Deck Contains Same Number of Cards Overall\n");
	printf("Cards in Deck before Remodel: %d\n",deckCount);
	printf("Cards in Deck after Remodel: %d\n",currentState.deckCount[currentPlayer]);
	assertTrue(deckCount == currentState.deckCount[currentPlayer]);
	
	//Test #9
	printf("Remodel Test 9: Discard Pile Contains +1 Card Overall\n");
	printf("Cards in Discard Pile before Remodel: %d\n",discardCount);
	printf("Cards in Discard Pile after Remodel: %d\n",currentState.discardCount[currentPlayer]);
	assertTrue(discardCount +1  == currentState.discardCount[currentPlayer]);
	
	//Test #10
	printf("Remodel Test 10: Duchy Supply Contains 1 Less Card Overall\n");
	printf("Cards in Duchy Supply Pile before Remodel: %d\n",supplyCount);
	printf("Cards in Duchy Supply Pile after Remodel: %d\n",currentState.supplyCount[duchy]);
	assertTrue(supplyCount -1  == currentState.supplyCount[duchy]);
	
	
		
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
	