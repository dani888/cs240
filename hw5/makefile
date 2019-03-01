# makefile
# Daniel Werminghausen 4/1/17



CC=gcc
CFLAGS= -m32

all:	tail

tail:	tail.o lineholder.o
	$(CC) $(CFLAGS) -g -o tail tail.o lineholder.o
tail.o: tail.c lineholder.h
	$(CC) $(CFLAGS) -g -c tail.c
lineholder.o: lineholder.c 
	$(CC) $(CFLAGS) -g -c lineholder.c

clean:
	rm *.o