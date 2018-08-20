/*
Dada duas sequências de 15 (quinze) números quaisquer, calcule o produto (Vet1[n]*Vet2[n]) de cada número com o seu correspondente. Para isso, utilize três vetores: dois para armazenar as duas sequências de números (Vet1 e Vet2) e outro para armazenar o produto (VetP). Ao final apresente os três vetores devidamente identificados ao usuário.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define QTD_VET1 15
#define QTD_VET2 15
#define QTD_PRODVET 15

main() {
	setlocale(LC_ALL, "Portuguese");

	int i,
		vet1[QTD_VET1],
		vet2[QTD_VET2],
		prodVet[QTD_PRODVET];

	for(i = 0; i < QTD_VET1; i++) {
		printf("Diga o %iº valor do primeiro vetor: ", i + 1);
		scanf("%i", &vet1[i]);
	}
	for(i = 0; i < QTD_VET2; i++) {
		printf("Diga o %iº valor do segundo vetor: ", i + 1);
		scanf("%i", &vet2[i]);
	}
	for(i = 0; i < QTD_PRODVET; i++) {
		prodVet[i] = vet1[i] * vet2[i];
	}
	for(i = 0; i < QTD_PRODVET; i++) {
		printf("%i * %i = %i\n", vet1[i], vet2[i], prodVet[i]);
	}
}
