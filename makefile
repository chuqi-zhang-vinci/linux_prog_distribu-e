CFLAGS=-std=c11 -pedantic -Wall -Wvla -Werror -D_DEFAULT_SOURCE

all: ex4.1a ex4.1b

ex4.1a.o: ex4.1a.c utils_v1.h
	gcc $(CFLAGS) -c ex4.1a.c

ex4.1a: ex4.1a.o utils_v1.o
	gcc $(CFLAGS) -o ex4.1a ex4.1a.o utils_v1.o

ex4.1b.o: ex4.1b.c utils_v1.h
	gcc $(CFLAGS) -c ex4.1b.c

ex4.1b: ex4.1b.o utils_v1.o
	gcc $(CFLAGS) -o ex4.1b ex4.1b.o utils_v1.o


utils_v1.o: utils_v1.c utils_v1.h
	gcc $(CFLAGS) -c utils_v1.c

clean:
	rm -f *.o
	rm -f $(all)
