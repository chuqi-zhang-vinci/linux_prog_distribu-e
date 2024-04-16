CC=gcc
CCFLAGS=-D_DEFAULT_SOURCE -D_XOPEN_SOURCE -D_BSD_SOURCE -std=c11 -pedantic -Wvla -Wall -Werror

all : network ipc jeu serveur client

network : network.o utils_v1.o
	$(CC) $(CCFLAGS) -o network network.o utils_v1.o

network.o : network.c utils_v1.h
	$(CC) $(CCFLAGS) -c network.c


ipc : ipc.o utils_v1.o
	$(CC) $(CCFLAGS) -o ipc ipc.o utils_v1.o

ipc.o : ipc.c utils_v1.h
	$(CC) $(CCFLAGS) -c ipc.c


jeu : jeu.o utils_v1.o
	$(CC) $(CCFLAGS) -o jeu jeu.o utils_v1.o

jeu.o : jeu.c utils_v1.h
	$(CC) $(CCFLAGS) -c jeu.c


serveur : serveur.o utils_v1.o
	$(CC) $(CCFLAGS) -o serveur serveur.o utils_v1.o

serveur.o : serveur.c utils_v1.h
	$(CC) $(CCFLAGS) -c serveur.c


client : client.o utils_v1.o
	$(CC) $(CCFLAGS) -o client client.o utils_v1.o

client.o : client.c utils_v1.h
	$(CC) $(CCFLAGS) -c client.c


utils_v1.o : utils_v1.c utils_v1.h
	$(CC) $(CCFLAGS) -c utils_v1.c


clean : 
	rm -f *.o
	rm -f network
	rm -f ipc
	rm -f jeu
	rm -f serveur
	rm -f client