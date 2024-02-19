#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "playlist.h"


Playlist* initPlaylist () {
    // TODO
    Playlist* playlist = (Playlist*)malloc(sizeof(Playlist));
    if(playlist == NULL)
        exit(1);
    playlist->tete = NULL;
    playlist->queue = NULL;
    return playlist;
}


bool addTrack (Playlist* p, Track* t) {
    // TODO
    Noeud* n = (Noeud*) malloc(sizeof(Noeud));

    if(n == NULL) {
        perror("malloc a foire");
        return false;
    }

    n->val = t;
    n->suivant = NULL;

    if (p->tete == NULL) {
        p->tete  = n;
        p->queue = n;
        return true;
    } else {
        p->queue->suivant = n;
        p->queue = n;
        return true;
    }
}


Playlist* destructiveMerge (Playlist* p1, Playlist* p2) {
    // TODO
    Playlist* p3 = (Playlist*) malloc (sizeof(Playlist));
    if(p3 == NULL) exit(1);
    *p3 = *p1;
    p3->queue->suivant = p2->tete;
    p3->queue = p2->queue;

    // doublons
    for(Noeud* target = p3->tete; target != NULL; target = target->suivant) {
        Noeud* prec = target;
        for (Noeud* c = target->suivant; c != NULL; c = c->suivant) {
            if ( compareTrack(c->val, target->val) == 0) {
                prec->suivant = c->suivant;
                free(c);
                c = prec;
            } else {
                prec = c;
            }
        }
    }

    p1->tete = NULL;
    p1->queue= NULL;
    p2->tete = NULL;
    p2->queue= NULL;

    return p3;
}


/** 
 * Affiche le contenu d'une playlisttit
 * PRE: p: pointeur non null vers la playtlist
 * POST: affiche le contenu de la playlist
 */
void printPlaylist (Playlist* p) {
    Noeud *bal = p->tete;
    int trackCnt = 0;
    while (bal != NULL) {
        printf("%d ", ++trackCnt);
        printTrack(bal->val);
        printf("\n");
        bal = bal->suivant;
    }
    if (trackCnt == 0)
        printf("/\n");
}

