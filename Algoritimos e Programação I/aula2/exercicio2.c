/*
Faça um algoritmo que leia 4 notas e informa a média delas.
*/
#include <stdio.h>
int main (void) {
	float nota1, nota2, nota3, nota4;
	printf("Digite a primeita nota:\n");
	scanf("%f", &nota1);
	printf("Digite a segunda nota:\n");
	scanf("%f", &nota2);
	printf("Digite a terceira nota:\n");
	scanf("%f", &nota3);
	printf("Digite a quarta nota:\n");
	scanf("%f", &nota4);

	float media = (nota1 + nota2 + nota3 + nota4) / 4;

	printf("Media das notas: %f\n", media);
	system("pause");
}
