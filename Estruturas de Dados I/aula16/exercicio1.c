#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct fila
{
	int dados;
	struct fila *prox;
};

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

int imprimeFila(struct fila **inicio)
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
	else
	{
		printf("\n");
	}

	return 1;
}

int imprimePilha(struct pilha **topo)
{
	struct pilha *aux = *topo;

	if (aux != NULL)
	{
		do
		{
			printf("%i ", aux->dados);
			aux = aux->prox;
		} while (aux != NULL);

		printf("\n");
	}
	else
	{
		printf("\n");
	}

	return 1;
}

int insereFilaImparPilha(struct fila **inicio, struct fila **fim, struct pilha **topo)
{
	struct fila *filaAuxInicio = NULL;
	struct fila *filaAuxFim = NULL;

	while (*inicio != NULL)
	{
		if ((*inicio)->dados % 2 != 0)
		{
			empilha(&(*topo), (*inicio)->dados);
		}
		enfileirar(&filaAuxInicio, &filaAuxFim, (*inicio)->dados);
		desenfileirar(&(*inicio), &(*fim));
	}

	*inicio = filaAuxInicio;
	*fim = filaAuxFim;
}

int insereFilaParPilha(struct fila **inicio, struct fila **fim, struct pilha **topo)
{
	struct fila *filaAuxInicio = NULL;
	struct fila *filaAuxFim = NULL;

	while (*inicio != NULL)
	{
		if ((*inicio)->dados % 2 == 0)
		{
			empilha(&(*topo), (*inicio)->dados);
		}
		enfileirar(&filaAuxInicio, &filaAuxFim, (*inicio)->dados);
		desenfileirar(&(*inicio), &(*fim));
	}

	*inicio = filaAuxInicio;
	*fim = filaAuxFim;

	return 1;
}

int insereValoresMenor50PilhaFila(struct pilha **topo, struct fila **inicio, struct fila **fim)
{
	struct pilha *topoAux = NULL;

	while (*topo != NULL)
	{
		if ((*topo)->dados < 50)
		{
			enfileirar(&(*inicio), &(*fim), (*topo)->dados);
		}

		empilha(&topoAux, (*topo)->dados);
		desempilha(&(*topo));
	}
	while (topoAux != NULL)
	{
		empilha(&(*topo), topoAux->dados);
		desempilha(&topoAux);
	}

	return 1;
}

int deletaFila(struct fila **inicio, struct fila **fim, int v)
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
	struct fila *inicioFila = NULL;
	struct fila *fimFila = NULL;
	struct pilha *pilhaImpar = NULL;
	struct pilha *pilhaPar = NULL;
	struct fila *inicioFilaMenor = NULL;
	struct fila *fimFilaMenor = NULL;

	srand(time(NULL));

	for (i = 0; i < 30; i++)
	{
		int rnd = rand() % 100;
		enfileirar(&inicioFila, &fimFila, rnd);
	}

	printf("Fila:\n\t");
	imprimeFila(&inicioFila);
	printf("Pilha Impar:\n\t");
	imprimePilha(&pilhaImpar);
	printf("Pilha Par:\n\t");
	imprimePilha(&pilhaPar);
	printf("Fila Menor:\n\t");
	imprimeFila(&inicioFilaMenor);
	printf("------------------------------\n");

	insereFilaImparPilha(&inicioFila, &fimFila, &pilhaImpar);

	printf("Fila:\n\t");
	imprimeFila(&inicioFila);
	printf("Pilha Impar:\n\t");
	imprimePilha(&pilhaImpar);
	printf("Pilha Par:\n\t");
	imprimePilha(&pilhaPar);
	printf("Fila Menor:\n\t");
	imprimeFila(&inicioFilaMenor);
	printf("------------------------------\n");

	insereFilaParPilha(&inicioFila, &fimFila, &pilhaPar);

	printf("Fila:\n\t");
	imprimeFila(&inicioFila);
	printf("Pilha Impar:\n\t");
	imprimePilha(&pilhaImpar);
	printf("Pilha Par:\n\t");
	imprimePilha(&pilhaPar);
	printf("Fila Menor:\n\t");
	imprimeFila(&inicioFilaMenor);
	printf("------------------------------\n");

	insereValoresMenor50PilhaFila(&pilhaImpar, &inicioFilaMenor, &fimFilaMenor);

	printf("Fila:\n\t");
	imprimeFila(&inicioFila);
	printf("Pilha Impar:\n\t");
	imprimePilha(&pilhaImpar);
	printf("Pilha Par:\n\t");
	imprimePilha(&pilhaPar);
	printf("Fila Menor:\n\t");
	imprimeFila(&inicioFilaMenor);
	printf("------------------------------\n");

	int valDel;
	printf("Digite um valor a ser deletado da fila: ");
	scanf("%i", &valDel);

	int statusExcluiNodo = deletaFila(&inicioFila, &fimFila, valDel);

	if (statusExcluiNodo == 0)
	{
		printf("O valor selecionado não foi encontrado.\n");
	}

	printf("Fila:\n\t");
	imprimeFila(&inicioFila);
	printf("Pilha Impar:\n\t");
	imprimePilha(&pilhaImpar);
	printf("Pilha Par:\n\t");
	imprimePilha(&pilhaPar);
	printf("Fila Menor:\n\t");
	imprimeFila(&inicioFilaMenor);
}
