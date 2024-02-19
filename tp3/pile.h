#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#ifndef _PILE_H_
#define _PILE_H_

typedef struct Noeud {
	int val;
	struct Noeud* suivant;
} Noeud;

typedef Noeud* Pile;



Pile initPile();

bool pileVide (Pile);

bool push (Pile*, int);

int pop (Pile*);

void viderPile (Pile*);

void afficherPile (Pile);

#endif