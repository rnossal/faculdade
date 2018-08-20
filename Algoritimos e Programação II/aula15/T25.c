/*
Faça um programa em C que defina uma estrutura para
um aluno (pode ser VOCÊ) em uma disciplina.

A estrutura deverá comportar os seguintes dados:
- Nome da disciplina (até STRTAM cars)
- código da disciplina (não é inteiro, pois podem ter letras. Até STRTAM cars)
- Nome do aluno (até STRTAM cars)
- código do aluno (não é inteiro, pois podem ter letras. Até STRTAM cars)
- Quantidade de trabalhos  (no máximo MAXTRAB)
- Nota de cada trabalho (até MAXTRAB)
- Peso de cada trabalho (quanto cada um vale)
- Nota da prova (uma nota)
- Peso da prova


Exemplo de dados de um aluno:
"Algoritmos e Programacao II"  <=== nome da disciplina
"D1234"                        <=== codigo da disciplina
"Fulano Beltrano de Tal"       <=== nome do aluno
"A0001"                        <=== codigo do aluno
4                    <=== 4 trabalhos existentes
3.0  4.0  0.0  9.0   <=== notas destes 4 trabalhos
0.7  0.8  0.8  0.7   <=== peso de cada trabalho
9.0                  <=== nota da prova
7.0                  <=== peso da prova

Ao invés de 4 trabalhos, poderiam ser os MAXTRAB. Mas nunca maior que MAXTRAB.

Faça um função que leia os dados deste aluno. Invoque-a no main e obtenha os dados
digitados para uma variável do main. A função não precisa ser uma única, ela
pode invocar outras funções.

Faça uma função que receba por parâmetro os dados deste aluno e retorne a sua
nota de 0 a 10. A nota deverá ser feita fazendo Prova*pesoProva + Trab1*pesoTrab1 + ...
(para o exemplo de dados acima, a nota deverá ser 7.46)

Faça o main invocar esta função.

A soma de todos os pesos, trabalhos e a prova, deve ser 10, senão tem um erro de sobra
ou falta de pontos. Imprima uma mensagem se tem este erro.

Faça uma outra função que imprima os resultados, com a nota de todos
os trabalhos, a nota da prova, e a nota final do aluno (de 0 a 10).

TUDO PARA UM ÚNICO ALUNO!

Para seus testes, considere MAXTRAB como sendo 10 e STRTAM como sendo 40.
(devem ser defines)
*/

#include <stdio.h>
#include <string.h>

#define STRTAM 40
#define MAXTRAB 10

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

	printf("Informe o nome do aluno: ");
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

	printf("\nNotas dos trabalhos: [");
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

main() {
	struct ALUNO al;

	al = cadAluno(al);

	printNota(al);
	printNotaDetalhes(al);
}
