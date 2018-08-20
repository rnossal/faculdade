/*
Considere uma universidade que tem turmas e cada disciplina
tem seus alunos e cada aluno tem os seus dados.

Cada aluno possui:
- Número da matricula: apesar de ser apenas números, esta informação
  deve ser string porque pode ter 0 no inicio que não devem ser ignorados.
  (ex: 001232322-5). O numero tem 9 digitos, seguido de um - e um digito
  verificador.
- Nome completo do aluno: uma string de até 100 cars
- notas G1, g2 e g3 deste aluno dentro desta disciplina

Cada turma possui:
- número da turma: mesmo caso da matricula. Embora sejam apenas números
  deve ser string porque pode começar com zero
- nome da disciplina: string de até 100 cars
- Nome do professor que ministra esta turma: até 100 cars
- Quantidade de alunos atualmente matriculados nesta turma (mínimo de 0)
- Lista dos alunos desta turma (estrutura de alunos)

Em cada turma a quantidade de alunos deve ser alocado de forma dinâmica.

Faça um programa que receba por parâmetros do main a quantidade de turmas
que se deseja cadastrar. Se esta quantidade for uma entrada inválida ou
menor que 1, então imprima a mensagem de erro correspondente e peça para
o usuário digitar a quantidade.

Após ter a quantidade, seja pelo main ou porque digitou, tente alocar
espaço para a quantidade de turmas solicitada. Caso não consiga, então
volte e solicite um valor menor ao usuário. Não há um limite máximo.

Após ter o vetor de turmas criado, use uma função para cadastrar turmas,
lendo número de turma, nome da disciplina, nome do professor e, finalmente,
quantidade de alunos. Se for digitado um valor inválido, imprima a mensagem
de erro e solicite novamente.

Aloque dinamicamente espaço para a quantidade de alunos solicitada. Caso
não seja possível alocar espaço para todos aqueles alunos, solicite um
novo valor para quantidade de alunos (menor). Em caso de três tentativas
de não conseguir alocar, imprima o erro correspondente e deixe esta turma
com 0 alunos.

Devidamente alocado a estrutura de alunos dentro desta turma, execute uma
função que leia os dados destes alunos (matricula, nome, g1, g2 e g3)
sempre tratando entrada inesperada (exemplo: digitou string para g1).

Ao final do cadastro das turmas e cada turma com seus alunos, imprima
um relatório dos dados cadastrados.

*** ETAPA A: para a entrega da etapa A espera-se que a leitura de dados
esteja concluida, mesmo que tenha sido feita de forma estática (temporariamente)
O sistema de correção para a etapa A testará apenas esta parte, sem a parte B

Após a leitura dos dados, ordene as turmas de acordo com o nome, desconsiderando
maisculas e minusculas. Em cada turma, ordene os alunos de acordo com a nota
da media, considerando media=(g1+2*g2)/3 sem considerar a g3.

*** ETAPA B: imprima um relatorio de turmas e, dentro de cada turma, seus
alunos. Para cada aluno imprima as notas, a media antes da G3 e a media
após a g3, considerando substituir a G1 ou G2, onde der media maior.

DESAFIO: será concedido pontos extras para os grupos que implementarem
com o seguinte desafio: ao cadastrar matricula de um aluno, recusar se
ela já foi cadastrada dentro desta mesma turma (aluno repetido). Se
a matricula do aluno já existir em outra turma previamente cadastrada,
não pedir nome do aluno, mas pegar o nome digitado para esta mesma
matricula (ainda assim pedir notas, pois é relativo a esta turma).
Ao cadastrar codigo de turma, recusar se esta turma já foi cadastrada
antes. Pedir um novo numero.

Exemplo de teste apenas para a ETAPA A:

c:\> t22.exe lixo<ENTER>
ERRO lixo
# ERRO Quantidade de turmas deve ser maior que 0
# Quantas turmas voce quer cadastrar?
...

c:\> t22.exe -1<ENTER>
ERRO -1
# ERRO Quantidade de turmas deve ser maior que 0
# Quantas turmas voce quer cadastrar?
...

c:\> t22.exe<ENTER>
# Quantas turmas voce quer cadastrar?
teste<ENTER>
ERRO entrada invalida

# Quantas turmas voce quer cadastrar?
-1<ENTER>
ERRO  Quantidade de turmas deve ser maior que 0

# Quantas turmas voce quer cadastrar?
6000000<ENTER>
ERRO 600000
# ERRO: Nao foi possivel alocar dados para 6000000 disciplinas.

# Quantas turmas voce quer cadastrar?
...

Acima o valor de 6 milhoes é um exemplo. O sistema deverá imprimir esta
mensagem de erro sempre que não conseguiu alocar memória para todas
as disciplinas solicitadas. Vai de sistema para sistema. 6 milhoes é um
exagero, que deve necessitar de, aprox, 1GB de memória RAM. O fato
e que deve dar o erro se não pode alocar. Não é erro para um valor
máximo pre-estabelecido.

C:\> T22 2<ENTER>
# Alocado com sucesso espaco para 2 turmas
# Digite dados para 2 turmas

# --- Turma [0] ---
# Codigo da turma:
0123<ENTER>

# Nome da disciplina:
Algoritmo e Programacao III<ENTER>

# Nome do professor:
Elgio Schlemer<ENTER>

# Quantos alunos tem a turma 0123?
lixo<ENTER>
ERRO entrada invalida

# Quantos alunos tem a turma 0123?
-1<ENTER>
ERRO -1
# Quantidade de alunos deve ser maior ou igual 0

# Quantos alunos tem a turma 0123?
1<ENTER>

# Alocado com sucesso espaco para 1 alunos na turma 0123

# ------- ALUNO [0] da turma
# Qual o numero de matricula do aluno:
012342342-4<ENTER>

# Qual o nome do aluno:
Vetchar do Malloc Main sem Ret<ENTER>

# Quais as notas G1, G2 e G3 do aluno
# nota G1:
3.4<ENTER>

# Nota G2:
6.7<ENTER>

# Nota G3:
lixo<ENTER>
ERRO entrada invalida

# Nota G3:
-1<ENTER>
ERRO -1
# ERRO: Nota deve ser maior ou igual a zero

# Nota G3:
8.0<ENTER>

# ------- ALUNO [0] FIM DO CADASTRO
# --- TURMA [0] FIM DO CADASTRO ----

# --- Turma [1] ---
# Codigo da turma:
0125<ENTER>

# Nome da disciplina:
Redes de Computadores II<ENTER>

# Nome do professor:
Elgio Schlemer<ENTER>

# Quantos alunos tem a turma 0123?
0<ENTER>

# --- TURMA [1] FIM DO CADASTRO ----

# FIM DA ETAPA A que era apenas o cadastro
C:\>

Nos arquivos de testes da etapa A não serão colocados quantidades
de disciplinas maiores que 10 e, em cada disciplina, não serão colocados
alunos maiores que 10. Isto permite que se faça uma versão ESTÁTICA da
etapa A fixando os vetores em 10, como já fizeram com os livros,
deixando para "dinamizar" depois, até a entrega final.

Mas a versão final PRECISA ter alocação dinâmica.

Após o término da etapa A, o professor irá disponibilizar uma resposta
ESTÁTICA para a etapa e ajustar o sistema para testar o relatório
(etapa B). Na bateria de testes, apenas os últimos irão testar o
cumprimento do desafio (terao IDs específicos)
*/

