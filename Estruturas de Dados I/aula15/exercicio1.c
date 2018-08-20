#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct pilha
{
	int dados;
	struct pilha *prox;
};

struct nodo
{
	int dados;
	struct nodo *prox;
};

struct nodod
{
	struct nodod *ant;
	int dados;
	struct nodod *prox;
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

int imprimePilha(struct pilha **topo)
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

int imprimeLSE(struct nodo **inicio)
{
	struct nodo *aux = *inicio;

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

int imprimeLDE(struct nodod **inicio)
{
	struct nodod *aux = *inicio;

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

int insereEsquerdaLSE(struct nodo **inicio, int v)
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

int insereDireitaLDE(struct nodod **inicio, struct nodod **fim, int v)
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

int insereImparPilhaEsquerdaLSE(struct pilha **pilha, struct nodo **lse)
{
	struct pilha *topoAux = NULL;

	while (*pilha != NULL)
	{
		if ((*pilha)->dados % 2 != 0)
		{
			insereEsquerdaLSE(&(*lse), (*pilha)->dados);
		}
		empilha(&topoAux, (*pilha)->dados);
		desempilha(&(*pilha));
	}

	while (topoAux != NULL)
	{
		empilha(&(*pilha), topoAux->dados);
		desempilha(&topoAux);
	}
}

int insereParPilhaDireitaLDE(struct pilha **pilha, struct nodod **ldeInicio, struct nodod **ldeFim)
{
	struct pilha *topoAux = NULL;

	while (*pilha != NULL)
	{
		if ((*pilha)->dados % 2 == 0)
		{
			insereDireitaLDE(&(*ldeInicio), &(*ldeFim), (*pilha)->dados);
		}
		empilha(&topoAux, (*pilha)->dados);
		desempilha(&(*pilha));
	}

	while (topoAux != NULL)
	{
		empilha(&(*pilha), topoAux->dados);
		desempilha(&topoAux);
	}
}

int deletaPilha(struct pilha **topo, int v)
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

int main()
{
	int i;
	struct pilha *topo = NULL;
	struct nodo *LSE = NULL;
	struct nodod *LDEInicio = NULL;
	struct nodod *LDEFim = NULL;

	srand(time(NULL));

	for (i = 0; i < 25; i++)
	{
		int rnd = rand() % 100;
		empilha(&topo, rnd);
	}

	printf("Valores da pilha:\n\t");
	imprimePilha(&topo);

	insereImparPilhaEsquerdaLSE(&topo, &LSE);
	printf("Valores da LSE:\n\t");
	imprimeLSE(&LSE);

	insereParPilhaDireitaLDE(&topo, &LDEInicio, &LDEFim);
	printf("Valores da LDE:\n\t");
	imprimeLDE(&LDEInicio);

	int valDel;
	printf("Digite um valor a ser deletado da pilha: ");
	scanf("%i", &valDel);
	deletaPilha(&topo, valDel);

	printf("\n\nValores finais das listas:\n");
	printf("Valores da pilha:\n\t");
	imprimePilha(&topo);
	printf("Valores da LSE:\n\t");
	imprimeLSE(&LSE);
	printf("Valores da LDE:\n\t");
	imprimeLDE(&LDEInicio);
}
