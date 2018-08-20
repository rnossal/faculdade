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

=========== PARTE FINAL
Relambrandro: na parte final será requerido:
- ordenamento das turmas pela nome da disciplina
- em cada turma, ordenamento das notas pela media antes da G3 (notas baixas antes)

O calculo da media, sem a g3, deve ser feito com media = (g1 + (2*g2)) / 3;
A media FINAL, depois da g3, que deve estar no relatorio, deve ser a maior
media resultante ao substituir a G1 ou a G2, isto é:

m1 = (g3 + (2*g2)) /3;
m2 = (g1 + (2*g3)) /3;

O maior entre m1 e m2 deve ser a media final.
G3 pode ser 0. Neste caso MediaFinal == Media (g3 não deve ser aplicada).
Colocar 0 para g3 pode ser o caso em que o aluno não precisou fazer a G3.

Segue um teste de bancada para a versão final.
Neste teste não se fez entrada inválida (continua como na etapa A) e também
já se inseriu os dados na ordem certa de ordenamento.

C:\> T22Final.exe<ENTER>
# Quantas turmas voce quer cadastrar?
5<ENTER>
# Alocado com sucesso espaco para 5 turmas

# --- Turma [0] ---
# Codigo da turma:
0123<ENTER>

# Nome da disciplina:
Algoritmo e Programacao I<ENTER>

# Nome do professor:
Maria Adelina Raup Sganzerla<ENTER>

# Quantos alunos tem a turma 0123?
4<ENTER>

# ------- ALUNO [0] da turma 0123
# Qual o numero da matricula do aluno:
000000002-1<ENTER>

# Qual o nome do aluno:
Beatriz Vasconcelos<ENTER>

# Quais as notas G1, G2 e G3 do aluno:
# Nota G1:
5<ENTER>

# Nota G2:
4.5<ENTER>

# Nota G3:
9<ENTER>

# ------ ALUNO [0] FIM DO CADASTRO

# ------- ALUNO [1] da turma 0123
# Qual o numero da matricula do aluno:
000000003-3<ENTER>

# Qual o nome do aluno:
Cinara Beltrano Fonseca Lima e Silva<ENTER>

# Quais as notas G1, G2 e G3 do aluno:
# Nota G1:
3.5<ENTER>

# Nota G2:
5.6<ENTER>

# Nota G3:
5.1<ENTER>

# ------ ALUNO [1] FIM DO CADASTRO

# ------- ALUNO [2] da turma 0123
# Qual o numero da matricula do aluno:
000000001-2<ENTER>

# Qual o nome do aluno:
Anderson dos Santos<ENTER>

# Quais as notas G1, G2 e G3 do aluno:
# Nota G1:
5<ENTER>

# Nota G2:
6<ENTER>

# Nota G3:
7<ENTER>

# ------ ALUNO [2] FIM DO CADASTRO

# ------- ALUNO [3] da turma 0123
# Qual o numero da matricula do aluno:
000000033-3<ENTER>

# Qual o nome do aluno:
Zuleica Machado VetChar<ENTER>

# Quais as notas G1, G2 e G3 do aluno:
# Nota G1:
10<ENTER>

# Nota G2:
10<ENTER>

# Nota G3:
0<ENTER>

# ------ ALUNO [3] FIM DO CADASTRO
# --- TURMA [0] FIM DO CADASTRO

# --- Turma [1] ---
# Codigo da turma:
0124<ENTER>

# Nome da disciplina:
Algoritmo e Programacao II<ENTER>

# Nome do professor:
Elgio Schlemer<ENTER>

# Quantos alunos tem a turma 0124?
0<ENTER>
# --- TURMA [1] FIM DO CADASTRO

# --- Turma [2] ---
# Codigo da turma:
0125<ENTER>

# Nome da disciplina:
Algoritmo e Programacao III<ENTER>

# Nome do professor:
Elgio Schlemer<ENTER>

# Quantos alunos tem a turma 0125?
0<ENTER>
# --- TURMA [2] FIM DO CADASTRO

# --- Turma [3] ---
# Codigo da turma:
0126<ENTER>

# Nome da disciplina:
Bando de Dados I<ENTER>

# Nome do professor:
Leonardo Soleti<ENTER>

# Quantos alunos tem a turma 0126?
0<ENTER>
# --- TURMA [3] FIM DO CADASTRO

