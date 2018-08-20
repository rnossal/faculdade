#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 50

struct nodo
{
	int dados;
	struct nodo *prox;
};

struct header
{
	struct nodo *inicio;
	int qtd;
	struct nodo *fim;
};

struct nodod
{
	struct nodod *ant;
	int dados;
	struct nodod *prox;
};

struct headerd
{
	struct nodod *inicio;
	int qtd;
	struct nodod *fim;
};

int criaHeaderLSE(struct header **header)
{
	struct header *novo = (struct header *)malloc(sizeof(struct header));

	if (novo != NULL)
	{
		novo->inicio = NULL;
		novo->qtd = 0;
		novo->fim = NULL;

		*header = novo;
	}

	return 0;
}

int criaHeaderLDE(struct headerd **header)
{
	struct headerd *novo = (struct headerd *)malloc(sizeof(struct headerd));

	if (novo != NULL)
	{
		novo->inicio = NULL;
		novo->qtd = 0;
		novo->fim = NULL;

		*header = novo;
	}

	return 0;
}

int insereDireiraLSE(struct header **header, int v)
{
	if (*header != NULL)
	{
		struct nodo *novo = (struct nodo *)malloc(sizeof(struct nodo));

		if (novo != NULL)
		{
			novo->dados = v;
			novo->prox = NULL;

			if ((*header)->inicio == NULL)
			{
				(*header)->inicio = novo;
			}
			else
			{
				(*header)->fim->prox = novo;
			}

			(*header)->fim = novo;
			(*header)->qtd++;

			return 1;
		}
	}

	return 0;
}

int encontraMaiorValorLSE(struct header **header)
{
	int val = -1;

	if (*header != NULL)
	{
		struct nodo *aux = (*header)->inicio;

		if (aux != NULL)
		{
			do
			{
				if (aux->dados > val)
				{
					val = aux->dados;
				}

				aux = aux->prox;
			} while (aux != NULL);
		}
	}

	return val;
}

int insereInicioMaiorValorLDE(struct headerd **headerd, struct header **header)
{
	int psq = encontraMaiorValorLSE(header);

	return insereEsquerdaLDE(headerd, psq);
}

int insereAntesMaiorValorLSE(struct header **header, int val)
{
	int psq = encontraMaiorValorLSE(header);

	if (*header != NULL)
	{
		struct nodo *ant = NULL;
		struct nodo *aux = (*header)->inicio;

		if (aux != NULL)
		{
			do
			{
				if (aux->dados == psq)
				{
					struct nodo *novo = (struct nodo *)malloc(sizeof(struct nodo));

					if (novo != NULL)
					{
						novo->dados = val;

						if (ant == NULL)
						{
							(*header)->inicio = novo;
						}
						else
						{
							ant->prox = novo;
						}
						novo->prox = aux;

						(*header)->qtd++;

						return 1;
					}
					else
					{
						return -1;
					}
				}

				ant = aux;
				aux = aux->prox;
			} while (aux != NULL);
		}
	}

	return 0;
}

int insereEsquerdaLDE(struct headerd **header, int v)
{
	struct nodod *novo = (struct nodod *)malloc(sizeof(struct nodod));

	if (novo != NULL)
	{
		novo->ant = NULL;
		novo->dados = v;
		novo->prox = (*header)->inicio;

		if ((*header)->inicio == NULL)
		{
			(*header)->fim = novo;
		}
		else
		{
			((*header)->inicio)->ant = novo;
		}
		(*header)->inicio = novo;

		(*header)->qtd++;

		return 1;
	}

	return 0;
}

int imprimeLSE(struct header **header)
{
	if (*header != NULL)
	{
		struct nodo *aux = (*header)->inicio;

		if (aux != NULL)
		{
			do
			{
				printf("%i ", aux->dados);
				aux = aux->prox;
			} while (aux != NULL);

			printf("\n");

			return 1;
		}
	}

	return 0;
}

int imprimeLDE(struct headerd **header)
{
	if (*header != NULL)
	{
		struct nodod *aux = (*header)->inicio;

		if (aux != NULL)
		{
			do
			{
				printf("%i ", aux->dados);
				aux = aux->prox;
			} while (aux != NULL);

			printf("\n");

			return 1;
		}
	}

	return 0;
}

