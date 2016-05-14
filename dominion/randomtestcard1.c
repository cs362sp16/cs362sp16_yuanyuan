//This test is to randomly test the implamentation of card council_room
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 1000

int main () {
  int card,handCountForCurrent[MAX_PLAYERS],numberbuys,seed,player,players;
  int suc=0,fail=0;
  int i;//get other player's hand count
  struct gameState G;
  struct gameState *p = &G;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
     sea_hag, tribute, smithy};
     seed = rand();		//pick random seed
  printf("Test for the card council_room Beginning\n");
  for (int j = 0; j < MAX_TESTS; j++) {
    ////printf("Running Round: %d\n",j+1);
    players = rand() % 4 + 1;
		//numActions = (rand() % 25) + 1;
		//printf("players:%d\n", players);
		player = rand() % players ;
    //initialize game
    initializeGame(players, k, seed, p);
    p->whoseTurn=player;

    for (int j = 0; j < players; j++) {
      p->handCount[j]=rand() % 10 + 5;
      handCountForCurrent[j]=p->handCount[j];
    }
    p->hand[player][1] = council_room;
    //pass the number of current player's handCount to a variable
    numberbuys=p->numBuys;
    cardEffect_council_room(1,p);
    //test current player's handcount
    if (handCountForCurrent[player]+4==p->handCount[player] && numberbuys+1==p->numBuys) {
      //printf("Test for current player's handcount and numBuys successed.\n");
      suc++;
    }
    else {//printf("Test for current player's handcount and numBuys failed.\n");
        fail++;
      }
    //test other player's handcount
    int num = 0; //get the total number of the players which test successed.
    for (int j = 0; j < players; j++) {
      if (j!=player) {
        if (handCountForCurrent[j]+1==p->handCount[j]) {
          num++;
        }
      }
    }
    if (num==players-1) {
      //printf("Test for other player's handcount successed.\n");
      suc++;
    }
    else //printf("Test for other player's handcount failed.\n");
      fail++;
  }
  printf("time failed: %d time successed: %d\n",fail,suc);
  return 0;
}
