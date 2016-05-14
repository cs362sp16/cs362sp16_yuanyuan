//This test is to test the implamentation of card minion
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 50

int main () {
  int choice1,choice2,player,players,numCoins,seed;
  int playerHand[MAX_PLAYERS];

  struct gameState G;
  struct gameState *p = &G;
  seed = rand();		//pick random seed
  SelectStream(1);
  PutSeed(seed);
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
     sea_hag, tribute, smithy};
  //pick random value for choice
  for (int j = 0; j < MAX_TESTS; j++) {
    choice1=rand()%2;
    if (choice1==0) {
      choice2=1;
    }else
      choice2=0;
      //printf("choice1:%d choice2:%d\n",choice1,choice2);//Debug
    //randomly set players and current player
    players = rand() % 4 + 1;
    player = rand() % players ;
    initializeGame(players, k, seed, p);
    numCoins=p->coins;
    //give each player initial handCount value
    for (int i = 0; i < players; i++) {
      p->handCount[i]=rand() % 20;
      playerHand[i]=p->handCount[i];
    }
    p->whoseTurn=player;
    //printf("%d,%d\n",p->handCount[0],p->handCount[1]);
    p->hand[player][1] = minion;//let the first card of player 0 be minion
    //printf("%d\n",p->handCount[1]);//Debug
    cardEffect(minion,choice1,choice2,0,p,1,-1);//choice 2
    //printf("%d,%d\n",p->handCount[player],playerHand[player]);//Debug
      //For choice2,  other players with 5+ cards discard hand and draw 4
    int j=0;
    if (choice2 == 1) {
      if(p->handCount[player]==4)//current player discard hand and redraw4 cards
      {
        printf("Test for handCount of currentPlayer successed.\n");
      }
      else
        printf("Test for handCount of currentPlayer failed.\n");
      for (int i = 0; i < players; i++) {
      //printf("%d,%d\n",p->handCount[i],playerHand[i]);
        if (i!=player) {
          if(playerHand[i]>=5){
            if (p->handCount[i]!=4) {
              j++;
            }
          }
          else {
            if (playerHand[i]!=p->handCount[i]) {
              j++;
            }
          }
        }
      }
    }
    else if(choice2==0){
    //printf("%d,%d\n", numCoins,p->coins);//Debug
      if (numCoins+2!=p->coins) {
        j++;
      }
    }
    if (j == 0) {
      printf("Test for other player's handCount and state's coins successed.\n");
    }
    else printf("Test for other player's handCount and state's coins failed.\n");
  }
  return 0;
}
