#include <stdio.h>
#include <stdlib.h>

struct adjacente
{
	struct adjacente *prox;
	int a;
};

struct vertice
{
	struct vertice *proxv;
	int v;
	struct adjacente *proxa;
};

int imprime(struct vertice **inicio)
{
	struct vertice *auxv = *inicio;
	struct adjacente *auxa = NULL;

	if (auxv != NULL)
	{
		do
		{
			printf("%i -> ", auxv->v);

			auxa = auxv->proxa;
			if (auxa != NULL)
			{
				do
				{
					printf("%i", auxa->a);
					if (auxa->prox != NULL)
						printf(" - ");

					auxa = auxa->prox;
				} while (auxa != NULL);
			}

			printf("\n");

			auxv = auxv->proxv;
		} while (auxv != NULL);
	}

	return 1;
}

struct vertice *aloca_vertice(int v)
{
	struct vertice *novo;
	novo = (struct vertice *)malloc(sizeof(struct vertice));
	novo->v = v;
	novo->proxv = NULL;
	novo->proxa = NULL;

	return (novo);
}

struct adjacente *aloca_adjacente(int a)
{
	struct adjacente *novo;
	novo = (struct adjacente *)malloc(sizeof(struct adjacente));
	novo->a = a;
	novo->prox = NULL;

	return (novo);
}

struct vertice *encontraVertice(struct vertice **vertices, int v)
{
	struct vertice *aux = *vertices;

	if (aux != NULL)
	{
		do
		{
			if (aux->v == v)
			{
				return aux;
			}
			else
			{
				aux = aux->proxv;
			}
		} while (aux != NULL);
	}

	return NULL;
}

struct adjacente *encontraAdjacente(struct adjacente **adjacentes, int a)
{
	struct adjacente *aux = *adjacentes;

	if (aux != NULL)
	{
		do
		{
			if (aux->a == a)
			{
				return aux;
			}
			else
			{
				aux = aux->prox;
			}
		} while (aux != NULL);
	}

	return NULL;
}

int insereOrdemVertice(struct vertice **inicio, struct vertice **vertice)
{
	struct vertice *aux = *inicio;
	struct vertice *ant = NULL;

	if (*vertice != NULL)
	{
		if (*inicio == NULL)
		{
			*inicio = *vertice;
		}
		else
		{
			while (aux != NULL && aux->v < (*vertice)->v)
			{
				ant = aux;
				aux = aux->proxv;
			}

			(*vertice)->proxv = aux;
			if (ant == NULL)
				*inicio = *vertice;
			else
				ant->proxv = *vertice;
		}

		return 1;
	}

	return 0;
}

int insereOrdemAdjacente(struct adjacente **inicio, struct adjacente **adjacente)
{
	struct adjacente *aux = *inicio;
	struct adjacente *ant = NULL;

	if (*adjacente != NULL)
	{
		if (*inicio == NULL)
		{
			*inicio = *adjacente;
		}
		else
		{
			while (aux != NULL && aux->a < (*adjacente)->a)
			{
				ant = aux;
				aux = aux->prox;
			}

			(*adjacente)->prox = aux;
			if (ant == NULL)
				*inicio = *adjacente;
			else
				ant->prox = *adjacente;
		}

		return 1;
	}

	return 0;
}

int conecta(struct vertice **grafo, int v, int a)
{
	struct vertice *vertice = NULL;			// Vertice que vai ser trabalhado.
	struct adjacente *adjacente = NULL; //Adjacente que será trabalhado.

	vertice = encontraVertice(&(*grafo), v);

	// Se o vertice não for encontrado, aloca um.
	if (vertice == NULL)
	{
		vertice = aloca_vertice(v);
		insereOrdemVertice(&(*grafo), &vertice);
	}

	adjacente = encontraAdjacente(&(vertice->proxa), a);

	// Se o adjacente não for encontrado, aloca um.
	if (adjacente == NULL)
	{
		adjacente = aloca_adjacente(a);
		insereOrdemAdjacente(&(vertice->proxa), &adjacente);
	}
}

int desconectaAdjacente(struct vertice **grafo, int v, int a)
{
	struct vertice *vertice = NULL; // Vertice que vai ser trabalhado.
	struct adjacente *ant = NULL;		//Adjacente anterior ao auxiliar.
	struct adjacente *aux = NULL;		//Adjacente auxiliar.

	vertice = encontraVertice(&(*grafo), v);

	if (vertice != NULL)
	{
		aux = vertice->proxa;

		while (aux != NULL)
		{
			if (aux->a == a)
			{
				if (ant == NULL)
				{
					(vertice->proxa) = aux->prox;
					free(aux);
					aux = vertice->proxa;

					return 1;
				}
				else
				{
					ant->prox = aux->prox;
					free(aux);
					aux = ant->prox;

					return 1;
				}
			}
			else
			{
				ant = aux;
				aux = aux->prox;
			}
		}
	}

	return 0;
}

int existeVerticeAdjacente(struct vertice **grafo, int v, int a)
{
	struct vertice *vertice = NULL;			// Vertice que vai ser trabalhado.
	struct adjacente *adjacente = NULL; //Adjacente que vai ser trabalhado.

	vertice = encontraVertice(&(*grafo), v);

	if (vertice != NULL)
	{
		adjacente = encontraAdjacente(&(vertice->proxa), a);

		if (adjacente != NULL)
		{
			return 1;
		}
	}

	return 0;
}

int main()
{
	struct vertice *grafo = NULL;
	int v, a;

	printf("Inserção de arco:\n");
	do
	{
		printf("\nPara encerrar digite 0 para o vertice e o adjacente\n");
		printf("Digite o Vertice: ");
		scanf("%i", &v);
		printf("Digite o Adjacente: ");
		scanf("%i", &a);

		if ((v != 0) && (a != 0))
		{
			conecta(&grafo, v, a);
			imprime(&grafo);
		}
	} while ((v != 0) && (a != 0)); //a saída será quando o usuário digitar 0 0

	printf("\n\nDeleção de adjacentes:\n");
	do
	{
		printf("\nPara encerrar digite 0 para o vertice e o adjacente\n");
		printf("Digite o Vertice: ");
		scanf("%i", &v);
		printf("Digite o Adjacente: ");
		scanf("%i", &a);

		if ((v != 0) && (a != 0))
		{
			desconectaAdjacente(&grafo, v, a);
			imprime(&grafo);
		}
	} while ((v != 0) && (a != 0)); //a saída será quando o usuário digitar 0 0

	printf("\n\nPesquisa de vértice a adjacentes:\n");
	do
	{
		printf("\nPara encerrar digite 0 para o vertice e o adjacente\n");
		printf("Digite o Vertice: ");
		scanf("%i", &v);
		printf("Digite o Adjacente: ");
		scanf("%i", &a);

		if ((v != 0) && (a != 0))
		{
			int existe = existeVerticeAdjacente(&grafo, v, a);
			if (existe)
			{
				printf("O arco informado existe.\n");
			}
			else
			{
				printf("O arco informado não existe.\n");
			}
		}
	} while ((v != 0) && (a != 0)); //a saída será quando o usuário digitar 0 0
}
