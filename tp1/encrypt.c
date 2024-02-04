#include "utils_v1.h"
#include "crypt.h"

int main(int argc, char const *argv[])
{
	char* line = readLine();

	printf("line : %s\n", line);

	line = encrypt(line);

	printf("line : %s\n", line);
	return 0;
}