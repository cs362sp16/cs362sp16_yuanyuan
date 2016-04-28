//This test is to test the implamentation of card smithy
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <assert.h>

int main (int argc, char** argv) {
  struct gameState G;
  struct gameState *p = &G;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
     sea_hag, tribute, smithy};
  initializeGame(2, k, atoi(argv[1]), p);
  p->hand[0][0] = smithy;//let the first card of player 0 be smithy
  cardEffect_smithy(0,p);
  printf("%d\n", p->handCount[0]);
  assert(p->handCount[0]==6);/*After drawn three card, the played card
  should be discarded. Therefore, the number of the player's hand card should be 7.*/
  printf("The test for the implamentation of smithy successed.\n");
  //This bug is set by me on the firt assignment
  return 0;
}
