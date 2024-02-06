#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "cryptPolybe.h"

static char square[8][8] =
{{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'},
{'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'},
{'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X'},
{'Y', 'Z', '0', '1', '2', '3', '4', '5'},
{'6', '7', '8', '9', ' ', '!', '"', '#'},
{'$', '%', '&', '\'', '(', ')', '*', '+'},
{',', '-', '.', '/', ':', ';', '<', '='},
{'>', '?', '@', '[', '\\', ']', '^', '_'}};


char* encryptPolybe(char* msg) {
    int size = strlen(msg);
    char* res = malloc (size * 2 * sizeof(char));
    int cpt = 0;
    for (int z = 0; z < size; z++)
    {
       for (int i = 0; i < 8; i++)
       {
           for (int j = 0; j < 8; j++)
           {
                if(msg[z] == square[i][j]){
                    res[cpt] = i + '0';
                    cpt += 1;
                    res[cpt] = j + '0';
                    cpt += 1;
                }
            }
       }
    }
    return res;
}

char* decryptPolybe(char* msg) {
   int size = strlen(msg);
   char* res = malloc ((size / 2) * sizeof(char));
   int cpt = 0;
   for (int z = 0; z < size; z += 2)
   {
        res[cpt] = square[msg[z] - '0'][msg[z+1] - '0'];
        cpt += 1;
   }
   return res;
}