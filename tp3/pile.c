#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "pile.h"
#include "utils_v1.h"

Pile initPile(){
	Pile pile = NULL;
	return pile;
}

bool pileVide(Pile pile) {
	return pile == NULL;
}

bool push (Pile* pile, int param) {
	Pile temp = malloc (sizeof(Noeud));
	temp->val = param;
	temp->suivant = *pile;
	*pile = temp;
	return true;
}

int pop (Pile* pile) {
	if(*pile == NULL) {
		return -1;
	}
	int victime = (*pile)->val;
	*pile = (*pile)->suivant;
	return victime;
}

void viderPile (Pile* pile) {
	while (*pile != NULL){
		Pile temp = *pile;
		*pile = (*pile)->suivant;
		free(temp);
	}
}

void afficherPile (Pile pile){
	while (pile != NULL){
		printf("%c\n", pile->val);
		pile = pile->suivant;
	}
}