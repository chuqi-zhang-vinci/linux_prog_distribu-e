#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "crypt.h"
#include "utils_v1.h"

int main(int argc, char const *argv[])
{
    char* line = readLine();
    printf("%s\n", line);
    line = encrypt(line);
    printf("%s\n", line);
    return 0;
}