#include <stdio.h>
#include <stdlib.h>

#define STRMAX 101

struct ALUNO {
	char matricula[STRMAX];
	char nome[STRMAX];
	double G1;
	double G2;
	double G3;
};

struct TURMA {
	char numero[STRMAX];
	char disciplina[STRMAX];
	char professor[STRMAX];
	int nAlunos;
	struct ALUNO *lAlunos;
};

int cleanBuff();
int lestring(char s[], int max);
struct TURMA readTurma(struct TURMA turma);
struct ALUNO readAluno(struct ALUNO aluno);
int compcasestr(char st1[], char st2[]);
int compareNome(struct TURMA *a, struct TURMA *b);
int compareNota(struct ALUNO *a, struct ALUNO *b);

main(int argc, char *argv[]) {
	int i;
	int qtdTurmas = 0;
	struct TURMA *turmas;

	if (argc > 1) {
		if (atoi(argv[1]) > 0) {
			qtdTurmas = atoi(argv[1]);

			if(!(turmas = malloc(qtdTurmas * sizeof(struct TURMA)))) {
				printf("ERRO %d\n", qtdTurmas);
				printf("# ERRO: Nao foi possivel alocar dados para %d disciplinas.\n", qtdTurmas);
				qtdTurmas = 0;
			}
		} else {
			printf("ERRO %s\n", argv[1]);
			printf("# ERRO Quantidade de turmas deve ser maior que 0\n");
		}
	}

	printf("\n");

	if (!qtdTurmas) {
		do {
			printf("# Quantas turmas voce quer cadastrar?\n");
			if (!scanf("%i", &qtdTurmas)) {
				printf("ERRO entrada invalida\n\n");
			} else if (qtdTurmas <= 0) {
				printf("# ERRO Quantidade de turmas deve ser maior que 0\n\n");
			} else if (qtdTurmas > 0) {
				if(turmas = malloc(qtdTurmas * sizeof(struct TURMA))) {
					break;
				} else {
					printf("ERRO %d\n", qtdTurmas);
					printf("# ERRO: Nao foi possivel alocar dados para %d disciplinas.\n\n", qtdTurmas);
				}
			}

			cleanBuff();
		} while(1);
	}

	printf("# Alocado com sucesso espaco para %d turmas\n\n", qtdTurmas);

	for (i = 0; i < qtdTurmas; i++) {
		printf("# --- Turma [%d] ---\n", i);
		turmas[i] = readTurma(turmas[i]);
		if (turmas[i].nAlunos > 0) { // É uma condicional pra lá de estranha, mas fiz assim para as saídas serem exatas, porque a mensagem parece atrelada ao cadastro de alunos (eu gosto de fazer as saídas exatas).
			printf("# --- TURMA [%d] FIM DO CADASTRO\n\n", i);
		} else {
			printf("\n");
		}
	}
	qsort(turmas, qtdTurmas, sizeof(struct TURMA), compareNome); // Usei cheat e fiz com qsort, sorry (espero que pelo menos esteja sem falhas).

	printf("# FIM DA ETAPA A que era apenas o cadastro\n");
}

