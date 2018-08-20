/*
Objetivo: strings, mas sem usar as funções já existentes. A única função
de manipulação de string permitida é para leitura, podendo usar o fgets
(que está em stdio.h> ou a função divulgada pelo professor.
Todas as demais devem ser implementadas

********  EMBASAMENTO ********
Considera-se um palíndromo palavras ou frases inteiras que são iguais
mesmo lidas ao contrário. A palavra "OVO" é um palíndromo.

A frase "SOCORRAM-ME, SUBI NO ONIBUS EM MARROCOS" é uma das mais
conhecidas da nossa lingua. No caso de frases deve-se considerar como
palíndromo mesmo ignorando espaços e pontuações.

Existem palíndromos que fazem sentido e alguns que são apenas palavras
soltas, sem nexo, como classificou Rômulo Marinho. Um exemplo de
palíndromo sem nexo seria: "Olé, maracuja, caju, caramelo".

Existem muitos palíndromos escritos que são obras de arte, por serem
enormes e ou poéticos. Um dos mais intrigantes exemplos de palíndromos,
chamado de perfeito, é em LATIN:

S A T O R
A R E P O
T E N E T
O P E R A
R O T A S

Se você estiver usando fonte FIXA, verá que forma um quadrado. Observe
que ele é palíndromo mesmo que lido em qualquer diração (menos diagnonal).

Palíndromos que não fazem sentido algum são fáceis de fazer e podem até ser
feitos por computador. Porém frases ou mesmo poesias, que tenham lógica
e coexão, são bem mais difíceis. O escritor "Demetri Martin" construiu
um poema em inglês com 224 palavras, sendo considerado, atualmente, um
dos maiores palíndromos com nexo do mundo
https://ronaldobressane.com/2009/03/08/o-maior-palindromo-do-mundo/

Já um outro tem mais de 17 mil palavras (74 mil letras), mas são palavras
soltas, sem  muita coexão. Mas não deixa de ser um grande mérito
(http://norvig.com/pal17txt.html)

*************  DEFINIÇÃO *************
Faça um programa que:

a) Solicite ao usuário que digite textos até uma quebra de linha.
Cada texto poderá ter até 150000 caracteres. A primeira coisa que ele
irá digitar será uma string de término que deverá ter 3 letras no mínimo.

b) após a digitação da string de término, para cada texto digitado, se
for a string de término desconsiderando maiúsculas e minúsculas,
encerre o programa (item c).

Se não for a string de termino imprima se ele é ou não é um palíndromo
(além de fazer contabilizações requeridas no item c)

c) Ao terminar a execução, porque foi digitada a string de término,
imprima um pequeno relatório (ver formatação).

Este relatório terá:
  - total de frases digitadas
  - maior frase em tamanho digitada (strlen)
  - menor frase em tamanho digitada (strlen)
  - total de letras minusculas digitadas (soma de todas as frases)
  - total de letras maiusculas digitadas (soma de todas as frases)
  - Quantidade de letras do maior palindromo encontrado
    (maior em quantidade de letras. "O,.;V. , . , O" não deve ser
    considerado maior que "O SSO", pois apesar do tamanho (strlen)
    da primeira ser maior, o que importa são letras.

C:\> exercT14.exe<ENTER>
# Qual a frase que você usará para encerrar?
de<ENTER>

# ERRO. A frase de término precisa ser maior
# Qual a frase que você usará para encerrar?
FI<ENTER>

# ERRO. A frase de término precisa ser maior
# Qual a frase que você usará para encerrar?
Quero terminar<ENTER>

# [1] Digite frase de até 150000 caracteres.
# [1] Digite "Quero terminar" para encerrar o programa
O  v o<ENTER>
  1 => PALINDROMO

# [2] Digite frase de até 150000 caracteres.
# [3] Digite "Quero terminar" para encerrar o programa
Socorram-me, subi no oniBus Em Marrocos<ENTER>
  2 => PALINDROMO

# [3] Digite frase de até 150000 caracteres.
# [3] Digite "Quero terminar" para encerrar o programa
Macaco gosta de subir em arvores<ENTER>
  3 => NAO EH PALINDROMO

# [4] Digite frase de até 150000 caracteres.
# [4] Digite "Quero terminar" para encerrar o programa
Ole, maracuja, caju, caramelo<ENTER>
  4 => PALINDROMO

# [5] Digite frase de até 150000 caracteres.
# [5] Digite "Quero terminar" para encerrar o programa
QUERo terMInar<ENTER>

4 frases digitadas
Maior frase = "Socorram-me, subi no oniBus Em Marrocos"
Menor frase = "O  v o"
78 letras minusculas
7 letras maiusculas
32 letras tem o maior palindromo digitado

C:>


************** OBSERVAÇÕES ****************
1) Acentos: em função das diferentes formas de acentuação existentes,
optou-se em não trabalhar com caracteres acentuados.
O palíndromo "Olé, maracuja, caju, caramelo" foi identificado como sendo
um palíndromo porque "Olé" foi digitado SEM ACENTO. Se digitar com
acento o programa pode dizer que NÃO É PALÍNDROMO, pois não considera
'é' igual ao 'e' (tratar isso envolveria conversão de caracteres acentuados
para não acentuados, o que foge do escopo deste exercício).
Também as saídas que não são opcionais (não tem #) não se colocou acentos
pelo mesmo motivo ("NAO EH PALINDROMO" ao invés de "NÃO É PALÍNDROMO")
Lembrando que linhas de saída que começam com # são ignoradas.

2) A frase de término pode ser qualquer coisa e ainda dentro do tamanho
máximo de 150 mil caracteres. Observe na definição e no exemplo que
não importa se letra maiúscula ou minúscula. Se a frase de término é
"Quero terminar", "QUERO terMInar" bate e encerra. Mas se for digitado
"Quero  terminar" (dois espaços em branco entre as palavras) ai não
bate e não encerra.

3) Dica: não será aceito se usar funções já existentes. Mas como etapa
da construção você pode usar estas funções. Depois de sucesso no exercício,
ai tem o desafio de implementar uma a uma as funções que usou. Atenção:
o compiladora não deixará você usar o mesmo nome das existentes. Se
você usou strcasecmp e agora vai implementar ela, deverá chamar de
outro nome (comparasemcase ou algo assim).
*/

