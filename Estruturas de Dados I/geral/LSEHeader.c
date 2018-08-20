#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int criaHeader(struct header **header)
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

int insereEsquerda(struct header **header, int v)
{
	if (*header != NULL)
	{
		struct nodo *novo = (struct nodo *)malloc(sizeof(struct nodo));

		if (novo != NULL)
		{
			novo->dados = v;
			novo->prox = (*header)->inicio;

			if ((*header)->fim == NULL)
			{
				(*header)->fim = novo;
			}

			(*header)->inicio = novo;
			(*header)->qtd++;

			return 1;
		}
	}

	return 0;
}

int insereDireira(struct header **header, int v)
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

int insereAntesValor(struct header **header, int psq, int val)
{
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

int encontraMaiorValor(struct header **header)
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

int imprime(struct header **header)
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

int main()
{
	int i;
	struct header *header = NULL;

	criaHeader(&header);

	for (i = 0; i < 10; i++)
	{
		insereEsquerda(&header, i);
	}

	imprime(&header);
}
