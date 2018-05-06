CFLAGS = -Wall -fpic -coverage -lm

runtests: testme
	./testme -i
	gcov -f -b testme.c &> randomtestresult.out 
	cat testme.c.gcov >> randomtestresult.out

testme: testme.o
	gcc -o testme testme.o $(CFLAGS)
	
testme.o: testme.c
	gcc -c testme.c $(CFLAGS)

clean:
	rm testme.o testme testme.gcno testme.c.gcov testme.gcno testme.gcda