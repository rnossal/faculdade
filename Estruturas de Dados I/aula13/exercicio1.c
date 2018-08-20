#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct nodod
{
	struct nodod *ant;
	int dados;
	struct nodod *prox;
};

int insereUltimo(struct nodod **p, int v)
{
	struct nodod *novo = (struct nodod *)malloc(sizeof(struct nodod));

	if (novo != NULL)
	{
		novo->dados = v;

		if (*p == NULL)
		{
			novo->prox = novo;
			novo->ant = novo;
		}
		else
		{
			novo->ant = *p;
			novo->prox = (*p)->prox;
			novo->prox->ant = novo;
			(*p)->prox = novo;
		}

		*p = novo;

		return 1;
	}

	return 0;
}

int insereAntesValor(struct nodod **p, int psq, int val)
{
	struct nodod *aux = NULL;
	struct nodod *novo = NULL;

	if (*p != NULL)
	{
		aux = (*p)->prox;

		do
		{
			if (aux->dados == psq)
			{
				novo = (struct nodod *)malloc(sizeof(struct nodod));

				if (novo != NULL)
				{
					novo->dados = val;
					novo->prox = aux;
					novo->ant = aux->ant;
					aux->ant->prox = novo;
					aux->ant = novo;

					return 1;
				}
				else
				{
					return -1;
				}
			}

			aux = aux->prox;
		} while (aux != (*p)->prox);
	}

	return 0;
}

int excluiNodo(struct nodod **p, int psq)
{
	struct nodod *aux = NULL;

	if (*p != NULL)
	{
		aux = (*p)->prox;

		do
		{
			if (aux->dados == psq)
			{
				if (aux == aux->ant)
				{
					*p = NULL;

					free(aux);
				}
				else
				{
					aux->ant->prox = aux->prox;
					aux->prox->ant = aux->ant;

					free(aux);
				}

				return 1;
			}

			aux = aux->prox;
		} while (aux != (*p)->prox);
	}

	return 0;
}

int imprime(struct nodod **p)
{
	struct nodod *aux = NULL;

	if (*p != NULL)
	{
		aux = (*p)->prox;

		do
		{
			printf("%i ", aux->dados);

			aux = aux->prox;
		} while (aux != (*p)->prox);

		printf("\n");

		return 1;
	}

	return 0;
}

int count(struct nodod **p)
{
	int i = 0;
	struct nodod *aux = *p;

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
	struct nodod *p = NULL;

	srand(time(NULL));

	for (i = 0; i < 25; i++)
	{
		int rnd = rand() % 100;
		insereUltimo(&p, rnd);
	}

	imprime(&p);

	int valPsq;
	printf("Digite um valor a ser pesquisado na LDE circular: ");
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
	printf("Digite um valor a ser deletado da LDE circular: ");
	scanf("%i", &valDel);

	int statusExcluiNodo = excluiNodo(&p, valDel);

	if (statusExcluiNodo == 0)
	{
		printf("O valor selecionado não foi encontrado.\n");
	}

	imprime(&p);

	printf("A LDE circular possui %i nodos.\n", count(&p));

	return 0;
}
