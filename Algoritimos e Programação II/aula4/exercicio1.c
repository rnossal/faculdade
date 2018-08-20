#include <stdio.h>
#include <string.h>

#define STRTAM 50

main() {
	char st1[STRTAM],
		st2[STRTAM];

	int teste;

	strncpy(st1, "APenas um pequeno teste", STRTAM); //Copia uma string para a outra
	strncpy(st2, st1, STRTAM);

	teste = strcmp(st1, st2); //Checa se são iguais (0 quer dizer serem iguais)

	strncpy(st2, "Apenas um Pequeno teste", STRTAM);
	teste = strncmp(st1, st2, 7); //Nessa função e com parâmetro só checa até o 7º caractere

	teste = strcasecmp(st1, st2); //Checa se as duas são iguais, mas sem ser case sensitive

	teste = strncasecmp(st1, st2, 10); //Checa se as duas são iguais, mas sem ser case sensitive até o caractere definido

	if (teste == 0) {
		printf("Sao iguais\n");
	}
	if (teste > 0) {
		printf("sr1 eh maior\n");
	}
	if (teste < 0) {
		printf("st2 eh maior\n");
	}

	//strncat(st1, st2, 20); //Concatena a segunda na primeira e somente a quantidade que foi definida no terceiro parâmetro
	printf("%s\n", st1);

	strtok(st1, "no"); //Tira da primeira ocorrência em diante na string passada (procura letra por letra)
	printf("%s\n", st1);
}
