#include <stdio.h>
#include <string.h>

#define STRTAM 40
#define MAXTRAB 10
#define MAXALUNOS 20

struct ALUNO
{
	char nomAluno[STRTAM];
	char codAluno[STRTAM];
	char nomDisciplina[STRTAM];
	char codDisciplina[STRTAM];
	int qtdTrabalhos;
	double notTrabalhos[MAXTRAB];
	double pesTrabalhos[MAXTRAB];
	double notProva;
	double pesProva;
};

struct ALUNO cadAluno(struct ALUNO al) {
	int i;

	limpaStdin();

	printf("\n----------\nInforme o nome do aluno: ");
	fgets(al.nomAluno, STRTAM, stdin);
	strtok(al.nomAluno, "\n");

	printf("Informe o codigo do aluno: ");
	fgets(al.codAluno, STRTAM, stdin);
	strtok(al.codAluno, "\n");

	printf("Informe o nome da disciplina matriculada: ");
	fgets(al.nomDisciplina, STRTAM, stdin);
	strtok(al.nomDisciplina, "\n");

	printf("Informe o codigo da disciplina matriculada: ");
	fgets(al.codDisciplina, STRTAM, stdin);
	strtok(al.codDisciplina, "\n");

	printf("Informe a quantidade de trabalhos da cadeira: ");
	scanf("%i", &al.qtdTrabalhos);
	while (al.qtdTrabalhos > MAXTRAB)
	{
		printf("Quandidade invalida. Informe novamente: ");
		scanf("%i", &al.qtdTrabalhos);
	}

	for (i = 0; i < al.qtdTrabalhos; i++) {
		printf("Informe a nota do %d(o) trabalho: ", i + 1);
		scanf("%lf", &al.notTrabalhos[i]);
		printf("Informe o peso do %d(o) trabalho: ", i + 1);
		scanf("%lf", &al.pesTrabalhos[i]);
	}

	printf("Informe a nota da prova: ");
	scanf("%lf", &al.notProva);

	printf("Informe o peso da nota da prova: ");
	scanf("%lf", &al.pesProva);

	return al;
}

double calcNota(struct ALUNO al) {
	int i;
	double notaFinal = 0;

	for (i = 0; i < al.qtdTrabalhos; i++) {
		notaFinal += (al.notTrabalhos[i] * al.pesTrabalhos[i]);
	}

	return (notaFinal + al.notProva * al.pesProva) / 10;
}
void printNota(struct ALUNO al) {
	double notaFinal = calcNota(al);

	if (notaFinal <= 10.0) {
		printf("\nNota final do aluno %s: %0.2lf\n", al.nomAluno, notaFinal);
	}
	else {
		printf("\nValor calculado a partir das notas maior que 10. Verificar e informar novamente as notas do aluno %s.\n", al.nomAluno);
	}
}
void printNotaDetalhes(struct ALUNO al) {
	int i;

	printf("\n----------\nNotas dos trabalhos: [");
	for (i = 0; i < al.qtdTrabalhos; i++) {
		if (i != al.qtdTrabalhos - 1) {
			printf("%0.2lf, ", al.notTrabalhos[i]);
		} else {
			printf("%0.2lf", al.notTrabalhos[i]);
		}
	}
	printf("]\nPeso dos trabalhos:  [");
	for (i = 0; i < al.qtdTrabalhos; i++) {
		if (i != al.qtdTrabalhos - 1) {
			printf("%0.2lf, ", al.pesTrabalhos[i]);
		}
		else {
			printf("%0.2lf", al.pesTrabalhos[i]);
		}
	}
	printf("]\nNota da prova:        %0.2lf", al.notProva);
	printf("\nPeso da prova:        %0.2lf\n", al.pesProva);
	printNota(al);
}
limpaStdin()
{
	int c;
	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
}

main() {
	int i, qtdAlunos;
	struct ALUNO al;
	struct ALUNO alunos[MAXALUNOS];

	printf("Digite quantos alunos você deseja cadastrar: ");
	scanf("%i", &qtdAlunos);
	while (qtdAlunos > MAXALUNOS) {
		printf("Quantidade invalida. Digite novamente uma quantidade desejada: ");
		scanf("%i", &qtdAlunos);
	}

	for (i = 0; i < qtdAlunos; i++) {
		alunos[i] = cadAluno(al);
	}
	for (i = 0; i < qtdAlunos; i++) {
		printNotaDetalhes(alunos[i]);
	}
}
