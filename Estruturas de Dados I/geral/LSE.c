#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct nodo
{
	int dados;
	struct nodo *prox;
};

int insereDireita(struct nodo **inicio, int v)
{
	struct nodo *novo = (struct nodo *)malloc(sizeof(struct nodo));
	struct nodo *aux = *inicio;

	if (novo != NULL)
	{
		novo->dados = v;
		novo->prox = NULL;

		if (*inicio == NULL)
		{
			*inicio = novo;
		}
		else
		{
			while (aux->prox != NULL)
			{
				aux = aux->prox;
			}

			aux->prox = novo;
		}

		return 1;
	}

	return 0;
}

int insereEsquerda(struct nodo **inicio, int v)
{
	struct nodo *novo = (struct nodo *)malloc(sizeof(struct nodo));

	if (novo != NULL)
	{
		novo->dados = v;

		novo->prox = *inicio;

		*inicio = novo;

		return 1;
	}

	return 0;
}

int insereNodo(struct nodo **inicio, int n, int v)
{
	struct nodo *ant = NULL;
	struct nodo *aux = *inicio;
	struct nodo *novo = (struct nodo *)malloc(sizeof(struct nodo));

	if (*inicio != NULL && novo != NULL)
	{
		do
		{
			if (aux->dados == n)
			{
				novo->dados = v;
				novo->prox = aux;

				if (ant == NULL)
				{
					*inicio = novo;
				}
				else
				{
					ant->prox = novo;
				}

				return 1;
			}

			ant = aux;
			aux = aux->prox;
		} while (aux != NULL);
	}

	return 0;
}

int insereNodoDepois(struct nodo **inicio, int n, int v)
{
	struct nodo *aux = *inicio;
	struct nodo *novo = (struct nodo *)malloc(sizeof(struct nodo));

	if (*inicio != NULL && novo != NULL)
	{
		do
		{
			if (aux->dados == n)
			{
				novo->dados = v;
				novo->prox = aux->prox;
				aux->prox = novo;

				return 1;
			}

			aux = aux->prox;
		} while (aux != NULL);
	}

	return 0;
}

int insereOrdem(struct nodo **inicio, int v)
{
	struct nodo *novo = (struct nodo *)malloc(sizeof(struct nodo));
	struct nodo *aux = *inicio;
	struct nodo *ant = NULL;

	if (novo != NULL)
	{
		novo->dados = v;
		novo->prox = NULL;

		if (*inicio == NULL)
		{
			*inicio = novo;
		}
		else
		{
			while (aux != NULL && aux->dados < v)
			{
				ant = aux;
				aux = aux->prox;
			}

			novo->prox = aux;
			if (ant == NULL)
				*inicio = novo;
			else
				ant->prox = novo;
		}

		return 1;
	}

	return 0;
}

int deletaNodo(struct nodo **inicio, int v)
{
	struct nodo *ant = NULL;
	struct nodo *aux = *inicio;

	if (*inicio != NULL)
	{
		do
		{
			if (aux->dados == v)
			{
				if (ant == NULL)
				{
					*inicio = aux->prox;
					free(aux);
					aux = *inicio;
				}
				else
				{
					ant->prox = aux->prox;
					free(aux);
					aux = ant->prox;
				}
			}
			else
			{
				ant = aux;
				aux = aux->prox;
			}
		} while (aux != NULL);
	}

	return 0;
}

int imprime(struct nodo **inicio)
{
	struct nodo *aux = *inicio;

	if (aux != NULL)
	{
		do
		{
			printf("%i\n", aux->dados);
			aux = aux->prox;
		} while (aux != NULL);
	}

	return 1;
}

int pesquisaValor(struct nodo **inicio, int v)
{
	int i;
	struct nodo *aux = *inicio;

	for (i = 1; aux != NULL; i++)
	{
		if (aux->dados == v)
		{
			return i;
		}
		aux = aux->prox;
	}

	return -1;
}

int contem(struct nodo **inicio, int v)
{
	struct nodo *aux = *inicio;

	if (aux != NULL)
	{
		do
		{
			if (aux->dados == v)
			{
				return 1;
			}
			aux = aux->prox;
		} while (aux != NULL);
	}

	return 0;
}

int main()
{
	int i;
	struct nodo *ptr = NULL;

	srand(time(NULL));

	return 0;
}
