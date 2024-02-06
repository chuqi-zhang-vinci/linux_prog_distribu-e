#ifndef _CRYPTPOLYBE_H_
#define _CRYPTPOLYBE_H_

/**
 * PRE : un tableau de char à crypté
 * POST : le message sera crypté par la méthode polybe
 * RES : afficher les chiffres de polybe
 */

/* déclaration des fonctions*/
char* encryptPolybe(char* msg);

/**
 * PRE : un tableau de char à décrypté
 * POST : le message sera décrypté par la méthode polybe
 * RES : affiche les caractères
 */

/* déclaration des fonctions*/
char* decryptPolybe(char* msg);

#endif