# --- Turma [4] ---
# Codigo da turma:
0127<ENTER>

# Nome da disciplina:
Linguagem de Programacao para a WEB<ENTER>

# Nome do professor:
Tales Bitelo Viegas<ENTER>

# Quantos alunos tem a turma 0127?
0<ENTER>
# --- TURMA [4] FIM DO CADASTRO
# RELATORIO PARA 5 turmas

TURMA DISCIPLINA                          PROFESSOR                     QTDALUNOS
 0123 Algoritmo e Programacao I           Maria Adelina Raup Sganzerla          4
 0124 Algoritmo e Programacao II          Elgio Schlemer                        0
 0125 Algoritmo e Programacao III         Elgio Schlemer                        0
 0126 Bando de Dados I                    Leonardo Soleti                       0
 0127 Linguagem de Programacao para a WEB Tales Bitelo Viegas                   0

# RELATORIO DOS ALUNOS EM CADA TURMA

TURMA 0123 - Algoritmo e Programacao I - 4 alunos
      MAT         ALUNO                                   G1    G2 MEDIA    G3  MEDIAFINAL
      000000002-1 Beatriz Vasconcelos                    5.0   4.5   4.7   9.0   7.7  APROVADO
      000000003-3 Cinara Beltrano Fonseca Lima e Silva   3.5   5.6   4.9   5.1   5.4 REPROVADO
      000000001-2 Anderson dos Santos                    5.0   6.0   5.7   7.0   6.3  APROVADO
      000000033-3 Zuleica Machado VetChar               10.0  10.0  10.0   0.0  10.0  APROVADO

TURMA 0124 - Algoritmo e Programacao II - 0 alunos

TURMA 0125 - Algoritmo e Programacao III - 0 alunos

TURMA 0126 - Bando de Dados I - 0 alunos

TURMA 0127 - Linguagem de Programacao para a WEB - 0 alunos

# FIM
C:\>

Observe o relatorio. A formatacao, como sempre, não será fundamental (por formataçao entende-se
dispor quase como se fosse uma tabela).

Veja que as turmas forma impressas em ordem alfabetica pelo nome (neste exemplo elas ja
foram digitadas desta forma).

Veja que os alunos foram impressos por ordem crescente de suas medias antes da G3 (aqui
também já se digitou desta forma).

Este teste, assim como está, já está no sistema como teste 0001.
Depois virão testes com entradas invalidas (como no A), muitos e muitos dados mais ainda ordenados
(irei gerar automaticamente) e, por fim, que não PRECISA PASSAR, os testes considerando os desafios.

Em breve também irei fornecer testes para o desafio.
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
int length(char str[]);
/*
Global assim mesmo dos nomes de maiores caractere porque não quero passar
elas por parâmetro da função ou criar mais for no main para usar na impressão.
*/
int mDisciplina,
	mProfessor,
	mAluno,
	mMatricula,
	mNumero;

