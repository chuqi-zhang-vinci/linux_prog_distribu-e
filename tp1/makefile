CFLAGS = -std=c17 -pedantic -Wvla -Werror -Wall -D_DEFAULT_SOURCE

all: encrypt decrypt

crypt.o: crypt.c crypt.h
	cc $(CFLAGS) -c crypt.c

encrypt.o: crypt.h encrypt.c
	cc $(CFLAGS) -c encrypt.c

decrypt.o: crypt.h decrypt.c
	cc $(CFLAGS) -c decrypt.c

utils_v1.o: utils_v1.h utils_v1.c
	cc $(CFLAGS) -c utils_v1.c

encrypt: encrypt.o crypt.o utils_v1.o
	cc $(CFLAGS) -o encrypt encrypt.o crypt.o utils_v1.o

decrypt: decrypt.o crypt.o utils_v1.o
	cc $(CFLAGS) -o decrypt decrypt.o crypt.o utils_v1.o

clean:
	rm -f *.o encrypt decrypt
