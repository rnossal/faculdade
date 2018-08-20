#include <stdio.h>
#include <stdlib.h>

main() {
	int a = 10;

	do {
		printf("Valor de a: %i\n", a);
		a++;
	} while (a < 5);

	system("pause");
}