#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "track.h"


Track* initTrack (char* artiste, char* titre, int duree) {
    // TODO
    Track* track = (Track*)malloc (sizeof(Track));

    strncpy(track->artiste, artiste, ARTISTE_LENGTH);
    strncpy(track->titre, titre, TITLE_LENGTH);
    track->duree = duree;

    return track;
}

int compareTrack (Track* t1, Track* t2) {
    // TODO
    int artiste_val = strncmp(t1->artiste, t2->artiste, ARTISTE_LENGTH);
    int titre_val = strncmp(t1->titre, t2->titre, TITLE_LENGTH);
    int duree_val = t1->duree - t2->duree;

    if(artiste_val < 0 || titre_val < 0 || duree_val < 0){
        return -1;
    } else if (artiste_val == 0 && titre_val == 0 && duree_val == 0){
        return 0;
    } else {
        return 1;
    }
}

void printTrack (Track *t) {
    printf("%s - %s - %d", t->artiste, t->titre, t->duree);
}

