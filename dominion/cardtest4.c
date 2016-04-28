//This test is to test the implamentation of card smithy
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <assert.h>

int main (int argc, char** argv) {
  int outpostP;
  struct gameState G;
  struct gameState *p = &G;
  int k[11] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
     sea_hag, tribute, smithy,outpost};
  initializeGame(2, k, atoi(argv[1]), p);
  p->hand[0][0] = smithy;//let the first card of player 0 be smithy
  outpostP = p->outpostPlayed;
  cardEffect(outpost,-1,-1,-1,p,0,-1);
  assert(p->outpostPlayed == outpostP+1);
  printf("The test for the implamentation of outpost successed.\n");
  return 0;
}
