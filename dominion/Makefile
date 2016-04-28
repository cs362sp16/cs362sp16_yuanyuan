CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

test: dominion.o unittest1.c unittest2.c unittest3.c unittest4.c
			gcc -o unittest1 unittest1.c -g dominion.o rngs.o $(CFLAGS)
			gcc -o unittest2 unittest2.c -g dominion.o rngs.o $(CFLAGS)
			gcc -o unittest3 unittest3.c -g dominion.o rngs.o $(CFLAGS)
			gcc -o unittest4 unittest4.c -g dominion.o rngs.o $(CFLAGS)

cardtest: dominion.o cardtest1.c cardtest2.c cardtest3.c cardtest4.c
			gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o $(CFLAGS)
			gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o $(CFLAGS)
			gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o $(CFLAGS)
			gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o $(CFLAGS)

unittestresults:
			gcov unittest1.c
			gcov unittest2.c
			gcov unittest3.c
			gcov unittest4.c
			gcov cardtest1.c
			gcov cardtest2.c
			gcov cardtest3.c
			gcov cardtest4.c
			cat unittest1.c.gcov &> unittestresults.out
			cat unittest2.c.gcov >> unittestresults.out
			cat unittest3.c.gcov >> unittestresults.out
			cat unittest4.c.gcov >> unittestresults.out
			cat cardtest1.c.gcov >> unittestresults.out
			cat cardtest2.c.gcov >> unittestresults.out
			cat cardtest3.c.gcov >> unittestresults.out
			cat cardtest4.c.gcov >> unittestresults.out

all: playdom player

clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM
