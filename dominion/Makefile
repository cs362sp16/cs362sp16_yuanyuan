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
		gcc -o test1 unittest1.c -g dominion.o rngs.o $(CFLAGS)
		gcc -o test2 unittest2.c -g dominion.o rngs.o $(CFLAGS)
		gcc -o test3 unittest3.c -g dominion.o rngs.o $(CFLAGS)
		gcc -o test4 unittest4.c -g dominion.o rngs.o $(CFLAGS)

cardtest: dominion.o cardtest1.c cardtest2.c cardtest3.c cardtest4.c
		gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o $(CFLAGS)
		gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o $(CFLAGS)
		gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o $(CFLAGS)
		gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o $(CFLAGS)

all: playdom player

clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM
