CFLAGS=-std=c11 -pedantic -Wall -Wvla -Werror -D_DEFAULT_SOURCE 

all: ex5.1a

ex5.1a.o: ex5.1a.c utils_v1.h
	gcc $(CFLAGS) -c ex5.1a.c

ex5.1a: ex5.1a.o utils_v1.o
	gcc $(CFLAGS) -o ex5.1a ex5.1a.o utils_v1.o

utils_v1.o: utils_v1.c utils_v1.h
	gcc $(CFLAGS) -c utils_v1.c

clean:
	rm -f *.o
	rm -f $(all);