#include <stdio.h>
#include <stdlib.h>

struct nodo
{
	int dados;
	struct nodo *prox;
};

int insereUltimo(struct nodo **p, int v)
{
	struct nodo *novo = (struct nodo *)malloc(sizeof(struct nodo));

	if (novo != NULL)
	{
		novo->dados = v;

		if (*p == NULL)
		{
			novo->prox = novo;
		}
		else
		{
			novo->prox = (*p)->prox;
			(*p)->prox = novo;
		}

		*p = novo;

		return 1;
	}

	return 0;
}

int inserePrimeiro(struct nodo **p, int v)
{
	struct nodo *novo = (struct nodo *)malloc(sizeof(struct nodo));

	if (novo != NULL)
	{
		novo->dados = v;

		if (*p == NULL)
		{
			novo->prox = novo;
			*p = novo;
		}
		else
		{
			novo->prox = (*p)->prox;
			(*p)->prox = novo;
		}

		return 1;
	}
	return 0;
}

int insereAntesValor(struct nodo **p, int psq, int val)
{
	struct nodo *aux = NULL;
	struct nodo *ant = NULL;
	struct nodo *novo = NULL;

	if (*p != NULL)
	{
		ant = *p;
		aux = (*p)->prox;

		do
		{
			if (aux->dados == psq)
			{
				novo = (struct nodo *)malloc(sizeof(struct nodo));

				if (novo != NULL)
				{
					novo->dados = val;

					ant->prox = novo;
					novo->prox = aux;

					return 1;
				}
				else
				{
					return -1;
				}
			}

			ant = aux;
			aux = aux->prox;
		} while (aux != (*p)->prox);
	}

	return 0;
}

int excluiNodo(struct nodo **p, int psq)
{
	struct nodo *aux = NULL;
	struct nodo *ant = NULL;

	if (*p != NULL)
	{
		ant = *p;
		aux = (*p)->prox;

		do
		{
			if (aux->dados == psq)
			{
				if (aux == ant)
				{
					*p = NULL;

					free(aux);
				}
				else
				{
					ant->prox = aux->prox;

					free(aux);
				}

				return 1;
			}

			ant = aux;
			aux = aux->prox;
		} while (aux != (*p)->prox);
	}

	return 0;
}

int imprime(struct nodo **p)
{
	struct nodo *aux = NULL;

	if (*p != NULL)
	{
		aux = (*p)->prox;

		do
		{
			printf("%i\n", aux->dados);

			aux = aux->prox;
		} while (aux != (*p)->prox);
	}
	return 0;
}

int count(struct nodo **p)
{
	int i = 0;
	struct nodo *aux = *p;

	if (*p != NULL)
	{
		aux = (*p)->prox;

		for (i = 1; aux != (*p); i++)
			aux = aux->prox;
	}

	return i;
}

int main()
{
	int i = 0;
	struct nodo *p = NULL;

	for (i = 0; i < 10; i++)
	{
		inserePrimeiro(&p, i);
	}

	imprime(&p);

	return 0;
}