int excluiNodoLDE(struct headerd **header, int v)
{
	struct nodod *aux = (*header)->inicio;
	struct nodod *del;

	if (aux != NULL)
	{
		do
		{
			if (aux->dados == v)
			{
				del = aux;

				if (del->ant == NULL)
				{
					(*header)->inicio = del->prox;

					if (del->prox == NULL)
					{
						(*header)->fim = NULL;
					}
					else
					{
						del->prox->ant = NULL;
					}
				}
				else
				{
					del->ant->prox = del->prox;

					if (del->prox == NULL)
					{
						(*header)->fim = del->ant;
					}
					else
					{
						del->prox->ant = del->ant;
					}
				}

				free(del);

				(*header)->qtd--;

				return 1;
			}

			aux = aux->prox;
		} while (aux != NULL);
	}

	return 0;
}

int qtdLDE(struct headerd **header)
{
	return (*header)->qtd;
}

int qtdLSE(struct header **header)
{
	return (*header)->qtd;
}

int excluiLSE(struct header **header)
{
	if (header != NULL)
	{
		if ((*header)->inicio != NULL)
		{
			struct nodo *aux = (*header)->inicio;
			struct nodo *del = aux;

			while (aux != NULL)
			{
				free(del);
				del = aux = aux->prox;
			}

			free(*header);
			*header = NULL;
		}
	}
	return 0;
}

int excluiLDE(struct headerd **header)
{
	if (header != NULL)
	{
		if ((*header)->inicio != NULL)
		{
			struct nodod *aux = (*header)->inicio;
			struct nodod *del = aux;

			while (aux != NULL)
			{
				free(del);
				del = aux = aux->prox;
			}

			free(*header);
			*header = NULL;
		}
	}
	return 0;
}

int main()
{
	int i = 0;
	struct header *headerLSE = NULL;
	struct headerd *headerLDE = NULL;

	srand(time(NULL));

	criaHeaderLSE(&headerLSE);
	criaHeaderLDE(&headerLDE);

	for (i = 0; i < TAM; i++)
	{
		int rnd = rand() % 100;

		insereDireiraLSE(&headerLSE, i);
		insereEsquerdaLDE(&headerLDE, i);
	}

	printf("Valores LSE:\n");
	imprimeLSE(&headerLSE);
	printf("Valores LDE:\n");
	imprimeLDE(&headerLDE);

	int valIns;
	printf("Digite um valor a ser inserido antes do maior valor da LSE: ");
	scanf("%i", &valIns);

	insereAntesMaiorValorLSE(&headerLSE, valIns);

	printf("Valores LSE:\n");
	imprimeLSE(&headerLSE);
	printf("Valores LDE:\n");
	imprimeLDE(&headerLDE);

	int valDel;
	printf("Digite um valor a ser deletado da LDE: ");
	scanf("%i", &valDel);

	int statusExcluiNodo = excluiNodoLDE(&headerLDE, valDel);

	if (statusExcluiNodo == 0)
	{
		printf("O valor selecionado não foi encontrado.\n");
	}

	printf("Valores LSE:\n");
	imprimeLSE(&headerLSE);
	printf("Valores LDE:\n");
	imprimeLDE(&headerLDE);

	insereInicioMaiorValorLDE(&headerLDE, &headerLSE);

	printf("Valores LSE:\n");
	imprimeLSE(&headerLSE);
	printf("Valores LDE:\n");
	imprimeLDE(&headerLDE);

	printf("Quantdade de itens na LSE: %i\n", qtdLSE(&headerLSE));
	printf("Quantdade de itens na LDE: %i\n", qtdLDE(&headerLDE));

	printf("Escolha uma opção para exclusão da lista:\n\t1 - Excluir LSE\n\t2 - Excluir LDE\n");
	int opt;
	scanf("%i", &opt);

	switch (opt)
	{
	case 1:
		excluiLSE(&headerLSE);
		break;
	case 2:
		excluiLDE(&headerLDE);
		break;
	default:
		printf("Opção inválida.\n");
	}

	printf("Valores LSE:\n");
	imprimeLSE(&headerLSE);
	printf("Valores LDE:\n");
	imprimeLDE(&headerLDE);
}

/*
k) (1.0 Ponto) Função que a partir da escolha do usuário, remove a LSE ou a LDE (não esqueça do
descritor).
*/
