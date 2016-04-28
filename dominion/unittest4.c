//This test is to test the function getCost
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <assert.h>

void testGetcost();

int main (int argc, char** argv) {
    testGetcost();
    printf("Test for the function getCost success.\n");
    return 0;
}

void testGetcost(){
  assert(getCost(0)==0);//curse
  assert(getCost(1)==2);//estate
  assert(getCost(2)==5);//duchy
  assert(getCost(13)==4);//smithy
  assert(getCost(30)==-1);
}
