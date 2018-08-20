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
			printf("%i ", aux->dados);
			aux = aux->ant;
		} while (aux != NULL);
		printf("\n");
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
			printf("%i ", aux->dados);
			aux = aux->prox;
		} while (aux != NULL);
		printf("\n");
	}

	return 1;
}

int contemLde(struct nodod **inicio, int val)
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

int contaLde(struct nodod **inicio)
{
	int i;
	struct nodod *aux = *inicio;

	for (i = 0; aux != NULL; i++)
		aux = aux->prox;

	return i;
}

int excluiAnterior(struct nodod **inicio, int v)
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

int insereAntesValor(struct nodod **inicio, int valor, int dado)
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

	// Sorteia valores e insere à esquerda ou à direita.
	for (i = 0; i < 20; i++)
	{
		int rnd = rand() % 100;

		if (rnd % 2 == 0)
		{
			insereDireita(&ldeInicio, &ldeFim, rnd);
		}
		else
		{
			insereEsquerda(&ldeInicio, &ldeFim, rnd);
		}
	}

	printf("LDE criada com os valores aleatórios:\n");
	imprimeInicioFim(&ldeInicio);
	// Fim sorteia valores e insere à esquerda ou à direita.

	// Verifica na LDE o valor informado e diz a posição.
	int val;
	printf("Digite de um nodo a ser localizado: ");
	scanf("%i", &val);
	int existencia = contemLde(&ldeInicio, val);
	if (existencia == -1)
	{
		printf("O valor %i que foi escolhido não foi encontrado na lista.\n", val);
	}
	else
	{
		printf("O valor %i que foi escolhido foi encontrado na posição %i da lista.\n", val, existencia);
	}
	// Fim verifica na LDE o valor informado e diz a posição.

	// Verifica na LDE e exclui antes.
	int valExclui;
	printf("Digite de um nodo a ser localizado e excluido seu anterior: ");
	scanf("%i", &valExclui);
	int excluido = excluiAnterior(&ldeInicio, valExclui);
	if (excluido == -1)
	{
		printf("O valor localizado é o início. Não existe um valor anterior a ser excluido.\n");
	}
	else if (excluido == 0)
	{
		printf("Não foi encontrado o valor a ser excluido o anterior.\n");
	}
	else
	{
		printf("O nodo anterior ao valor %i foi encontrado e excluído com sucesso.\n", valExclui);
	}

	printf("LDE depois da exclusão:\n");
	imprimeInicioFim(&ldeInicio);
	// Fim verifica na LDE e exclui antes.

	// Verifica LDE e insere quadrado antes.
	int valValorBusca;
	printf("Digite de um nodo a ser localizado e inserido antes desse nodo, um novo com o seu quadrado: ");
	scanf("%i", &valValorBusca);
	int inserido = insereAntesValor(&ldeInicio, valValorBusca, (valValorBusca * valValorBusca));
	if (inserido == -1)
	{
		printf("Não foi possível alocar o nodo necessário.\n");
	}
	else if (inserido == 0)
	{
		printf("Não foi encontrado nenhum nodo com o valor informado na LDE.\n");
	}
	else
	{
		printf("Inserido um nodo antes de um nodo com o valor informado.\n");
	}

	printf("LDE depois da inserção:\n");
	imprimeInicioFim(&ldeInicio);
	// Fim verifica LDE e insere quadrado antes.

	// Imprime inicio ao fim.
	printf("LDE impressa do início para o fim:\n");
	imprimeInicioFim(&ldeInicio);
	// Fim imprime inicio ao fim.

	// Imprime fim inicio.
	printf("LDE impressa do fim para o início:\n");
	imprimeFimInicio(&ldeFim);
	// Fim imprime fim inicio.

	// Conta LDE.
	printf("A LDE contém %i nodos.\n", contaLde(&ldeInicio));
	// Fim conta LDE.

	return 0;
}
