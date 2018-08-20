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
		free(turmas[i].lAlunos); // Se pra quem entregou no prazo o T22 poderia ser sem o desafio, tá aí...
	}
	free(turmas);
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
