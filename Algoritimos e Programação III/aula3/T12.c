/*
Faça um programa em C ANSI que solicite que o usuário digite N elementos
inteiros, positivos ou negativos. N não pode ser maior que 50000.

Usuário deve dizer qual o tamanho de N no início (deve ler do teclado).
(simplesmente encerrar a execução se for um valor de N inválido)

Armazene todos os elementos digitados em um vetor de inteiros antes de
realizar qualquer operação com eles.

Após a digitação e armazenamento de todos os inteiros, para cada inteiro
armazenado no vetor, faça:

a) Ordene o vetor de inteiros
b) Informe se o número é par ou impar. Ignore repetidos.
b) informe se o número é primo e se não for imprima todos os seus divisores (ignore repetidos)
c) calcule um vetor de doubles com a média dos elementos do vetor de inteiros,
   da seguinte forma (exemplo para um vetor com N==10, dez elementos):

   - vetDouble[0] terá a média entre vetINT[0], vetINT[1], vetINT[2], vetINT[3] e vetINT[4]
   - vetDouble[1] terá a média entre vetINT[1], vetINT[2], vetINT[3], vetINT[4] e vetINT[5]
   ...
   - vetDouble[6] terá a média entre vetINT[6], vetINT[7], vetINT[8], vetINT[9] e vetINT[0]
   - vetDouble[7] terá a média entre vetINT[7], vetINT[8], vetINT[9], vetINT[0] e vetINT[1]
   - vetDouble[8] terá a média entre vetINT[8], vetINT[9], vetINT[0], vetINT[1] e vetINT[2]
   (exemplos acima considerando um vetor no qual exista os elementos [1], [2], [3] e [4])

(ou seja, após o último elemento sucedem-se o [0] e [1] como se fosse circular.
CUIDADO PARA VETORES PEQUENOS. Se N for 3 haverá apenas [0], [1] e [2]. A média
de [0] será,  neste caso, entre [0], [1], [2] e, novamente [0], [1]

Observe atentamente um exemplo de uso deste programa:

C:\> exercT12.exe <ENTER>
Quantos elementos você quer? (1 a 50000)
0<ENTER>
Erro. Valor 0 inválido
ENCERRADO

C:\> exercT12.exe <ENTER>
Quantos elementos você quer? (1 a 50000)
-5<ENTER>
Erro. Valor -5 inválido
ENCERRADO

C:\> exercT12.exe <ENTER>
Quantos elementos você quer? (1 a 50000)
534000<ENTER>
Erro. Valor 534000 inválido
ENCERRADO

C:\> exercT12.exe <ENTER>
Quantos elementos você quer? (1 a 50000)
6<ENTER>

Digite 6 números inteiros positivos ou negativos:
1199993 10 55 -7 10 8921<ENTER>

Lido com sucesso 6 inteiros

        -7 => IMPAR  DIVISORES: PRIMO
        10 => PAR    DIVISORES: 2, 5
        55 => IMPAR  DIVISORES: 5, 11
      8921 => IMPAR  DIVISORES: 11, 811
   1199993 => IMPAR  DIVISORES: PRIMO

vetDouble[0] = 1797.80
vetDouble[1] = 241797.80
vetDouble[2] = 241794.40
vetDouble[3] = 241794.40
vetDouble[4] = 241785.40
vetDouble[5] = 240012.20

FIM
C:\>

Ao informar se é par ou impar e os divisores, foi ignorado o segundo valor 10
(ignorar repetidos). Mas não foi ignorado no cálculo do vetor de Doubles.
vetDouble[0] = (-7+10+10+55+8921)/5

C:\> exercT12.exe <ENTER>
Quantos elementos você quer (1 a 50000):
11<ENTER>

Digite  números inteiros positivos ou negativos
123 12490 23 25 12 65309 12 25 123 12490 843371<ENTER>

Lido com sucesso 11 inteiros
        12 => PAR    DIVISORES: 2, 3, 4, 6
        23 => IMPAR  DIVISORES: PRIMO
        25 => IMPAR  DIVISORES: 5
       123 => IMPAR  DIVISORES: 3, 41
     12490 => PAR    DIVISORES: 2, 5, 10, 1249, 2498, 6245
     65309 => IMPAR  DIVISORES: PRIMO
    843371 => IMPAR  DIVISORES: PRIMO

vetDouble[0] = 19.40
vetDouble[1] = 41.60
vetDouble[2] = 63.80
vetDouble[3] = 2557.20
vetDouble[4] = 5050.20
vetDouble[5] = 18107.00
vetDouble[6] = 186756.60
vetDouble[7] = 186734.40
vetDouble[8] = 184238.80
vetDouble[9] = 181745.40
vetDouble[10] = 168688.60

FIM


d) DESAFIO: ao inves de calcular a media entre CINCO elementos, fazer a
media entre os K elementos, sendo K = (tam/20)+1, ou seja, K tem um vigesimo
mais um o tamanho do vetor. Se o vetor tiver 311 elementos, será a media
sobre 15+1=16 elementos. Se o vetor tiver miseros 5 elementos, será a média
entre (5/20)=0+1=1 apenas 1 elemento. Ou seja, dele mesmo.

O teu programa é seguro contra entradas inesperadas?
(digite uma string quando ele espera um inteiro do vetor)
*/

#include <stdio.h>
#define MAXTAM 50000

