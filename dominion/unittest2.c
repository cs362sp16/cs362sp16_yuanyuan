//This test is to test the function playCard
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <assert.h>


void testPlayCard(struct gameState *p);

int main (int argc, char** argv) {
  struct gameState G;
  struct gameState *p = &G;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
     sea_hag, tribute, smithy};
  initializeGame(2, k, atoi(argv[1]), p);
  testPlayCard(p);
  printf("Test for the playCard function success.\n");
    return 0;
}

void testPlayCard(struct gameState *p){
  assert(playCard(3,-1,-1,-1,p)==-1);
  p->hand[0][1]=7;
  assert(playCard(1,-1,-1,-1,p)==0);
  assert(p->numActions==0);
}
