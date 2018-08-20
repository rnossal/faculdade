#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
LIFO (ultima a entrar, primeiro a sair)
FIFO (primeiro a entrar, primeiro a sair)
*/

struct pilha
{
	int dados;
	struct pilha *prox;
};

int empilha(struct pilha **topo, int v)
{
	struct pilha *novo = (struct pilha *)malloc(sizeof(struct pilha));

	if (novo != NULL)
	{
		novo->dados = v;

		if (*topo == NULL)
		{
			novo->prox = NULL;
		}
		else
		{
			novo->prox = *topo;
		}

		*topo = novo;

		return 1;
	}

	return 0;
}

int desempilha(struct pilha **topo)
{
	if (*topo != NULL)
	{
		struct pilha *del = *topo;

		*topo = (*topo)->prox;

		free(del);

		return 1;
	}

	return 0;
}

int deleta(struct pilha **topo, int v)
{
	struct pilha *topoAux = NULL;

	while (*topo != NULL)
	{
		if ((*topo)->dados == v)
		{
			desempilha(&(*topo));
			break;
		}
		else
		{
			empilha(&topoAux, (*topo)->dados);
			desempilha(&(*topo));
		}
	}

	while (topoAux != NULL)
	{
		empilha(&(*topo), topoAux->dados);
		desempilha(&topoAux);
	}
}

int imprime(struct pilha **topo)
{
	struct pilha *topoAux = NULL;

	while (*topo != NULL)
	{
		printf("%i ", (*topo)->dados);
		empilha(&topoAux, (*topo)->dados);
		desempilha(&(*topo));
	}

	printf("\n");

	while (topoAux != NULL)
	{
		empilha(&(*topo), topoAux->dados);
		desempilha(&topoAux);
	}
}

int main()
{
	int i;
	struct pilha *topo = NULL;

	for (i = 0; i < 25; i++)
	{
		empilha(&topo, i);
	}

	imprime(&topo);

	deleta(&topo, 18);

	imprime(&topo);
}
