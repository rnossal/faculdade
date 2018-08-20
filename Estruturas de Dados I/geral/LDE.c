#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct nodod
{
	struct nodod *ant;
	int dados;
	struct nodod *prox;
};

int insereDireita(struct nodod **inicio, struct nodod **fim, int v)
{
	struct nodod *novo = (struct nodod *)malloc(sizeof(struct nodod));

	if (novo != NULL)
	{
		novo->ant = *fim;
		novo->dados = v;
		novo->prox = NULL;

		if (*inicio == NULL)
		{
			*inicio = novo;
		}
		else
		{
			(*fim)->prox = novo;
		}

		*fim = novo;

		return 1;
	}

	return 0;
}

int insereEsquerda(struct nodod **inicio, struct nodod **fim, int v)
{
	struct nodod *novo = (struct nodod *)malloc(sizeof(struct nodod));

	if (novo != NULL)
	{
		novo->ant = NULL;
		novo->dados = v;
		novo->prox = *inicio;

		if (*inicio == NULL)
		{
			*fim = novo;
		}
		else
		{
			(*inicio)->ant = novo;
		}
		*inicio = novo;

		return 1;
	}

	return 0;
}

int imprimeFimInicio(struct nodod **fim)
{
	struct nodod *aux = *fim;

	if (aux != NULL)
	{
		do
		{
			printf("%i\n", aux->dados);
			aux = aux->ant;
		} while (aux != NULL);
	}

	return 1;
}

int imprimeInicioFim(struct nodod **inicio)
{
	struct nodod *aux = *inicio;

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

int contem(struct nodod **inicio, int val)
{
	int i;
	struct nodod *aux = *inicio;

	for (i = 1; aux != NULL; i++)
	{
		if (aux->dados == val)
		{
			return i;
		}
		aux = aux->prox;
	}

	return -1;
}

int conta(struct nodod **inicio)
{
	int i;
	struct nodod *aux = *inicio;

	for (i = 0; aux != NULL; i++)
		aux = aux->prox;

	return i;
}

int exclui(struct nodod **inicio, struct nodod **fim, int v)
{
	struct nodod *aux = *inicio;
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
					*inicio = del->prox;

					if (del->prox == NULL)
					{
						*fim = NULL;
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
						*fim = del->ant;
					}
					else
					{
						del->prox->ant = del->ant;
					}
				}

				free(del);
			}

			aux = aux->prox;
		} while (aux != NULL);
	}

	return 0;
}

int excluiAnterior(struct nodod **inicio, struct nodod **fim, int v)
{
	struct nodod *aux = NULL;
	struct nodod *del = NULL;

	if (*inicio != NULL)
	{
		if ((*inicio)->dados == v)
			return -1;

		aux = (*inicio)->prox;

		if (aux == NULL)
			return 0;
		do
		{
			if (aux->dados == v)
			{
				del = aux->ant;

				if (del->ant == NULL)
				{
					aux->ant = NULL;
					*inicio = aux;
					free(del);

					return 1;
				}
				else
				{
					aux->ant = del->ant;
					del->ant->prox = aux;
					free(del);

					return 1;
				}
			}
			else
			{
				aux = aux->prox;
			}
		} while (aux != NULL);
	}

	return 0;
}

int insereAntesValor(struct nodod **inicio, struct nodod **fim, int valor, int dado)
{
	struct nodod *aux = *inicio;
	struct nodod *novo = (struct nodod *)malloc(sizeof(struct nodod));

	if (novo == NULL)
		return -1;

	if (aux != NULL)
	{
		novo->dados = dado;
		do
		{
			if (aux->dados == valor)
			{
				if (aux->ant != NULL)
				{
					aux->ant->prox = novo;
				}
				else
				{
					*inicio = novo;
				}
				novo->ant = aux->ant;
				novo->prox = aux;
				aux->ant = novo;

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
	struct nodod *ldeInicio = NULL;
	struct nodod *ldeFim = NULL;

	srand(time(NULL));

	return 0;
}
