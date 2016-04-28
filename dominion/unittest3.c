//This test is to test the function updateCoins
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <assert.h>

void testUpdateCoins(struct gameState *p);

int main (int argc, char** argv) {
  struct gameState G;
  struct gameState *p = &G;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
     sea_hag, tribute, smithy};
  initializeGame(2, k, atoi(argv[1]), p);
  testUpdateCoins(p);
    return 0;
}

void testUpdateCoins(struct gameState *p){
    for (int i = 0; i < p->handCount[0]; i++) {
      p->hand[0][i] = copper;
    }
    updateCoins(0,p,3);
    assert(p->coins==8);
    for (int i = 0; i < p->handCount[0]; i++) {
      p->hand[0][i] = silver;
    }
    updateCoins(0,p,0);
    assert(p->coins==10);
    p->hand[1][0] = copper;
    p->hand[1][1] = copper;
    p->hand[1][2] = copper;
    p->hand[1][3] = silver;
    p->hand[1][4] = gold;
    p->handCount[1]=5;
    updateCoins(1,p,0);
    printf("%d\n", p->coins);
    assert(p->coins==8);
    printf("Test for function updateCoins success.\n");
}