#include <stdio.h>

#define MAXCHARS 150001

// Struct para guardar as informações porque sim \o/
typedef struct {
	int phrases;
	char biggerPhrase[MAXCHARS];
	char smallerPhrase[MAXCHARS];
	int lowercaseCount;
	int uppercaseCount;
	int wordCountBiggerPhrase;
} relInfo;

// Struct para guardar as informações de case de uma expressão (usada na função de contador de case).
typedef struct {
	int lowercaseCount;
	int uppercaseCount;
	int total;
} wordCase;

// Lê a tela para a string dada e retorna a quantidade lida.
// (Peguei tua função mesmo, Elgio. Ela é boa)
int read(char str[], int maxRead) {
	int i;
	char letter;

	for (i = 0; i < (maxRead - 1); i++) {
		letter = fgetc(stdin);

		if ((letter == '\n') && (i == 0)) {
			i = i - 1;
			continue;
		}

		if (letter == '\n')
			break;
		str[i] = letter;
	}

	str[i] = 0;

	return i;
}

// Pega uma string de destino e sobrescreve o que tem na de origem até a quantidade máxima de caracteres definido.
int copy(char strDest[], char strOrig[], int maxCopy) {
	int i;

	for (i = 0; i < maxCopy; i++) {
		if (strOrig[i] == 0)
			break;
		strDest[i] = strOrig[i];
	}
	strDest[i] = 0;

	return i;
}

// Retorna o tamanho da string passada.
int length(char str[]) {
	int len;

	for (len = 0; str[len] != 0; ++len);

	return len;
}

