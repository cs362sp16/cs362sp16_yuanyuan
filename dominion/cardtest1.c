//This test is to test the implamentation of card concil_room
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <assert.h>

void test_council_room(struct gameState *p);

int main (int argc, char** argv) {
  int card; //get the number of adventurer
  struct gameState G;
  struct gameState *p = &G;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
     sea_hag, tribute, smithy};
  initializeGame(2, k, atoi(argv[1]), p);
  p->hand[0][1] = council_room;
  test_council_room(p);
  printf("Test for the implamentation of card council_room success.\n");
  return 0;
}

void test_council_room(struct gameState *p){
  //pass the number of another player's hangcount to the variable.
  int handCountForplayer1 = p->handCount[1];
  cardEffect_council_room(1,p);
  assert(p->handCount[1]-1==handCountForplayer1);
  //After played the card concil_room, this card should be discarded.
  assert(p->hand[0][1]!=council_room);
}
