CFLAGS=-std=c17 -pedantic -Wvla -Werror -Wall -D_DEFAULT_SOURCE

all : npi testplaylist

utils_v1.o : utils_v1.h utils_v1.c
	cc $(CFLAGS) -c utils_v1.c

pile.o : pile.h pile.c
	cc $(CFLAGS) -c pile.c

npi.o : npi.c utils_v1.h pile.h
	cc $(CFLAGS) -c npi.c

npi : npi.o pile.o utils_v1.o
	cc $(CFLAGS) -o npi npi.o pile.o utils_v1.o




track.o : track.h track.c
	cc $(CFLAGS) -c track.c

playlist.o : playlist.h playlist.c track.h
	cc $(CFLAGS) -c playlist.c

testplaylist.o : playlist.h testplaylist.c track.h
	cc $(CFLAGS) -c testplaylist.c

testplaylist : testplaylist.o playlist.o track.o
	cc $(CFLAGS) -o testplaylist testplaylist.o playlist.o track.o


clean :
	rm *o npi testplaylist