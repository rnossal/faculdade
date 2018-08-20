#include <stdio.h>

parImpar (int x) {
	if (x % 2 == 0) {
		printf("%d PAR\n", x);
	} else {
		printf("%d IMPAR\n", x);
	}
}
double media (int x, int y) {
	double d;

	d = x + y;
	d = d / 2;
	// printf("A media de %d com %d = %f\n", d);
	return(d);
}

main () {
	int a;

	for (a = 0; a < 30; a++) {
		parImpar(a);
	}

	int c,
		d;

	printf("Digite dois numeros\n");
	scanf("%d", &c);
	scanf("%d", &d);

	double temp = media(c, d);
	printf("A funcao media me retornou %f\n", temp);
}
