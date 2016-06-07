//This test is to test the implamentation of card minion
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
  //printf("%d,%d\n",p->handCount[0],p->handCount[1]);
  p->hand[0][0] = minion;//let the first card of player 0 be minion
  for (int i = 0; i < 5; i++) {
    drawCard(1,p);
  }
  //printf("%d\n",p->handCount[1]);
  cardEffect(minion,-1,0,-1,p,0,-1);//choice 2
  //printf("%d,%d\n",p->handCount[0], p->handCount[1]);
  assert(p->handCount[0]=4);//other player discard hand and redraw4 cards
  assert(p->handCount[1]=4);//current player discard played card and draw 4 cards
  printf("The test for the implamentation of minion success.\n");
  return 0;
}
