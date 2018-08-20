#include <stdio.h>
#include <string.h>

#define STRMAX 10

main() {
	char sr1[STRMAX];
	int t;

	printf("Digite uma string de até 9 cars:\n");

	fgets(sr1, STRMAX, stdin);

	printf("A string tem %d caracteres\n", strlen(sr1));
	printf("A string é: %s", sr1);
}
