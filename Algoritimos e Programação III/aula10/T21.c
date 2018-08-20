/*
Considere a leitura e armazenamento de N livros, sendo que
N deve ser maior que 0 e menor que NMAX (um define).

Cada livro possui os seguintes dados:

- Nome do livro (uma string de até STRMAX cars)
- Nome do autor (uma string de até STRMAX cars)
- quantidade de páginas
- Valor em reais

Faça um programa que leia do teclado os dados para N livros.
O valor de N virá por parâmetros do main. Se não vier ou for
um valor inválido, deve pedir que se digite o valor de N.

Faça a leitura dos dados usando uma função e armazenando os dados
em um vetor de estrutura.

Após a completa leitura dos dados, imprima uma lista de livros
formatadas como no exemplo.

Valores maximos: considere 20000 como NMAX e 100 como STRMAX

Exemplo de uso (os exemplos que são erros estão incompletos,
pois ficaria muito extenso. Os ... indicam que o programa segue)

Lembrando que no padrão da correção automática, tudo que for
impresso com # no início é ignorado. OBSERVE ATENTAMENTE ISSO
para que seu programa passe no teste.

C:\> exercT21.exe<ENTER>
# Quantos livros você quer digitar:
...

C:\> exerT21.exe -1<ENTER>
ERRO -1
# ERRO: quantidade de livros deve estar entre 1 e 20000
# Quantos livros você quer digitar:
...

C:\> exercT21.exe teste<ENTER>
ERRO teste
# ERRO: quantidade de livros deve estar entre 1 e 20000
# Quantos livros você quer digitar:
...

C:\> exercT21.exe 50000<ENTER>
ERRO 50000
# ERRO: quantidade de livros deve estar entre 1 e 20000
# Quantos livros você quer digitar:
...

C:\> exerT21 2<ENTER>
# Digite os dados para 2 livros:

# --- Livro [0] ---
# Nome do livro:
C para quem tem coragem<ENTER>

# Nome do autor:
Elgio Schlemer<ENTER>

# Quantas páginas:
teste<ENTER>
ERRO entrada invalida
# ERRO. Digitou lixo

# Quantas páginas:
50<ENTER>

# Valor em reais:
128.99<ENTER>

# --- Livro [1] ---
# Nome do livro:
Existe vida depois de Algoritmos III<ENTER>

# Nome do autor:
Pedro<ENTER>

# Quantas páginas:
5<ENTER>

# Valor em reais:
65<ENTER>

# ---- FIM DO CADASTRO DE 2 LIVROS ----

Nome do livro                        Nome do autor     Paginas         Valor
-----------------------------------------------------------------------------
C para quem tem coragem              Elgio Schlemer         50 R$     128.99
Existe vida depois de Algoritmos III Pedro                   5 R$      65.00

Total de todos os 2 livros: R$    193.99

C:\>

Observe atentamente o alinhamento. Veja que o Nome do livro foi alinhado
em relação ao maior nome de livro digitado. O mesmo para o nome do autor.
Já a quantidade de páginas está alinhada a direita, bem como o valor.

Veja um relatório fictício para outros nomes de livros

Nome do livro                                     Nome do autor                 Paginas         Valor
------------------------------------------------------------------------------------------------------
A quantidade de bits menores que 8 em um sub-byte Altamiro Jose de Magalhaes       3490 R$    1229.95


Viu como se ajustou? O títolo deste livro tem 49 cars, no limite máximo.
Veja que esta impressão não está com # no início, ou seja, deve bater
literalmente. O sistema de verificação AVISA com warning quando a saida
não bate literalmente por ter espaços a mais.

Veja que existem apenas um espaço em branco entre o nome do livro e do autor.
Do ponto de vista visual, não é muito legal. Também o R$ bem afastado do
valor. Mas vamos deixar assim.
*/

#include <stdio.h>
#include <stdlib.h>

#define NMAX 20000
#define STRMAX 101
/*
Acima coloquei 101 ao invés de 100 porque no arquivo de teste você exibe uma string com 100 caracteres e não 99.

Exemplo:

No T213144.out a linha 29368 exibe "DESENVOLVIMENTO DO KERNEL DO LINUX: UM GUIA PRATICO PARA O PROJETO E A IMPLEMENTACAO DO KERNEL DO LI"
O nome do livro possui 100 caracteres, ao invés de 99 (o que seria o máximo ao definir um array com 100 posições).
Usando STRMAX 100 como você pediu, eu só conseguiria capturar e imprimir "DESENVOLVIMENTO DO KERNEL DO LINUX: UM GUIA PRATICO PARA O PROJETO E A IMPLEMENTACAO DO KERNEL DO L" e iria falhar no seu teste.
*/


struct LIVRO {
	char nomeLivro[STRMAX];
	char nomeAutor[STRMAX];
	int pags;
	double valor;
};

