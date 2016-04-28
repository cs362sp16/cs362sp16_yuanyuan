//This test is to test the function initializeGame
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <assert.h>

void  testInitializeGame(int randomSeed,struct gameState *p);

int main (int argc, char** argv) {
  struct gameState G;
  struct gameState *p = &G;
  testInitializeGame(atoi(argv[1]),p);
    return 0;
}

void testInitializeGame(int randomSeed,struct gameState *p){
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
     sea_hag, tribute, smithy};
  initializeGame(2, k, randomSeed, p);
  assert(10==p->supplyCount[curse]);
  assert(p->handCount[0]==5);
  assert(p->handCount[1]==5);
  printf("Test for the initializeGame function success.\n");
}