/*
Só para manter os números identados pegando sua quantidade de caracteres.
Não é a solução mais elegante, mas uma das menos onerosas.
*/
int numLen (int num) {
	int compl = 0; // Complemento em caso de nagativo.
	if (num < 0) compl = 1; // Por ser negativo, faz um complemento na quantidade de caracteres.
	num = abs(num); // Coloca valor absoluto em num. Ex: -10 -> 10

	if (num < 10) return 1 + compl;
	if (num < 100) return 2 + compl;
	if (num < 1000) return 3 + compl;
	if (num < 10000) return 4 + compl;
	if (num < 100000) return 5 + compl;
	if (num < 1000000) return 6 + compl;
	if (num < 10000000) return 7 + compl;
	if (num < 100000000) return 8 + compl;
	if (num < 1000000000) return 9 + compl;

	return 10 + compl;
}

// Retorna uma string com "PRIMO" se for primo ou seus divisores listados se não for.
char *isPrimo (int num) {
	int i;
	char tempStr[numLen(MAXTAM) + 3], // Uma string temporária para guardar o número máximo de caracteres de um número mais "-" se negativo e ", ".
		buffer[MAXTAM];
	char *divisiveis = buffer; // Ponteiro de uma string para conseguir manipular aqui e depois retornar.

	num = abs(num); // Pega o número absoluto de "num" e coloca dentro de "num" (para deixar positivo e encaixar no for).

	strncpy(divisiveis, "", MAXTAM); // Deixa a string vazia para também ser usada no futuro seu tamanho.

	for (i = 2; i < num; i++) {
		if (num % i == 0) {
			snprintf(tempStr, MAXTAM, "%i, ", i); // Formata em uma string temporária para pegar um inteiro e deixar na forma "x, ".
			strncat(divisiveis, tempStr, MAXTAM); // Concatena essa string temporária para a string final.
		}
	}

	if (!strlen(divisiveis)) return "PRIMO"; // Se divisiveis for uma string vazia, retorna que é um primo.

	divisiveis[strlen(divisiveis) - 2] = '\0'; // "Tira" o último ", " da string.
	return divisiveis; // Retorna os divisores.
}

main() {
	// Para iteração em loops.
	int i, j;
	// Variáveis temporárias.
	int temp, // Usado no sort do vetor, no check se já foi processado um valor igual e usado para conta de quantos números para média foram processados.
		limitMedian, // Limite de números usado para definir a quantidade de elementos a serem capturados para a média (usando principalmente no desafio).
		mChars = 0; // Número com a maior quantidade de chars encontrado.
	// Variáveis de armazenamento.
	int elems, // Quantidade de elementos a serem trabalhados.
		vetInt[MAXTAM]; // Vetor com os elementos armazenados.
	double vetDouble[MAXTAM]; // Vetor com os valores das médias.

	printf("Quantos elementos você quer (1 a 50000):\n");
	scanf("%i", &elems);

	if (elems < 1 || elems > 50000) exit(1);

	printf("Digite %i números inteiros positivos ou negativos\n", elems);
	for (i = 0; i < elems; i++) {
		scanf("%i", &vetInt[i]);
	}

	printf("Lido com sucesso %i inteiros\n", elems);
	// Faz o sort do vetor para deixar em ordem crescente.
	for(i = 0; i < elems; i++) {
		if (numLen(vetInt[i]) > mChars) mChars = numLen(vetInt[i]);

		for(j = 0; j < elems - 1; j++) {
			if(vetInt[j] > vetInt[j + 1]) {
				temp = vetInt[j];
				vetInt[j] = vetInt[j + 1];
				vetInt[j + 1] = temp;
			}
		}
	}

	temp = 0;
	for (i = 0; i < elems; i++) {
		if (vetInt[i] == temp && i != 0) continue;

		temp = vetInt[i];

		j = 0;
		while ((j + numLen(vetInt[i])) < (mChars + 4)) {
			printf(" ");
			j++;
		}

		printf("%i => ", vetInt[i]);

		if (vetInt[i] % 2 == 0) { printf("PAR    "); }
		else { printf("IMPAR  "); }

		printf("DIVISORES: %s\n", isPrimo(vetInt[i]));
	}

	printf("\n");

	// limitMedian =  5; // Se quiser usar sem o desafio.
	// Duas linhas abaixo caso quiser usar com o desafio.
	limitMedian = (elems / 20) + 1;
	printf("*** Com o desafio. t=%i. Fazendo media com %i elementos\n", elems, limitMedian);

	for (i = 0; i < elems; i++) {
		temp = i;
		for (j = limitMedian; j > 0; j--) {
			vetDouble[i] += vetInt[temp];
			if (temp + 1 < elems) {
				temp++;
			} else {
				temp = 0;
			}
		}

		vetDouble[i] = vetDouble[i] / limitMedian;
	}
	for (i = 0; i < elems; i++) {
		printf("vetDouble[%i] = %.2lf\n", i, vetDouble[i]);
	}

	printf("\nFIM\n");

	/*
		Diff do arquivo de saída gerado batendo com os arquivos de saída de exemplo tanto do desafio quanto do exerício sem ele.
		Somente verificar os line endings dependendo do método de diff usado (em testes os arquivos de exemplo possuíam line ending CFLF e o garado LF, somente isso gera diferença).
	*/
}