int cleanBuff();
int printHorizontalLine(int q);
struct LIVRO readLivro(struct LIVRO livro);
int lestring(char s[], int max);
int length(char str[]);

main(int argc, char const *argv[]) {
	int i,
		qtdLivros = 0,
		mNome = 0,
		mAutor = 0;
	double total = 0;
	// struct LIVRO *livros = malloc(NMAX * sizeof(struct LIVRO)); // Tive que usar malloc porque não havia NADA que fizesse um array ser criado com NMAX pelo valor que tinha (em algumas máquinas que usei para o desenvolvimento).
	struct LIVRO livros[NMAX]; // Aqui já usamos normal para enviar para correção.

	if (argc > 1) {
		if (atoi(argv[1]) > 0 && atoi(argv[1]) <= NMAX) {
			qtdLivros = atoi(argv[1]);
		} else {
			printf("ERRO %s\n", argv[1]);
			printf("# ERRO. quantidade de livros deve estar entre 1 e %d\n", NMAX);
		}
	}
	if (!qtdLivros) {
		do {
			printf("# Quantos livros você quer digitar:\n");
			scanf("%i", &qtdLivros);
			cleanBuff();
			if (qtdLivros > 0 && qtdLivros <= NMAX) {
				break;
			}
			printf("ERRO entrada invalida\n");
			if (!qtdLivros) {
				printf("# ERRO. Digitou lixo\n");
			}

		} while(1);
	}

	printf("# Digite os dados para %d livros\n\n", qtdLivros);

	for (i = 0; i < qtdLivros; i++) {
		printf("# --- Livro [%d] ---\n", i);
		livros[i] = readLivro(livros[i]);

		if (i == 0) {
			mNome = length(livros[i].nomeLivro);
			mAutor = length(livros[i].nomeAutor);
		} else {
			if (length(livros[i].nomeLivro) > mNome) {
				mNome = length(livros[i].nomeLivro);
			}
			if (length(livros[i].nomeAutor) > mAutor) {
				mAutor = length(livros[i].nomeAutor);
			}
		}
		total += livros[i].valor;
	}

	printf("# ---- FIM DO CADASTRO DE %d LIVROS ----\n\n", qtdLivros);

	i = printf("Nome do livro %*s", mNome > 13 ? mNome - 13 : mNome, "");
	i += printf("Nome do autor %*s", mAutor > 13 ? mAutor - 13 : mAutor, "");
	i += printf("   Paginas"); // Vai com vários espaços mesmo porque: preguiça
	i += printf("         Valor\n");
	printHorizontalLine(i);
	printf("\n");
	for (i = 0; i < qtdLivros; i++) {
		printf("%-*s", mNome < 13 ? 13 : mNome, livros[i].nomeLivro);
		printf(" %-*s ", mAutor < 13 ? 13 : mAutor, livros[i].nomeAutor);
		printf("%10d", livros[i].pags);
		printf(" R$%11.2f\n", livros[i].valor);
	}

	printf("\nTotal de todos os %d livros: R$%10.2lf\n", qtdLivros, total);
}

// Limpa o buffer sempre que necessário.
int cleanBuff() {
	while(fgetc(stdin) != '\n');

	return 1;
}
// Imprime uma linha horizontal de n caracteres.
int printHorizontalLine(int q) {
	int i;

	for(i = 0; i < q; i++) printf("-");

	return i;
}
struct LIVRO readLivro(struct LIVRO livro) {
	printf("# Nome do livro:\n");
	lestring(livro.nomeLivro, STRMAX);
	printf("\n# Nome do autor:\n");
	lestring(livro.nomeAutor, STRMAX);
	printf("\n# Quantas páginas:\n");
	while(!scanf("%i", &livro.pags)){
		cleanBuff();
		printf("ERRO entrada invalida\n");
		printf("# ERRO. Digitou lixo\n");
		printf("\n# Quantas páginas:\n");
	}
	cleanBuff();
	printf("\n# Valor em reais:\n");
	while(!scanf("%lf", &livro.valor)){
		cleanBuff();
		printf("ERRO entrada invalida\n");
		printf("# ERRO. Digitou lixo\n");
		printf("\n# Valor em reais:\n");
	}
	cleanBuff();
	printf("\n");

	return livro;
}
int lestring(char s[], int max) {
	int i = 0;
	char letra;

	for (i = 0; i < (max - 1); i++) {
		letra = fgetc(stdin);

		if ((letra == '\n') && (i == 0)) {
			i = i - 1;
			continue;
		}

		if (letra == '\n')
			break;
		s[i] = letra;
	}

	s[i] = 0;

	return (i);
}
int length(char str[]) {
	int len;

	for (len = 0; str[len] != 0; ++len);

	return len;
}