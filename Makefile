CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lm

EXECUTABLE = hsht_main

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): hashtable.o hsht_main.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

hashtable.o: hashtable.c hashtable.h
	$(CC) $(CFLAGS) -c hashtable.c -o hashtable.o

hsht_main.o: hsht_main.c hashtable.h
	$(CC) $(CFLAGS) -c hsht_main.c -o hsht_main.o

clean:
	@rm -f *.o $(EXECUTABLE)
