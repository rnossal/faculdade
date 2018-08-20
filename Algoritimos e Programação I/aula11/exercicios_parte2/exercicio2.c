/*
Faça um programa que mostre os conceitos finais dos alunos de uma classe de 20 alunos, considerando : 
	Os dados de cada aluno (número de matrícula e nota numérica final) serão fornecidos pelo usuário.
	A tabela de conceitos segue abaixo:
		0,0 a 4,9 - D 
		5,0 a 6,9 - C 
		7,0 a 8,9 - B 
		9,0 a 10,0 – A

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main() {
	setlocale(LC_ALL, "Portuguese");

	int cont,
		matricula;
	float nota;
	
	for(cont = 0; cont < 20; cont++) {
		printf("Digite o número da matricula: ");
		scanf("%i", &matricula);
		printf("Digite a nota final: ");
		scanf("%f", &nota);

		if(nota >= 0 && nota <= 4.9) {
			printf("Conceito: D\n");
		} else if(nota >= 5 && nota <= 6.9) {
			printf("Conceito: C\n");
		} else if(nota >= 7 && nota <= 8.9) {
			printf("Conceito: B\n");
		} else if(nota >= 9 && nota <= 10) {
			printf("Conceito: A\n");
		}
	}
	system("pause");
}