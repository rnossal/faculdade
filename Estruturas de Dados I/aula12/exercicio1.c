#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
			printf("%i ", aux->dados);

			aux = aux->prox;
		} while (aux != (*p)->prox);

		printf("\n");
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

	srand(time(NULL));

	for (i = 0; i < 25; i++)
	{
		int rnd = rand() % 100;
		insereUltimo(&p, i);
	}

	imprime(&p);

	int valPsq;
	printf("Digite um valor a ser pesquisado na LSE circular: ");
	scanf("%i", &valPsq);
	int valIns;
	printf("Digite o valor a ser inserido antes do valor anterior, se encontrado: ");
	scanf("%i", &valIns);

	int statusInsereAntesValor = insereAntesValor(&p, valPsq, valIns);

	if (statusInsereAntesValor == 0)
	{
		printf("Valor de pesquisa não encontrado.\n");
	}
	else if (statusInsereAntesValor == -1)
	{
		printf("Não foi possível alocar a estrutura.\n");
	}

	imprime(&p);

	int valDel;
	printf("Digite um valor a ser deletado da LSE circular: ");
	scanf("%i", &valDel);

	int statusExcluiNodo = excluiNodo(&p, valDel);

	if (statusExcluiNodo == 0)
	{
		printf("O valor selecionado não foi encontrado.\n");
	}

	imprime(&p);

	printf("A LSE circular possui %i nodos.\n", count(&p));

	return 0;
}
