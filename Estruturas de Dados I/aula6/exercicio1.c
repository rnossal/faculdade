/**
	Desenvolvedor: Rafael Nossal
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct nodo
{
	int dados;
	struct nodo *prox;
};

int insereDireita(struct nodo **inicio, int v)
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

int imprime(struct nodo **inicio)
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

int insereParImpar(struct nodo **inicioOrig, struct nodo **inicioPar, struct nodo **inicioImpar)
{
	struct nodo *aux = *inicioOrig;

	if (*inicioOrig != NULL)
	{
		do
		{
			if (aux->dados % 2 == 0)
			{
				insereDireita(inicioPar, aux->dados);
			}
			else
			{
				insereDireita(inicioImpar, aux->dados);
			}

			aux = aux->prox;
		} while (aux != NULL);

		return 1;
	}

	return 0;
}

int excluiNodo(struct nodo **inicio, int v)
{
	int nodosExluidos = 0;
	struct nodo *ant = NULL;
	struct nodo *aux = *inicio;

	if (*inicio != NULL)
	{
		do
		{
			if (aux->dados == v)
			{
				if (ant == NULL)
				{
					*inicio = aux->prox;
					free(aux);
					aux = *inicio;
				}
				else
				{
					ant->prox = aux->prox;
					free(aux);
					aux = ant;
				}

				nodosExluidos++;
			}
			else
			{
				ant = aux;
				aux = aux->prox;
			}
		} while (aux != NULL);

		return nodosExluidos;
	}

	return nodosExluidos;
}

int excluiMultiploTres(struct nodo **inicio)
{
	int nodosExluidos = 0;
	struct nodo *ant = NULL;
	struct nodo *aux = *inicio;

	if (*inicio != NULL)
	{
		do
		{
			if (aux->dados % 3 == 0)
			{
				if (ant == NULL)
				{
					*inicio = aux->prox;
					free(aux);
					aux = *inicio;
				}
				else
				{
					ant->prox = aux->prox;
					free(aux);
					aux = ant;
				}

				nodosExluidos++;
			}
			else
			{
				ant = aux;
				aux = aux->prox;
			}
		} while (aux != NULL);

		return nodosExluidos;
	}

	return nodosExluidos;
}

int main()
{
	int i;
	struct nodo *lseOriginal = NULL;
	struct nodo *lsePar = NULL;
	struct nodo *lseImpar = NULL;

	srand(time(NULL));

	for (i = 0; i < 20; i++)
	{
		int rnd = rand() % 101;

		insereDireita(&lseOriginal, rnd);
	}

	printf("LSE original:\n");
	imprime(&lseOriginal);

	insereParImpar(&lseOriginal, &lsePar, &lseImpar);

	printf("LSE par:\n");
	imprime(&lsePar);
	printf("LSE impar:\n");
	imprime(&lseImpar);

	int num;

	printf("Digite o número para tentar excluir da lse par: ");
	scanf("%i", &num);
	int ret = excluiNodo(&lsePar, num);

	if (ret == 0)
	{
		printf("Nenhum nodo na lse par foi encontrado para exclusão\n");
	}

	printf("LSE par:\n");
	imprime(&lsePar);

	int nExcluidos = excluiMultiploTres(&lseImpar);

	printf("%i numeros múltiplos de 3 foram excluídos da lse impar.\n", nExcluidos);

	printf("LSE impar:\n");
	imprime(&lseImpar);

	return 0;
}