int cleanBuff() {
	while(fgetc(stdin) != '\n');

	return 1;
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
struct TURMA readTurma(struct TURMA turma) {
	int i;
	int contaEntradas = 0;

	printf("# Codigo da turma:\n");
	lestring(turma.numero, STRMAX);
	printf("\n# Nome da disciplina:\n");
	lestring(turma.disciplina, STRMAX);
	printf("\n# Nome do professor:\n");
	lestring(turma.professor, STRMAX);
	while (/*turma.nAlunos <= 0 && */contaEntradas < 3) {
		printf("\n# Quantos alunos tem a turma %s?\n", turma.numero);
		if (!scanf("%i", &turma.nAlunos)) {
			printf("ERRO entrada invalida\n");
		} else if (turma.nAlunos < 0) {
			printf("ERRO %d\n", turma.nAlunos);
			printf("# Quantidade de alunos deve ser maior ou igual a 0\n");
		} else if (turma.nAlunos > 0) {
			if (turma.lAlunos = malloc(turma.nAlunos * sizeof(struct ALUNO))) {
				printf("\n# Alocado com sucesso espaco para %d alunos na turma %s\n\n", turma.nAlunos, turma.numero); // Aqui vai dar diferença porque os arquivos .out tem um typo de suceso ao invés de sucesso.
				break;
			} else {
				// Manda alguma msg que não pode alocar.
				turma.nAlunos = 0;
				contaEntradas++;
			}
		} else if (!turma.nAlunos) {
			break;
		}

		if (contaEntradas == 3) {
			// Imprime algum erro de tentativas.
		}
		cleanBuff();
	}

	for (i = 0; i < turma.nAlunos; i++) {
		printf("# ------- ALUNO [%d] da turma\n", i);
		turma.lAlunos[i] = readAluno(turma.lAlunos[i]);
		printf("\n# ------ ALUNO [%d] FIM DO CADASTRO\n", i);
	}
	qsort(turma.lAlunos, turma.nAlunos, sizeof(struct ALUNO), compareNota); // Ordena da maior nota para a menor.

	return turma;
}
struct ALUNO readAluno(struct ALUNO aluno) {
	printf("# Qual o numero da matricula do aluno:\n");
	lestring(aluno.matricula, STRMAX);
	printf("\n# Qual o nome do aluno:\n");
	lestring(aluno.nome, STRMAX);
	printf("\n# Quais as notas G1, G2 e G3 do aluno\n");
	do {
		printf("# Nota G1:\n");
		if (!scanf("%lf", &aluno.G1)) {
			printf("ERRO entrada invalida\n");
		} else if (aluno.G1 < 0) {
			printf("# ERRO: Nota deve ser maior ou igual a zero\n");
		} else if (aluno.G1 > 10) {
			printf("# ERRO: Nota deve ser menor ou igual a 10\n");
		} else {
			break;
		}
		cleanBuff();
	} while (1);
	do {
		printf("\n# Nota G2:\n");
		if (!scanf("%lf", &aluno.G2)) {
			printf("ERRO entrada invalida\n");
		} else if (aluno.G2 < 0) {
			printf("# ERRO: Nota deve ser maior ou igual a zero\n");
		} else if (aluno.G2 > 10) {
			printf("# ERRO: Nota deve ser menor ou igual a 10\n");
		} else {
			break;
		}
		cleanBuff();
	} while (1);
	do {
		printf("\n# Nota G3:\n");
		if (!scanf("%lf", &aluno.G3)) {
			printf("ERRO entrada invalida\n");
		} else if (aluno.G3 < 0) {
			printf("# ERRO: Nota deve ser maior ou igual a zero\n");
		} else if (aluno.G3 > 10) {
			printf("# ERRO: Nota deve ser menor ou igual a 10\n");
		} else {
			break;
		}
		cleanBuff();
	} while (1);

	return aluno;
}
int compcasestr(char st1[], char st2[]) {
	char l1, l2;
	int i;

	for (i = 0; st1[i]; i++) {
		l1 = st1[i];
		l2 = st2[i];

		if ((l1 >= 'a') && (l1 <= 'z')) {
			l1 = l1 - 32;
		}
		if ((l2 >= 'a') && (l2 <= 'z')) {
			l2 = l2 - 32;
		}
		if (l1 != l2) {
			return (l1 - l2);
		}
	}

	return (st1[i] - st2[i]);
}
int compareNome(struct TURMA *a, struct TURMA *b) {
	return compcasestr(a->disciplina, b->disciplina);
}
int compareNota(struct ALUNO *a, struct ALUNO *b) {
	return (int)(((b->G1 + b->G2 * 2) / 3) + 0.5) - (int)(((a->G1 + a->G2 * 2) / 3) + 0.5);
}
