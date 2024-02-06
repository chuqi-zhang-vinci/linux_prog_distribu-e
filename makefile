CFLAGS=-std=c17 -pedantic -Wvla -Werror -Wall -D_DEFAULT_SOURCE

all : encrypt decrypt encryptPolybe decryptPolybe

crypt.o : crypt.c crypt.h
	cc $(CFLAGS) -c crypt.c;

encrypt.o : crypt.h utils_v1.h encrypt.c
	cc $(CFLAGS) -c encrypt.c

decrypt.o : crypt.h utils_v1.h decrypt.c
	cc $(CFLAGS) -c decrypt.c

utils_v1.o : utils_v1.h utils_v1.c
	cc $(CFLAGS) -c utils_v1.c

encrypt : crypt.o encrypt.o utils_v1.o
	cc $(CFLAGS) -o encrypt crypt.o encrypt.o utils_v1.o

decrypt : crypt.o decrypt.o utils_v1.o
	cc $(CFLAGS) -o decrypt crypt.o decrypt.o utils_v1.o

cryptPolybe.o : cryptPolybe.h cryptPolybe.c
	cc $(CFLAGS) -c cryptPolybe.c

encryptPolybe.o : cryptPolybe.h encryptPolybe.c utils_v1.h
	cc $(CFLAGS) -c encryptPolybe.c

decryptPolybe.o : cryptPolybe.h decryptPolybe.c utils_v1.h
	cc $(CFLAGS) -c decryptPolybe.c

encryptPolybe : utils_v1.o encryptPolybe.o cryptPolybe.o
	cc $(CFLAGS) -o encryptPolybe cryptPolybe.o encryptPolybe.o utils_v1.o

decryptPolybe : utils_v1.o decryptPolybe.o cryptPolybe.o
	cc $(CFLAGS) -o decryptPolybe cryptPolybe.o decryptPolybe.o utils_v1.o

clean : 
	rm *.o encrypt decrypt encryptPolybe decryptPolybe