main(int argc, char *argv[]) {
	int i, j;
	int qtdTurmas = 0;
	struct TURMA *turmas;
	double mediaFinal;

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
		printf("# --- TURMA [%d] FIM DO CADASTRO\n\n", i);
	}
	qsort(turmas, qtdTurmas, sizeof(struct TURMA), compareNome); // Usei cheat e fiz com qsort, sorry (espero que pelo menos esteja sem falhas).

	printf("# FIM DA ETAPA A que era apenas o cadastro");

	printf("\n# RELATORIO PARA %i turmas\n\n", qtdTurmas);

	printf("TURMA %*s", mNumero > 5? mNumero - 5 : 0, "");
	printf("DISCIPLINA %*s ", mDisciplina > 11? mDisciplina - 11 : mDisciplina, "");
	printf("PROFESSOR %*s  ", mProfessor > 10? mProfessor - 10 : mProfessor, "");
	printf("QTDALUNOS\n");
	for (i = 0; i < qtdTurmas; i++) {
		printf("%5s ", turmas[i].numero);
		printf("%-*s", mDisciplina + 1, turmas[i].disciplina);
		printf("%-*s", mProfessor + 1, turmas[i].professor);
		printf("%10i\n", turmas[i].nAlunos);
	}

	printf("\n# RELATORIO DOS ALUNOS EM CADA TURMA\n");
	for (i = 0; i < qtdTurmas; i++) {
		printf("\nTURMA %s - %s - %i alunos\n", turmas[i].numero, turmas[i].disciplina, turmas[i].nAlunos);
		if (turmas[i].nAlunos > 0) {
			printf("%6sMAT ", "");
			printf("%*sALUNO  ", mMatricula > 3? mMatricula - 3 : mMatricula, "");
			printf("%*s G1", mAluno > 4? mAluno - 4 : mAluno, "");
			printf("    G2");
			printf(" MEDIA");
			printf("    G3");
			printf("  MEDIAFINAL\n");
		}
		for (j = 0; j < turmas[i].nAlunos; j++) {
			if (turmas[i].lAlunos[j].G3 == 0.0) {
				mediaFinal = (turmas[i].lAlunos[j].G1 + turmas[i].lAlunos[j].G2 * 2) / 3;
			} else {
				if (((turmas[i].lAlunos[j].G3 + (turmas[i].lAlunos[j].G2 * 2)) / 3) > ((turmas[i].lAlunos[j].G1 + (turmas[i].lAlunos[j].G3 * 2)) / 3)) {
					mediaFinal = (turmas[i].lAlunos[j].G3 + (turmas[i].lAlunos[j].G2 * 2)) / 3;
				} else {
					mediaFinal = (turmas[i].lAlunos[j].G1 + (turmas[i].lAlunos[j].G3 * 2)) / 3;
				}
			}
			printf("      %-*s %-*s  %4.1lf  %4.1lf  %4.1lf  %4.1lf  %4.1lf %s\n",
				mMatricula > 3? mMatricula - 3 : mMatricula,
				turmas[i].lAlunos[j].matricula,
				mAluno,
				turmas[i].lAlunos[j].nome,
				turmas[i].lAlunos[j].G1,
				turmas[i].lAlunos[j].G2,
				((turmas[i].lAlunos[j].G1 + turmas[i].lAlunos[j].G2 * 2) / 3),
				turmas[i].lAlunos[j].G3,
				mediaFinal,
				(mediaFinal >= 5.96)?" APROVADO":"REPROVADO");
		}
	}
	// printf("FIM\n");
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
	while (contaEntradas < 3) {
		printf("\n# Quantos alunos tem a turma %s?\n", turma.numero);
		if (!scanf("%i", &turma.nAlunos)) {
			printf("ERRO entrada invalida\n");
		} else if (turma.nAlunos < 0) {
			printf("ERRO %d\n", turma.nAlunos);
			printf("# Quantidade de alunos deve ser maior ou igual a 0\n");
		} else if (turma.nAlunos > 0) {
			if (turma.lAlunos = malloc(turma.nAlunos * sizeof(struct ALUNO))) {
				printf("\n# Alocado com suceso espaco para %d alunos na turma %s\n\n", turma.nAlunos, turma.numero); // Aqui vai dar diferença porque os arquivos .out tem um typo de suceso ao invés de sucesso.
				break;
			} else {
				printf("ERRO %d\n", turma.nAlunos);
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
	if (length(turma.numero) > mNumero) {
		mNumero = length(turma.numero);
	}
	if (length(turma.disciplina) > mDisciplina) {
		mDisciplina = length(turma.disciplina);
	}
	if (length(turma.professor) > mProfessor) {
		mProfessor = length(turma.professor);
	}

	for (i = 0; i < turma.nAlunos; i++) {
		printf("# ------- ALUNO [%d] da turma %s\n", i, turma.numero);
		turma.lAlunos[i] = readAluno(turma.lAlunos[i]);
		printf("\n# ------ ALUNO [%d] FIM DO CADASTRO\n\n", i);
	}
	qsort(turma.lAlunos, turma.nAlunos, sizeof(struct ALUNO), compareNota);

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

	if (length(aluno.nome) > mAluno) {
		mAluno = length(aluno.nome);
	}
	if (length(aluno.matricula) > mMatricula) {
		mMatricula = length(aluno.matricula);
	}

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
	if (((a->G1 + a->G2 * 2) / 3) > ((b->G1 + b->G2 * 2) / 3)) {
		return 1;
	} else {
		return -1;
	}
	return 0;
}
int length(char str[]) {
	int len;

	for (len = 0; str[len] != 0; ++len);

	return len;
}
