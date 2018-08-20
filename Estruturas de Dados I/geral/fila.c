#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct fila
{
	int dados;
	struct fila *prox;
};

int enfileirar(struct fila **inicio, struct fila **fim, int v)
{
	struct fila *novo = (struct fila *)malloc(sizeof(struct fila));

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
			(*fim)->prox = novo;
		}

		*fim = novo;

		return 1;
	}

	return 0;
}

int desenfileirar(struct fila **inicio, struct fila **fim)
{
	if (*inicio != NULL)
	{
		struct fila *del = *inicio;

		if ((*inicio)->prox == NULL)
		{
			*fim = NULL;
		}

		*inicio = (*inicio)->prox;

		free(del);

		return 1;
	}

	return 0;
}

int imprime(struct fila **inicio)
{
	struct fila *aux = *inicio;

	if (aux != NULL)
	{
		do
		{
			printf("%i ", aux->dados);
			aux = aux->prox;
		} while (aux != NULL);

		printf("\n");
	}

	return 1;
}

int deleta(struct fila **inicio, struct fila **fim, int v)
{
	int excluiu = 0;

	struct fila *filaAuxInicio = NULL;
	struct fila *filaAuxFim = NULL;

	while (*inicio != NULL)
	{
		if ((*inicio)->dados == v)
		{
			excluiu++;
		}
		else
		{
			enfileirar(&filaAuxInicio, &filaAuxFim, (*inicio)->dados);
		}

		desenfileirar(&(*inicio), &(*fim));
	}

	*inicio = filaAuxInicio;
	*fim = filaAuxFim;

	return excluiu;
}

int main()
{
	int i;
	struct fila *inicio = NULL;
	struct fila *fim = NULL;

	for (i = 0; i < 2; i++)
	{
		enfileirar(&inicio, &fim, i);
	}

	printf("%p\n", inicio);
	printf("%p\n", fim);
	imprime(&inicio);

	desenfileirar(&inicio, &fim);

	printf("%p\n", inicio);
	printf("%p\n", fim);
	imprime(&inicio);

	desenfileirar(&inicio, &fim);

	printf("%p\n", inicio);
	printf("%p\n", fim);
	imprime(&inicio);
}