// Conta quantas letras maiúsculas e quantas minúsculas existem na string passada.
wordCase countCase(char str[]) {
	int i, len = length(str);
	wordCase count = {0, 0};

	for (i = 0; i < len; i++) {
		if (str[i] >= 65 && str[i] <= 90) {
			count.uppercaseCount++;
			count.total++;
		}
		if (str[i] >= 97 && str[i] <= 122) {
			count.lowercaseCount++;
			count.total++;
		}
	}

	return count;
}

// Checa se a frase de entrada é palíndromo.
int isPalindrome(char str[]) {
	int i, len = length(str);
	char a, b;

	for (i = 0; i < len; i++) {
		a = str[i];
		b = str[len - i - 1];

		if (a >= 97 && a <= 122)
			a -= 32;
		if (b >= 97 && b <= 122)
			b -= 32;

		if (a != b)
			return 0;
	}

	return 1;
}

// Compara igualdade entre duas strings (não é case sensitive).
int equals(char str[], char strToCompare[]) {
	int i, len = length(str);
	char a, b;

	if (len != length(strToCompare)) return 0;

	for (i = 0; i < len; i++) {
		a = str[i];
		b = strToCompare[i];

		if (a >= 97 && a <= 122)
			a -= 32;
		if (b >= 97 && b <= 122)
			b -= 32;

		if (a != b) return 0;
	}

	return 1;
}

// Pega a string passada, remove o que não for letra e retorna a nova string (ignora também códigos ASCII extendidos, eg: acentos).
char *formatToOnlyLetters(char str[]) {
	int i, j = 0, len = length(str);
	char buffer[MAXCHARS];
	char *strOut = buffer;

	for (i = 0; i < len; i++) {
		if (str[i] >= 97 && str[i] <= 122 || str[i] >= 65 && str[i] <= 90) {
			strOut[j] = (unsigned char)str[i];
			j++;
		}
	}
	strOut[j] = 0;

	return strOut;
}

main() {
	char exitPhrase[MAXCHARS];
	char readPhrase[MAXCHARS];
	relInfo rel = {
		0,
		{0},
		{0},
		0,
		0,
		0
	};
	wordCase countRead;

	do {
		printf("# Qual a frase que você usará para encerrar?\n");
		read(exitPhrase, MAXCHARS);
		if (length(exitPhrase) < 3) {
			printf("# ERRO. a frase de termino precisa ser maior\n");
		}
	} while (length(exitPhrase) < 3);

	printf("\n");

	do {
		printf("# [%d] Digite frase de até %d caracteres.\n", rel.phrases + 1, MAXCHARS - 1);
		printf("# [%d] Digite \"%s\" para encerrar o programa\n", rel.phrases + 1, exitPhrase);
		read(readPhrase, MAXCHARS);

		if (!equals(exitPhrase, readPhrase)) {
			countRead = countCase(readPhrase);

			if (isPalindrome(formatToOnlyLetters(readPhrase))) {
				printf("%3d => PALINDROMO\n\n", rel.phrases + 1);
			} else {
				printf("%3d => NAO EH PALINDROMO\n\n", rel.phrases + 1);
			}

			if (length(rel.smallerPhrase) == 0) {
				copy(rel.smallerPhrase, readPhrase, MAXCHARS);
			}

			if (length(readPhrase) > length(rel.biggerPhrase)) {
				copy(rel.biggerPhrase, readPhrase, MAXCHARS);
				rel.wordCountBiggerPhrase = countRead.total;
			}
			if (length(readPhrase) < length(rel.smallerPhrase)) {
				copy(rel.smallerPhrase, readPhrase, MAXCHARS);
			}

			rel.lowercaseCount += countRead.lowercaseCount;
			rel.uppercaseCount += countRead.uppercaseCount;
			rel.phrases++;
		}

	} while (!equals(exitPhrase, readPhrase));

	printf("\n%d frases digitadas\n"
			"Maior frase = \"%s\"\n"
			"Menor frase = \"%s\"\n"
			"%d letras minusculas\n"
			"%d letras maiusculas\n"
			"%d letras o maior palindromo digitado\n", rel.phrases, rel.biggerPhrase, rel.smallerPhrase, rel.lowercaseCount, rel.uppercaseCount, rel.wordCountBiggerPhrase);
}
