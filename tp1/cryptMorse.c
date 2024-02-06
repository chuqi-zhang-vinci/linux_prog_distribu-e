#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define BUF_LEN 256

static const char alpha[26][6] = {
    ".-",   //A
    "-...", //B
    "-.-.", //C
    "-..",  //D
    ".",    //E
    "..-.", //F
    "--.",  //G
    "....", //H
    "..",   //I
    ".---", //J
    "-.-",  //K
    ".-..", //L
    "--",   //M
    "-.",   //N
    "---",  //O
    ".--.", //P
    "--.-", //Q
    ".-.",  //R
    "...",  //S
    "-",    //T
    "..-",  //U
    "...-", //V
    ".--",  //W
    "-..-", //X
    "-.--", //Y
    "--..", //Z
};

char* cryptMorse(char* msg){
	int size = strlen(msg);
	char* res = malloc ((size*6) * sizeof(char));
	int cpt = 0;

	for (int z = 0; z < size; z++)
	{
		int place = (msg[z] - 'A');
		strcpy(res + cpt, alpha[place]);
		cpt += strlen(alpha[place]);
		res[cpt] = ' ';
		cpt += 1;
	}
	return res;
}

char* readLine () {
   char buf[BUF_LEN];
   char* s = NULL;
   bool fin = false;

   while (fgets(buf, BUF_LEN, stdin)) {
      // Traitement d'un bloc de caractères lus sur stdin
      int taille = strlen(buf);
      if (buf[taille-1] == '\n') {
         taille--;
         buf[taille] = '\0';
         fin = true;
      }

      if (s == NULL) {
         // Première allocation de la chaîne s
         s = (char*) malloc((taille+1) * sizeof(char));
         if (s == NULL) return NULL;
         // Copie des caractères du buffer dans s
         strcpy(s,buf);
      } else {
         // Réallocation de la chaîne s
         s = (char*) realloc(s, (strlen(s)+taille+1) * sizeof(char));
         if (s == NULL) return NULL;
         // Concaténation des caractères du buffer à la fin de s
         strcat(s,buf);
      }

      if (fin)
         // Fin de la ligne lue sur stdin
         return s;
   }

   // Cas d'erreur ou de fin de fichier
   return NULL;
}

int main(int argc, char const *argv[])
{
	char* line = readLine();
	printf("%s\n", line);
	line = cryptMorse(line);
	printf("%s\n", line);
	return 0;
}