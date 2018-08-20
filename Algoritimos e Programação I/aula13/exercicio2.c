/*
Faça um programa que leia os números sorteados em uma loteria em um vetor de 5 posições.
A seguir, preencha um vetor P com o número de acertos de 20 apostadores.
Para preencher o vetor P, o programa deve perguntar para cada apostador os números nos quais ele apostou.
O programa confere e conta o número de acertos guardando esse número em P.
A seguir, o programa deve escrever a posição dos apostadores vencedores (acertaram os 5 números).
Se não houver vencedor, o programa deve escrever a posição dos apostadores que mais pontos fizeram (4 acertos, ...).
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define QTD_NUMS 5
#define QTD_P 20


main() {
	setlocale(LC_CTYPE, "Portuguese");

	int nums_sorteados[QTD_NUMS],
		p[QTD_P],
		acertos,
		num,
		i,
		j,
		k,
		max_acertos = 0;
	
	printf("Digite os 5 números sorteados na loteria:\n\n");
	for(i = 0; i < QTD_NUMS; i++) {
		printf("Digite o %iº número: ", i + 1);
		scanf("%i", &nums_sorteados[i]);
	}
	printf("Agora digite os números apostados de 20 apostadores:\n\n");
	for(i = 0; i < QTD_P; i++) {
		acertos = 0;
		for(j = 0; j < QTD_NUMS; j++) {
			printf("Digite o %iº número apostado pelo %iº apostador: ", j + 1, i + 1);
			scanf("%i", &num);
			for(k = 0; k < QTD_NUMS; k++) {
				if(num == nums_sorteados[k]) {
					acertos++;
				}
			}
		}
		p[i] = acertos;
		if(acertos > max_acertos) {
			max_acertos = acertos;
		}
	}
	if(max_acertos == 0) {
		printf("Não houveram apostadores com acertos.\n");
	} else if (max_acertos == 5) {
		printf("Os vencedores (com 5 acertos) estão nas posições ");
	} else {
		printf("Não houveram apostadores com 5 acertos.\nOs apostadores com o número de acertos mais próximos (%i) estão nas posições ", max_acertos);
	}
	if(max_acertos != 0) {
		for(i = 0; i < QTD_P; i++) {
			if(p[i] == max_acertos) {
				printf("%i ", i);
			}
		}
		printf("da lista.\n");
	}
	system("pause");
}