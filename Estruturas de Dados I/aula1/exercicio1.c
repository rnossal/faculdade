#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXMUN 900
#define MAXVET 10

/**
	Gera número aleatórios para preencher o vetor.
	@param vet Vetor que será preenchido.
	@param tam Tamanho desse vetor.
	@return Quantidade de itens percorridos.
*/
int sorteia(int *vet, int tam);

/**
	Percorre o vetor atrás de números pares ou impares e coloca dentro do vetor auxiliar.
	@param vet Vetor que será procurado.
	@param vetImparPar Vetor que será preenchido.
	@param tamVet Tamanho de vet.
	@param tamVetImparPar Tamanho de vetImparPar.
	@param par Se deve procurar por par ou impar.
	@return Quatidade de itens percorridos.
*/
int verificaParImpar(int *vet, int *vetImparPar, int tamVet, int tamVetImparPar, int par);

/**
	Percorre o vetor atrás de números pares e coloca dentro do vetor auxiliar.
	@param vet Vetor que será procurado.
	@param vetPar Vetor que será preenchido.
	@param tamVet Tamanho de vet.
	@param tamVetPar Tamanho de vetPar.
	@return Quatidade de itens percorridos.
*/
int verificaPar(int *vet, int *vetPar, int tamVet, int tamVetPar);

/**
	Percorre o vetor atrás de números impares e coloca dentro do vetor auxiliar.
	@param vet Vetor que será procurado.
	@param vetImpar Vetor que será preenchido.
	@param tamVet Tamanho de vet.
	@param tamVetImpar Tamanho de vetImpar.
	@return Quatidade de itens percorridos.
*/
int verificaImpar(int *vet, int *vetImpar, int tamVet, int tamVetImpar);

/**
	Verifica de um número dado é primo.
	@param num Número a ser checado.
	@return Resultado da checagem.
*/
int ehPrimo(int num);

/**
	Percorre o vetor atrás de números primos e coloca dentro do vetor auxiliar.
	@param vet Vetor que será procurado.
	@param vetPrimo Vetor que será preenchido.
	@param tamVet Tamanho de vet.
	@param tamVetPrimo Tamanho de vetPrimo.
	@return Quatidade de itens percorridos.
*/
int verificaPrimo(int *vet, int *vetPrimo, int tamVet, int tamVetPrimo);

/**
	Percorre o vetor atrás de números em um intervalo de 250 à 650 e coloca dentro do vetor auxiliar.
	@param vet Vetor que será procurado.
	@param vetIntervalo Vetor que será preenchido.
	@param tamVet Tamanho de vet.
	@param tamVetIntervalo Tamanho de vetIntervalo.
	@return Quatidade de itens percorridos.
*/
int verificaIntervalo(int *vet, int *vetIntervalo, int tamVet, int tamVetIntervalo);

/**
	Imprime os dados de um vetor.
	@param vet Vetor que será impresso.
	@param tam Tamanho desse vetor.
*/
int imprime(int *vet, int tam);

int main()
{
	int vet[MAXVET];
	int vetPar[MAXVET];
	int vetImpar[MAXVET];
	int vetPrimo[MAXVET];
	int vetIntervalo[MAXVET];

	sorteia(vet, MAXVET);
	verificaPar(vet, vetPar, MAXVET, MAXVET);
	verificaImpar(vet, vetImpar, MAXVET, MAXVET);
	verificaPrimo(vet, vetPrimo, MAXVET, MAXVET);
	verificaIntervalo(vet, vetIntervalo, MAXVET, MAXVET);

	printf("------NUMEROS------\n");
	imprime(vet, MAXVET);
	printf("-------PARES-------\n");
	imprime(vetPar, MAXVET);
	printf("------IMPARES------\n");
	imprime(vetImpar, MAXVET);
	printf("------PRIMOS-------\n");
	imprime(vetPrimo, MAXVET);
	printf("-----INTERVALO-----\n");
	imprime(vetIntervalo, MAXVET);
}

/**
	Gera número aleatórios para preencher o vetor.
*/
int sorteia(int *vet, int tam)
{
	int i;

	srand(time(NULL));

	for (i = 0; i < tam; i++)
		vet[i] = rand() % (MAXMUN + 1);

	return i;
}

/**
	Percorre o vetor atrás de números pares ou impares e coloca dentro do vetor auxiliar.
*/
int verificaParImpar(int *vet, int *vetImparPar, int tamVet, int tamVetImparPar, int par)
{
	int i, j = 0;

	for (i = 0; i < tamVet && j < tamVetImparPar; i++)
	{
		if (vet[i] % 2 == 0 && par)
		{
			vetImparPar[j] = vet[i];
			j++;
		}
		else if (vet[i] % 2 != 0 && !par)
		{
			vetImparPar[j] = vet[i];
			j++;
		}
	}

	for (; j < tamVetImparPar; j++)
		vetImparPar[j] = -1;

	return j;
}

/**
	Percorre o vetor atrás de números pares e coloca dentro do vetor auxiliar.
*/
int verificaPar(int *vet, int *vetPar, int tamVet, int tamVetPar)
{
	return verificaParImpar(vet, vetPar, tamVet, tamVetPar, 1);
}

/**
	Percorre o vetor atrás de números impares e coloca dentro do vetor auxiliar.
*/
int verificaImpar(int *vet, int *vetImpar, int tamVet, int tamVetImpar)
{
	return verificaParImpar(vet, vetImpar, tamVet, tamVetImpar, 0);
}

/**
	Verifica de um número dado é primo.
*/
int ehPrimo(int num)
{
	int i;

	for (i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
			return 0;
	}
	return 1;
}

/**
	Percorre o vetor atrás de números primos e coloca dentro do vetor auxiliar.
*/
int verificaPrimo(int *vet, int *vetPrimo, int tamVet, int tamVetPrimo)
{
	int i, j = 0;

	for (i = 0; i < tamVet && j < tamVetPrimo; i++)
	{
		if (ehPrimo(vet[i]))
		{
			vetPrimo[j] = vet[i];
			j++;
		}
	}

	for (; j < tamVetPrimo; j++)
		vetPrimo[j] = -1;

	return j;
}

/**
	Percorre o vetor atrás de números em um intervalo de 250 à 650 e coloca dentro do vetor auxiliar.
*/
int verificaIntervalo(int *vet, int *vetIntervalo, int tamVet, int tamVetIntervalo)
{
	int i, j = 0;

	for (i = 0; i < tamVet && j < tamVetIntervalo; i++)
	{
		if (vet[i] >= 250 && vet[i] <= 650)
		{
			vetIntervalo[j] = vet[i];
			j++;
		}
	}

	for (; j < tamVetIntervalo; j++)
		vetIntervalo[j] = -1;

	return j;
}

/**
	Imprime os dados de um vetor.
*/
int imprime(int *vet, int tam)
{
	int i;

	for (i = 0; i < tam; i++)
	{
		if (vet[i] == -1)
			break;

		printf("%i\n", vet[i]);
	}

	return i;
}
