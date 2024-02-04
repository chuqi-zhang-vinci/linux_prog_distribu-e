#include "utils_v1.h"
#include "crypt.h"

int main(int argc, char const *argv[])
{
	char* line = readLine();

	printf("line : %s\n", line);

	line = decrypt(line);

	printf("line : %s\n", line);
	return 0;
}