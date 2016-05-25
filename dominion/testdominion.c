#include "dominion.h"
#include "rngs.h"
#include "interface.h"

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int main(){
  struct gameState *state = newGame();

  int k[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int card;
  int checkSame;

  int players;
  int seed;

  int x;
  int i;

  int coins;
  //int choice1, choice2, choice3;
  int curPlayer;
  int curCard = 0;
  int cardLocation;
  char cardName[100];
  int actionCard;

  int getWin[MAX_PLAYERS];

  // Random Kingdom Cards (10)
  checkSame = 0;
  for(int i = 0; i < 10; i++){
    // Find random card between adventurer and treasure_map
    card = rand() % 20 + adventurer;
    // duplicate check
    for(int j = 0; j < i; j++){
      if(card == k[j]){
        checkSame = 1;
        break;
      }
      else
        checkSame = 0;
      }
    // If duplicate back track
    if(checkSame == 1)
      i--;
    // otherwise assign kingdom card
    else
      k[i] = card;
  }

for (int i = 0; i < 1; i++) {//loop n times
  printf("Starts game!\n");
  // Print kingdom cards
  printf("Kindom cards: \n");
  for(int i = 0; i < 10; i++){
    cardNumToName(k[i], cardName);
    printf("%s\n", cardName);
  }
  // Initialize Seed
  seed = rand();

  // Random number of players
  players = (rand() % 3) + 2;
  state->numPlayers = players;

  // Init game
  x = initializeGame(players, k, seed, state);

  // Continue Playing while game is not over
  while(!isGameOver(state)){
    // get current player number
    curPlayer = state->whoseTurn;
    printf("first player: %d's \n", curPlayer);
    cardLocation = 0;

    // Check for an action card
    // Avoid feast and tribute infinite loop
    actionCard = 0;
    for(i = 0; i < numHandCards(state); i++){
      if(handCard(i, state) < treasure_map && handCard(i, state) >= adventurer
          && handCard(i, state) != feast && handCard(i, state) != tribute){
        actionCard = i;
        break;
      }
    }

    printf("Action phase stated.\n");
    // While there are actions, continue turn for action phase
    while(state->numActions > 0 && actionCard != 0){
      curCard = handCard(i, state);
      cardNumToName(curCard, cardName);

      //choice1 = rand() % state->handCount[curPlayer];
      //choice2 = rand() % sea_hag;
      //choice3 = rand() % sea_hag;

      x = playCard(actionCard, -1, -1, -1, state);

      // Discard if not valid action card
      if(x == -1){
        //printf("Cannot play card: %s\n", cardName);
        discardCard(cardLocation, curPlayer, state, 0);
      }
      else{
        printf("Played card: %s, %d\n", cardName, curCard);
      }

      // Make sure we still have actions
      if(state->numActions <= 0){
        printf("Action phase over.\n");
        break;
      }

      // Look for next action card
      for(i = actionCard; i < numHandCards(state); i++){
        if(handCard(i, state) < treasure_map && handCard(i, state) >= adventurer
            && handCard(i, state) != feast && handCard(i, state) != tribute){
          actionCard = i;
          break;
        }
        else
          actionCard = 0;
      }
    }

    // Buy phase
    printf("Buy phase starting.\n");
    // check for coin cards
    coins = 0;
    for(i = 0; i < numHandCards(state); i++){
      if(handCard(i, state) == copper)
        coins++;
      else if(handCard(i, state) == silver)
        coins = coins + 2;
      else if(handCard(i, state) == gold)
        coins = coins + 3;
    }
    // Buy while you still can
    while(state->numBuys > 0 && coins > 0){
      do{
        x = rand() % 2;
        cardLocation = rand() % 10;

        // random chance of buying either a kingdom card or a action card
        if(x)
          card = k[cardLocation];
        else
          card = rand() % treasure_map;
      }while(buyCard(card, state) != 0);

      cardNumToName(card, cardName);
      printf("Buying card: %s\n", cardName);
    }
    printf("Buy Phase over.\n");
    // Cleanup
    printf("Clean up.\n");
    endTurn(state);
  }

  // Find out who won the game
  getWinners(getWin, state);
  for(i = 0; i < state->numPlayers; i++){
    if(getWin[i] == 1){
      printf("Player %d wins.\n", i);
      break;
    }
  }
  printf("Their score was: %d\n", scoreFor(i, state));
}


}
