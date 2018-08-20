#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int criaHeader(struct headerd **header)
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

int insereDireita(struct headerd **header, int v)
{
	struct nodod *novo = (struct nodod *)malloc(sizeof(struct nodod));

	if (novo != NULL)
	{
		novo->ant = (*header)->fim;
		novo->dados = v;
		novo->prox = NULL;

		if ((*header)->inicio == NULL)
		{
			(*header)->inicio = novo;
		}
		else
		{
			((*header)->fim)->prox = novo;
		}

		(*header)->fim = novo;
		(*header)->qtd++;

		return 1;
	}

	return 0;
}

int insereEsquerda(struct headerd **header, int v)
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

int imprimeInicioFim(struct headerd **header)
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

int imprimeFimInicio(struct headerd **header)
{
	if (*header != NULL)
	{
		struct nodod *aux = (*header)->fim;

		if (aux != NULL)
		{
			do
			{
				printf("%i ", aux->dados);
				aux = aux->ant;
			} while (aux != NULL);

			printf("\n");

			return 1;
		}
	}
	return 0;
}

int exclui(struct headerd **header, int v)
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

int main()
{
	struct headerd *header = NULL;

	criaHeader(&header);
}
