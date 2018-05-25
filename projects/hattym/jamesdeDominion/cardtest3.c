/* cardtest3.c tests the functionality of the council room card function  in 
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
	int currentPlayer;
	int k[10] = {adventurer, council_room, feast,  gardens, mine, remodel, smithy, village, baron, great_hall };
	int randomSeed = 100;
	int handCount;
	int playedCardCount;
	int discardCount;
	int deckCount;
	int player2HandCount;
	int player2DeckCount;
	int numBuys;
	
	
	//set gameState
	initializeGame(numPlayers, k, randomSeed, &preservedState);
	
	/*Start Testing  adventurer card effect Function*/
	printf("Start Council Room Card Unit Tests \n");
	printf("-------------------------------------------\n");
	
	//copy newGameState 
	memcpy(&currentState,&preservedState,sizeof(struct gameState));
	printf("First Test Set: Player 1's Turn\n");
	currentPlayer = 0;
	//preserve initial values
	numPlayers = 2;
	playedCardCount = currentState.playedCardCount;
	deckCount = currentState.deckCount[currentPlayer];
	handCount = currentState.handCount[currentPlayer];
	player2HandCount = currentState.handCount[currentPlayer+1];
	player2DeckCount = currentState.deckCount[currentPlayer + 1];
	numBuys = currentState.numBuys;
	
	//run Council Room Card Effect
	cardEffect(council_room, 0, 0, 0, &currentState, 1, 0);	
	
	//Test #1
	printf("Council Room Test 1: Player 1 Hand Contains +3 Cards Overall\n");
	printf("Cards in Hand before Council Room: %d\n",handCount);
	printf("Cards in Hand after Council Room: %d\n",currentState.handCount[currentPlayer]);
	assertTrue(handCount + 3 == currentState.handCount[currentPlayer]);
	
	//Test #2
	printf("Council Room Test 2: Player 1's Played Cards Contains +1 Cards Overall\n");
	printf("Cards in Played Cards before Council Room: %d\n",playedCardCount);
	printf("Cards in Played Cards after Council Room: %d\n",currentState.playedCardCount);
	assertTrue(playedCardCount + 1 == currentState.playedCardCount);
	
	//Test #3
	printf("Council Room Test 3: Player 1's Deck Contains 4 Less Cards Overall\n");
	printf("Cards in Deck before Council Room: %d\n",deckCount);
	printf("Cards in Deck after Council Room: %d\n",currentState.deckCount[currentPlayer]);
	assertTrue(deckCount - 4 == currentState.deckCount[currentPlayer]);
	
	//Test #4
	printf("Council Room Test 4: Player 1's number of buys increased by 1\n");
	printf("Number of Buys before Council Room: %d\n",numBuys);
	printf("Number of Buys after Council Room: %d\n",currentState.numBuys);
	assertTrue(numBuys +1 == currentState.numBuys);
	
	//Test #5
	printf("Council Room Test 5: Player 2's Hand Contains +1 Cards Overall\n");
	printf("Cards in Hand before Council Room: %d\n",player2HandCount);
	printf("Cards in Hand after Council Room: %d\n",currentState.handCount[currentPlayer+1]);
	assertTrue(player2HandCount + 1 == currentState.handCount[currentPlayer+1]);

	//Test #6
	printf("Council Room Test 6: Player 2's Deck Contains 1 Less Cards Overall\n");
	printf("Cards in Deck before Council Room: %d\n",player2DeckCount);
	printf("Cards in Deck after Council Room: %d\n",currentState.deckCount[currentPlayer +1]);
	assertTrue(player2DeckCount - 1 == currentState.deckCount[currentPlayer + 1]);
		
	//3 Players Test set	
	//copy newGameState 
	memcpy(&currentState,&preservedState,sizeof(struct gameState));
	printf("First Test Set: Player 2's Turn\n");
	currentPlayer = 1;
	currentState.whoseTurn = 1;
	//preserve initial values
	playedCardCount = currentState.playedCardCount;
	deckCount = currentState.deckCount[currentPlayer];
	handCount = currentState.handCount[currentPlayer];
	player2HandCount = currentState.handCount[currentPlayer - 1];
	player2DeckCount = currentState.deckCount[currentPlayer - 1];
	numBuys = currentState.numBuys;

	//run Council Room Card Effect
	cardEffect(council_room, 0, 0, 0, &currentState, 1, 0);	
	
	//Test #6
	printf("Council Room Test 6: Player 2's Hand Contains +3 Cards Overall\n");
	printf("Cards in Hand before Council Room: %d\n",handCount);
	printf("Cards in Hand after Council Room: %d\n",currentState.handCount[currentPlayer]);
	assertTrue(handCount + 3 == currentState.handCount[currentPlayer]);
	
	//Test #7
	printf("Council Room Test 7: Player 2's Played Cards Contains +1 Cards Overall\n");
	printf("Cards in Played Cards before Council Room: %d\n",playedCardCount);
	printf("Cards in Played Cards after Council Room: %d\n",currentState.playedCardCount);
	assertTrue(playedCardCount + 1 == currentState.playedCardCount);
	
	//Test #8
	printf("Council Room Test 8: Player 2's Deck Contains 4 Less Cards Overall\n");
	printf("Cards in Deck before Council Room: %d\n",deckCount);
	printf("Cards in Deck after Council Room: %d\n",currentState.deckCount[currentPlayer]);
	assertTrue(deckCount - 4 == currentState.deckCount[currentPlayer]);
	
	//Test #9
	printf("Council Room Test 9: Player 2's number of buys increased by 1\n");
	printf("Number of Buys before Council Room: %d\n",numBuys);
	printf("Number of Buys after Council Room: %d\n",currentState.numBuys);
	assertTrue(numBuys +1 == currentState.numBuys);
	
	//Test #10
	printf("Council Room Test 10: Player 1's Hand Contains +1 Cards Overall\n");
	printf("Cards in Hand before Council Room: %d\n",player2HandCount);
	printf("Cards in Hand after Council Room: %d\n",currentState.handCount[currentPlayer-1]);
	assertTrue(player2HandCount + 1 == currentState.handCount[currentPlayer-1]);

	//Test #11
	printf("Council Room Test 11: Player 1's Deck Contains 1 Less Cards Overall\n");
	printf("Cards in Deck before Council Room: %d\n",player2DeckCount);
	printf("Cards in Deck after Council Room: %d\n",currentState.deckCount[currentPlayer -1]);
	assertTrue(player2DeckCount - 1 == currentState.deckCount[currentPlayer -1]);
	
	
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
	