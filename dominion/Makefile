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

adventurer: randomtestadventurer.c dominion.o
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o $(CFLAGS)

randomtestcard:randomtestcard1.c randomtestcard2.c dominion.o
	gcc -o randomtestcard1 randomtestcard1.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o randomtestcard2 randomtestcard2.c -g dominion.o rngs.o $(CFLAGS)


unittest: unittest1.c unittest2.c unittest3.c unittest4.c dominion.o
		gcc -o unittest1 unittest1.c -g dominion.o rngs.o $(CFLAGS)
		gcc -o unittest2 unittest2.c -g dominion.o rngs.o $(CFLAGS)
		gcc -o unittest3 unittest3.c -g dominion.o rngs.o $(CFLAGS)
		gcc -o unittest4 unittest4.c -g dominion.o rngs.o $(CFLAGS)

cardtest:
		gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest1.c rngs.c -o cardtest1 -lm -g
		gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest2.c rngs.c -o cardtest2 -lm -g
		gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest3.c rngs.c -o cardtest3 -lm -g
		gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest4.c rngs.c -o cardtest4 -lm -g

unittestresults:
		./unittest1 1 &> unittestresults.out
		echo "GCOV AFTER 1 TEST" >> unittestresults.out
		gcov dominion.c >> unittestresults.out
		./unittest2 1 >> unittestresults.out
		echo "GCOV AFTER 2 TEST" >> unittestresults.out
		gcov dominion.c >> unittestresults.out
		./unittest3 1 >> unittestresults.out
		echo "GCOV AFTER 3 TEST" >> unittestresults.out
		gcov dominion.c >> unittestresults.out
		./unittest4 1 >> unittestresults.out
		echo "GCOV AFTER 4 TEST" >> unittestresults.out
		gcov dominion.c >> unittestresults.out
		./cardtest1 1 >> unittestresults.out
		echo "GCOV AFTER 1 CARDTEST" >> unittestresults.out
		gcov dominion.c >> unittestresults.out
		./cardtest2 1 >> unittestresults.out
		echo "GCOV AFTER 2 CARDTEST" >> unittestresults.out
		gcov dominion.c >> unittestresults.out
		./cardtest3 1 >> unittestresults.out
		echo "GCOV AFTER 3 CARDTEST" >> unittestresults.out
		gcov dominion.c >> unittestresults.out
		./cardtest4 1 >> unittestresults.out
		echo "GCOV AFTER 4 CARDTEST" >> unittestresults.out
		gcov dominion.c >> unittestresults.out

randomadventurer:
		./randomtestadventurer 42 &> randomtestadventurer.out
		echo "GCOV AFTER 1 TEST adventurer" >> randomtestadventurer.out
		gcov dominion.c >> randomtestadventurer.out
		echo "Coverage for each function" >> randomtestadventurer.out
		gcov -f -b dominion.c >> randomtestadventurer.out
		cat dominion.c.gcov >> randomtestadventurer.out

randomcard1:
	./randomtestcard1 42 &> randomtestcard1.out
	echo "GCOV AFTER 1 TEST card 1" >> randomtestcard1.out
	gcov dominion.c >> randomtestcard1.out
	echo "Coverage for each function" >> randomtestcard1.out
	gcov -f -b dominion.c >> randomtestcard1.out

randomcard2:
	./randomtestcard2 42 &> randomtestcard2.out
	echo "GCOV AFTER 1 TEST card 2" >> randomtestcard2.out
	gcov dominion.c >> randomtestcard2.out
	echo "Coverage for each function" >> randomtestcard2.out
	gcov -f dominion.c >> randomtestcard2.out
	echo "Branch coverage" >>randomtestcard2.out
	gcov -b dominion.c >>randomtestcard2.out

testDominion:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c testdominion.c rngs.c interface.c -o testdominion -lm -g

runTestDominion: testDominion
	./testDominion &> testDominionResults.out
	gcov dominion.c >> testDominionResults.out
	cat dominion.c.gcov >> testDominionResults.out

all: playdom player

clean:
	rm -rf *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestadventurer randomtestcard2 randomtestcard1 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM testDominion2 testDominion1
