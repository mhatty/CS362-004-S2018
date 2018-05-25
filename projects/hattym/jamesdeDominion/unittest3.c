/* unittest3.c tests the functionality of the isGameOver function  in 
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
	int returnValue;
	
	//set gameState
	initializeGame(numPlayers, k, randomSeed, &preservedState);
	
	/*Start Testing  isGameOver Function*/
	printf("Start isGameOver Unit Tests \n");
	printf("-------------------------------------------\n");
	
	/*Providence Supply is empty*/
	printf("isGameOver Test 1: Providence Card supply is empty\n");
	printf("Expected Result: Return value == 1\n");
	//copy newGameState 
	memcpy(&currentState,&preservedState,sizeof(struct gameState));
	
	//set providence card supply to 0
	currentState.supplyCount[province] = 0;
	printf("Providence Card Supply: %d\n",currentState.supplyCount[province]); 
	returnValue = isGameOver(&currentState);
	printf("Return Value: %d\n",returnValue);
	assertTrue(returnValue);
	
	/*3 Other Suppliers are empty*/
	printf("isGameOver Test 2: 3 Supply piles are empty\n");
	printf("Expected Result: Return value == 1\n");
	//copy newGameState 
	memcpy(&currentState,&preservedState,sizeof(struct gameState));
	currentState.supplyCount[gold] = 0;
	currentState.supplyCount[copper] = 0;
	currentState.supplyCount[silver] = 0;
	printf("Gold Card Supply: %d\n",currentState.supplyCount[gold]); 
	printf("Silver Card Supply: %d\n",currentState.supplyCount[silver]); 
	printf("Copper Card Supply: %d\n",currentState.supplyCount[copper]); 
	returnValue = isGameOver(&currentState);
	printf("Return Value: %d\n",returnValue);
	assertTrue(returnValue);
	
	/*Game Start Settings*/
	printf("isGameOver Test 3: Game has just started\n");
	printf("Expected Result: Return value == 0\n");
	//copy newGameState 
	memcpy(&currentState,&preservedState,sizeof(struct gameState));
	printf("Providence Card Supply: %d\n",currentState.supplyCount[province]);
	printf("Gold Card Supply: %d\n",currentState.supplyCount[gold]); 
	printf("Silver Card Supply: %d\n",currentState.supplyCount[silver]); 
	printf("Copper Card Supply: %d\n",currentState.supplyCount[copper]);  
	returnValue = isGameOver(&currentState);
	printf("Return Value: %d\n",returnValue);
	assertTrue(!returnValue);
	
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
	