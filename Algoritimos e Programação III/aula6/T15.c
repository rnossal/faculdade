/*
Faça um programa em C que leia todos os argumentos passados para
a função main e diga se cada um dele é ou não é um palindromo.

Ao final diga quantas frases tinham nos argumentos e quantas
destas eram palíndromos.

C:\> exercT15.exe<ENTER>
ERRO
# Faltou passar parametros
# FIM

C:\> exercT15.exe ovo Subi no Onibus "Socorram-me, subi no oniBus Em Marrocos"
       PALINDROMO = "OVO"
NAO EH PALINDROMO = "SUBI"
NAO EH PALINDROMO = "NO"
NAO EH PALINDROMO = "ONIBUS"
       PALINDROMO = "SOCORRAM-ME, SUBI NO ONIBUS EM MARROCOS"
5 FRASES
2 PALINDROMOS
# FIM

C:\>
*/

#include <stdio.h>

// Retorna o tamanho da string passada.
int length(char str[]) {
	int len;

	for (len = 0; str[len] != 0; ++len);

	return len;
}

// Retorna a string passada em uppercase (chars fora do range de letras minúsculas sem caracteres especiais só serão copiados).
int upper(char str[]) {
	int i;

	for (i = 0; str[i]; i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] = str[i] - 32;
		}
	}

	return i;
}

// Checa se a frase de entrada é palíndromo (vai checar por letras minúsculas para saber se dese continuar, mas ainda assim vai testar igualdade, ou seja, usa o upper ;) ).
int isPalindrome(char str[]) {
	int i = 0,
		j = (length(str) - 1);

	while (i <= j) {
		if (!(str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')) {
			i++;
			continue;
		}
		if (!(str[j] >= 'a' && str[j] <= 'z' || str[j] >= 'A' && str[j] <= 'Z')) {
			j--;
			continue;
		}

		if (str[i] != str[j]) {
			return 0;
		}

		i++;
		j--;
	}

	if (str[i] == 0 || str[j] == 0) { // Vai isso aqui mesmo que resolve o "easter egg" do exercício.
		return 0;
	}

	return 1;
}

int main(int argc, char const *argv[]) {
	int i,
		countPalindrome = 0;

	if (argc < 2) {
		printf("ERRO\n# Faltou passar parametros\n# FIM\n");
		return 0;
	}

	for (i = 1; i < argc; i++) {
		upper(argv[i]);
		if (isPalindrome(argv[i])) {
			printf("       PALINDROMO = \"");
			countPalindrome++;
		} else {
			printf("NAO EH PALINDROMO = \"");
		}
		printf("%s\"\n", argv[i]);
	}

	printf("%d FRASES\n"
			"%d PALINDROMOS\n"
			"# FIM\n", argc - 1, countPalindrome);
}
