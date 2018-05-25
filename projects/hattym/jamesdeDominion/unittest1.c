/* unittest1.c tests the functionality of the updateCoins function  in 
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
	int currentCoins;
	int newCoins;
	int bonus;
	
	//set gameState
	initializeGame(numPlayers, k, randomSeed, &preservedState);
	
	/*Start Testing  UpdateCoins Function*/
	printf("Start UpdateCoins Unit Tests \n");
	printf("-------------------------------------------\n");
	/*Check if hand with 1 copper, 1 silver, and 2 golds, and no bonus updates the number of coins to 11*/
	printf("UpdateCoins Test 1: Player 1 hand(1 copper, 2 silver, 2 gold) + 0 bonus = 11 coins\n");
	
	//copy newGameState 
	memcpy(&currentState,&preservedState,sizeof(struct gameState));
	
	//set player'ss hand to 1 copper and 1 silver and 2 gold 
	currentState.hand[currentPlayer][0] = copper;
	currentState.hand[currentPlayer][1] = silver;
	currentState.hand[currentPlayer][2] = silver;
	currentState.hand[currentPlayer][3] = gold;
	currentState.hand[currentPlayer][4] = gold;
	
	//set bonus to 0
	bonus = 0;
	
	//call updateCoins
	updateCoins(currentPlayer,&currentState,bonus);
	printf("Actual Player coins: %d\n",currentState.coins);
	assertTrue(currentState.coins == 11);
	
	/*Check if hand with no copper, no silver, no gold and 5 bonus updates the number of coins to 5*/
	printf("UpdateCoins Test 2: Player 1 hand(5 gardens) + 5 bonus = 5 coins\n");
	
	//copy newGameState 
	memcpy(&currentState,&preservedState,sizeof(struct gameState));
	
	//set player'ss hand to 5 non-treasures
	currentState.hand[currentPlayer][0] = gardens;
	currentState.hand[currentPlayer][1] = gardens;
	currentState.hand[currentPlayer][2] = gardens;
	currentState.hand[currentPlayer][3] = gardens;
	currentState.hand[currentPlayer][4] = gardens;
	
	
	//set bonus to 0
	bonus = 5;
	
	//call updateCoins
	updateCoins(currentPlayer,&currentState,bonus);
	printf("Actual Player coins: %d\n",currentState.coins);
	assertTrue(currentState.coins == 5);
	
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
		


