#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int excluiLDE(struct nodod **inicio, struct nodod **fim, int v)
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

int insereOrdemLSE(struct nodo **inicio, int v)
{
	struct nodo *novo = (struct nodo *)malloc(sizeof(struct nodo));
	struct nodo *aux = *inicio;
	struct nodo *ant = NULL;

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
			while (aux != NULL && aux->dados < v)
			{
				ant = aux;
				aux = aux->prox;
			}

			novo->prox = aux;
			if (ant == NULL)
				*inicio = novo;
			else
				ant->prox = novo;
		}

		return 1;
	}

	return 0;
}

int insereDireitaLSE(struct nodo **inicio, int v)
{
	struct nodo *novo = (struct nodo *)malloc(sizeof(struct nodo));
	struct nodo *aux = *inicio;

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
			while (aux->prox != NULL)
			{
				aux = aux->prox;
			}

			aux->prox = novo;
		}

		return 1;
	}

	return 0;
}

int insereMultiploLSE(struct nodod **inicioLDE, struct nodod **fimLDE, struct nodo **inicioLSE, int val)
{
	struct nodod *aux = *inicioLDE;

	if (aux != NULL)
	{
		do
		{
			if (aux->dados != 0 && aux->dados % val == 0)
			{
				insereOrdemLSE(inicioLSE, aux->dados);
			}

			aux = aux->prox;
		} while (aux != NULL);
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
	}

	printf("\n");

	return 1;
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
	}
	
	printf("\n");

	return 1;
}

int verificaIntervaloExclui(struct nodod **inicioLDE, struct nodod **fimLDE, struct nodo **inicioLSE, int inicioIntervalo, int fimIntervalo)
{
	if (fimIntervalo < inicioIntervalo)
	{
		int intervaloTmp = inicioIntervalo;

		inicioIntervalo = fimIntervalo;
		fimIntervalo = intervaloTmp;
	}

	struct nodod *aux = *inicioLDE;

	if (aux != NULL)
	{
		do
		{
			int dados = aux->dados;
			aux = aux->prox;

			if (dados >= inicioIntervalo && dados <= fimIntervalo)
			{
				insereDireitaLSE(inicioLSE, dados);
				excluiLDE(inicioLDE, fimLDE, dados);
			}
		} while (aux != NULL);
	}

	return 1;
}

int contemLSE(struct nodo **inicio, int v)
{
	struct nodo *aux = *inicio;

	if (aux != NULL)
	{
		do
		{
			if (aux->dados == v)
			{
				return 1;
			}
			aux = aux->prox;
		} while (aux != NULL);
	}

	return 0;
}

int verificaLSEMultiplicaLDE(struct nodo **inicioLSE, struct nodod **inicioLDE, struct nodod **fimLDE, int v)
{
	struct nodo *aux = *inicioLSE;

	if (contemLSE(inicioLSE, v))
	{
		if (aux != NULL)
		{
			do
			{
				insereDireitaLDE(inicioLDE, fimLDE, (aux->dados * v));
				
				aux = aux->prox;
			} while (aux != NULL);
		}
	}
}

int main()
{
	srand(time(NULL));

	int i;
	struct nodo *lse = NULL;
	struct nodo *lseAuxiliar = NULL;
	struct nodod *ldeInicio = NULL;
	struct nodod *ldeFim = NULL;
	struct nodod *ldeMultiplicadoInicio = NULL;
	struct nodod *ldeMultiplicadoFim = NULL;

	for (i = 0; i < 50; i++)
	{
		int val = rand() % 1000;
		insereDireitaLDE(&ldeInicio, &ldeFim, i);
	}

	printf("\n");
	printf("LDE:\n");
	imprimeLDE(&ldeInicio);
	printf("LSE:\n");
	imprimeLSE(&lse);
	printf("LSE auxiliar:\n");
	imprimeLSE(&lseAuxiliar);
	printf("LDE multiplicada:\n");
	imprimeLDE(&ldeMultiplicadoInicio);
	printf("\n");

	int valValorBusca;
	printf("Digite um valor a ser encontrado os multiplos: ");
	scanf("%i", &valValorBusca);
	insereMultiploLSE(&ldeInicio, &ldeFim, &lse, valValorBusca);

	printf("\n");
	printf("LDE:\n");
	imprimeLDE(&ldeInicio);
	printf("LSE:\n");
	imprimeLSE(&lse);
	printf("LSE auxiliar:\n");
	imprimeLSE(&lseAuxiliar);
	printf("LDE multiplicada:\n");
	imprimeLDE(&ldeMultiplicadoInicio);
	printf("\n");

	int inicioIntervalo;
	printf("Digite o valor do início do intervalo para verificar e excluir: ");
	scanf("%i", &inicioIntervalo);
	int fimIntervalo;
	printf("Digite o valor do fim do intervalo para verificar e excluir: ");
	scanf("%i", &fimIntervalo);

	verificaIntervaloExclui(&ldeInicio, &ldeFim, &lseAuxiliar, inicioIntervalo, fimIntervalo);

	printf("\n");
	printf("LDE:\n");
	imprimeLDE(&ldeInicio);
	printf("LSE:\n");
	imprimeLSE(&lse);
	printf("LSE auxiliar:\n");
	imprimeLSE(&lseAuxiliar);
	printf("LDE multiplicada:\n");
	imprimeLDE(&ldeMultiplicadoInicio);
	printf("\n");

	int valorEscolhido;
	printf("Digite um valor a ser verificado na LSE auxiliar e multiplicado em uma LDE: ");
	scanf("%i", &valorEscolhido);

	verificaLSEMultiplicaLDE(&lseAuxiliar, &ldeMultiplicadoInicio, &ldeMultiplicadoFim, valorEscolhido);

	printf("\n");
	printf("LDE:\n");
	imprimeLDE(&ldeInicio);
	printf("LSE:\n");
	imprimeLSE(&lse);
	printf("LSE auxiliar:\n");
	imprimeLSE(&lseAuxiliar);
	printf("LDE multiplicada:\n");
	imprimeLDE(&ldeMultiplicadoInicio);
	printf("\n");
}
