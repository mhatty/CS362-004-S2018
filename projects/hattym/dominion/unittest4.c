/* unittest4.c tests the functionality of the buyCard function  in 
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
	int card;
	int numBuys;
	int returnValue;
	int discardCount;
	int supplyCount;
	int numCoins;
	
	//set gameState
	initializeGame(numPlayers, k, randomSeed, &preservedState);
	
	/*Start Testing  buyCard Function*/
	printf("Start buyCard Unit Tests \n");
	printf("-------------------------------------------\n");
	
	/*Try to buy a card when number of buys is less than 1*/
	printf("buyCard Test 1: Number of buys < 1\n");
	printf("Expected Result: Function returns -1, state variables unchanged\n");
	//copy newGameState 
	memcpy(&currentState,&preservedState,sizeof(struct gameState));
	
	//set game state variables
	currentState.coins = 10;
	currentState.numBuys = 0;
	currentState.whoseTurn = currentPlayer;
	
	//preserve initial values
	card = gold;
	discardCount = currentState.discardCount[currentPlayer];
	supplyCount = currentState.supplyCount[card];
	numCoins = currentState.coins;
	numBuys = currentState.numBuys;
	
	//run numBuy
	returnValue = buyCard(gold,&currentState);
	
	//print results
	printf("Card Cost: 6\n");
	printf("Coins Before Buy: %d\n",numCoins);
	printf("Coins After Buy: %d\n",currentState.coins);
	printf("Cards in discard before Buy: %d\n",discardCount);
	printf("Cards in discard after Buy: %d\n",currentState.discardCount[currentPlayer]);
	printf("Card Supply Before Buy: %d\n",supplyCount);
	printf("Card Supply After Buy: %d\n",currentState.supplyCount[card]);
	printf("Number of Buys Before Buy: %d\n",numBuys);
	printf("Number of Buys After Buy: %d\n",currentState.numBuys);
	printf("Return Value: %d\n",returnValue);
	assertTrue(discardCount == currentState.discardCount[currentPlayer] && numCoins == currentState.coins && supplyCount == currentState.supplyCount[card] && numBuys == currentState.numBuys && returnValue == -1);
	
	/*Try to buy a card when the supply count is 0*/
	printf("buyCard Test 2: supply count = 0\n");
	printf("Expected Result: Function returns -1, state variables unchanged\n");
	//copy newGameState 
	memcpy(&currentState,&preservedState,sizeof(struct gameState));
	
	//set game state variables
	currentState.coins = 10;
	currentState.numBuys = 1;
	currentState.supplyCount[card] = 0;
	currentState.whoseTurn = currentPlayer;
	
	//preserve initial values
	card = gold;
	discardCount = currentState.discardCount[currentPlayer];
	supplyCount = currentState.supplyCount[card];
	numCoins = currentState.coins;
	numBuys = currentState.numBuys;
	
	//run numBuy
	returnValue = buyCard(gold,&currentState);
	
	//print results
	printf("Card Cost: 6\n");
	printf("Coins Before Buy: %d\n",numCoins);
	printf("Coins After Buy: %d\n",currentState.coins);
	printf("Cards in discard before Buy: %d\n",discardCount);
	printf("Cards in discard after Buy: %d\n",currentState.discardCount[currentPlayer]);
	printf("Card Supply Before Buy: %d\n",supplyCount);
	printf("Card Supply After Buy: %d\n",currentState.supplyCount[card]);
	printf("Number of Buys Before Buy: %d\n",numBuys);
	printf("Number of Buys After Buy: %d\n",currentState.numBuys);
	printf("Return Value: %d\n",returnValue);
	assertTrue(discardCount == currentState.discardCount[currentPlayer] && numCoins == currentState.coins && supplyCount == currentState.supplyCount[card] && numBuys == currentState.numBuys && returnValue == -1);					
	
	/*Try to buy a card without adequate coins 0*/
	printf("buyCard Test 3: Not Enough Coins < 1\n");
	printf("Expected Result: Function returns -1, state variables unchanged\n");
	//copy newGameState 
	memcpy(&currentState,&preservedState,sizeof(struct gameState));
	
	//set game state variables
	currentState.coins = 0;
	currentState.numBuys = 1;
	currentState.whoseTurn = currentPlayer;
	
	//preserve initial values
	card = gold;
	discardCount = currentState.discardCount[currentPlayer];
	supplyCount = currentState.supplyCount[card];
	numCoins = currentState.coins;
	numBuys = currentState.numBuys;
	
	//run numBuy
	returnValue = buyCard(gold,&currentState);
	
	//print results
	printf("Card Cost: 6\n");
	printf("Coins Before Buy: %d\n",numCoins);
	printf("Coins After Buy: %d\n",currentState.coins);
	printf("Cards in discard before Buy: %d\n",discardCount);
	printf("Cards in discard after Buy: %d\n",currentState.discardCount[currentPlayer]);
	printf("Card Supply Before Buy: %d\n",supplyCount);
	printf("Card Supply After Buy: %d\n",currentState.supplyCount[card]);
	printf("Number of Buys Before Buy: %d\n",numBuys);
	printf("Number of Buys After Buy: %d\n",currentState.numBuys);
	printf("Return Value: %d\n",returnValue);
	assertTrue(discardCount == currentState.discardCount[currentPlayer] && numCoins == currentState.coins && supplyCount == currentState.supplyCount[card] && numBuys == currentState.numBuys && returnValue == -1);
	
	/*Buy Card Successfully*/
	printf("buyCard Test 3: Successfully Buy Card");
	printf("Expected Result: Function returns 0, Coins Decrease by 6, \nNumber of Buys Decreases by 1, Supply Count Decreases by 1, Discard Count increases by 1\n");
	//copy newGameState 
	memcpy(&currentState,&preservedState,sizeof(struct gameState));
	
	//set game state variables
	currentState.coins = 10;
	currentState.numBuys = 1;
	currentState.whoseTurn = currentPlayer;
	
	//preserve initial values
	card = gold;
	discardCount = currentState.discardCount[currentPlayer];
	supplyCount = currentState.supplyCount[card];
	numCoins = currentState.coins;
	numBuys = currentState.numBuys;
	
	//run numBuy
	returnValue = buyCard(gold,&currentState);
	
	//print results
	printf("Card Cost: 6\n");
	printf("Coins Before Buy: %d\n",numCoins);
	printf("Coins After Buy: %d\n",currentState.coins);
	printf("Cards in discard before Buy: %d\n",discardCount);
	printf("Cards in discard after Buy: %d\n",currentState.discardCount[currentPlayer]);
	printf("Card Supply Before Buy: %d\n",supplyCount);
	printf("Card Supply After Buy: %d\n",currentState.supplyCount[card]);
	printf("Number of Buys Before Buy: %d\n",numBuys);
	printf("Number of Buys After Buy: %d\n",currentState.numBuys);
	printf("Return Value: %d\n",returnValue);
	assertTrue(discardCount + 1 == currentState.discardCount[currentPlayer] && numCoins - 6 == currentState.coins && supplyCount -1 == currentState.supplyCount[card] && numBuys -1 == currentState.numBuys && returnValue == 0);
			
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
	