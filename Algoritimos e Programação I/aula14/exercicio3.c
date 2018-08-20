/*
Faça um programa que leia dois vetores X1 e X2, ambos inteiros e com 10 posições. O programa deve, a seguir, preencher e escrever o vetor:
a) união : contém todos os valores de X1 e X2, sem repetição;
b) intersecção: contém apenas os valores em comum de X1 e X2, sem repetição;
c) diferença: contém todos os valores de X1 (sem repetição) que não estão em X2.
d) escreva o vetor X1 e X2 invertidos, começando do último número até o primeiro.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define QTD_VETS 10


main() {
	setlocale(LC_CTYPE, "Portuguese");

	int vet1[QTD_VETS],
		vet2[QTD_VETS],
		uniao[QTD_VETS * 2],
		interseccao[QTD_VETS],
		diferenca[QTD_VETS],
		i,
		j,
		k,
		repet,
		repet2,
		contU = 0,
		contI = 0,
		contD = 0;

	printf("Preencha os dois vetores com 10 valores inteiros respectivamente cada:\n");
	for(i = 0; i < QTD_VETS; i++) {
		printf("Preencha o primeiro vetor com o %iº número: ", i + 1);
		scanf("%i", &vet1[i]);
		printf("Preencha o segundo vetor com o %iº número: ", i + 1);
		scanf("%i", &vet2[i]);
	}//Esquece daqui para cima

	for(i = 0; i < QTD_VETS; i++) {
		repet = 0;
		for(j = 0; j < QTD_VETS; j++) {
			if(vet1[i] == vet2[j]) {
				repet++;
			}
		}//Conta se existem números iguais entre vet1 e vet2
		if(repet == 0) {
			for(j = 0; j < contU; j++) {
				if(vet1[i] == uniao[j]) {
					repet++;
				}
			}//Olha se já não está na união
			for(k = 0; k < contD; k++) {
				if(vet1[i] == diferenca[k]) {
					repet2++;
				}
			}//Olha se já não está na diferença
			if(repet == 0) {
				uniao[contU] = vet1[i];
				contU++;
			}//Se não estiver coloca na união
			if(repet2 == 0) {
				diferenca[contD] = vet1[i];
				contD++;
			}//Se não estiver coloca na diferença
		} else {
			repet = 0;
			repet2 = 0;
			for(j = 0; j < contI; j++) {
				if(vet1[i] == interseccao[j]) {
					repet++;
				}
			}//Olha se já não está na intersecçao
			if(repet == 0) {
				interseccao[contI] = vet1[i];
				contI++;
			}//Se não estiver coloca na intersecçao
		}//Se não tiver em vet2 e se estiver em vet2
	}//Percorre vet1
	for(i = 0; i < QTD_VETS; i++) {
		repet = 0;
		for(j = 0; j < contU; j++) {
			if(vet2[i] == uniao[j]) {
				repet++;
			}
		}//Olha se já não está na união
		if(repet == 0) {
			uniao[contU] = vet2[i];
			contU++;
		}//Se não estiver coloca
	}//Percorre vet2

	printf("A união dos valores informados nos vetores apresenta os números:\n\t");
	for(i = 0; i < contU; i++) {
		printf("%i ", uniao[i]);
	}
	printf("\nA intersecção dos valores informados nos vetores apresenta os números:\n\t");
	for(i = 0; i < contI; i++) {
		printf("%i ", interseccao[i]);
	}
	printf("\nA difereça dos valores informados no primeiro vetor para o segundo apresenta os números:\n\t");
	for(i = 0; i < contD; i++) {
		printf("%i ", diferenca[i]);
	}
	printf("\nOs dois vetores invertidos se dão por:\n\t");
	printf("Primeiro vetor: ");
	for(i = QTD_VETS - 1; i >= 0 ; i--) {
		printf("%i ", vet1[i]);
	}
	printf("\n\tSegundo vetor: ");
	for(i = QTD_VETS - 1; i >= 0; i--) {
		printf("%i ", vet2[i]);
	}

	printf("\n");
	system("pause");
}