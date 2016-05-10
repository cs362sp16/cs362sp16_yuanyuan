//This test is to randomly test the implamentation of card adventurer
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 50

int main () {
  int handcount,players,player,numActions,seed;
  struct gameState G;
  struct gameState *p = &G;
  int k[11] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
     sea_hag, tribute, smithy,outpost};
	   seed = rand();		//pick random seed
	printf("Test for adventurer Beginning.\n");
  for (int i = 0; i < MAX_TESTS; i++) {
		printf("Running round: %d\n", i+1);
		//initialize players
		players = rand() % 4 + 1;
		//numActions = (rand() % 25) + 1;
		printf("players:%d\n", players);
		player = rand() % players ;
		p->whoseTurn=player;
		initializeGame(players, k, seed, p);
		//Initiate valid state variables
		//p->deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
		//p->discardCount[player] = rand() % MAX_DECK;
		//p->handCount[player] = rand() % MAX_HAND;
		printf("player:%d\n", player);
		p->whoseTurn=player;
		p->handCount[player] = rand() % 10 + 5;
	  //p->hand[player][0] = adventurer;//let the first card of player 0 be smithy
	  handcount = p->handCount[player];
	  cardEffect(adventurer,-1,-1,-1,p,0,-1);
		printf("handcount before:%d  handcount after:%d\n", handcount,p->handCount[player]);
	  if (handcount+2==p->handCount[player]) {
	  	printf("Test successed\n");
	  }
		else
			printf("Test failed\n");
  }
  return 0;
}
