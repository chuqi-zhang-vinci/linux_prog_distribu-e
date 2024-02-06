#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "cryptPolybe.h"
#include "utils_v1.h"

int main(int argc, char const *argv[])
{
    char* line = readLine();
    printf("%s\n", line);
    line = encryptPolybe(line);
    printf("%s\n", line);
    return 0;
}