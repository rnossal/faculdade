/*
Refaça o T23. Se não conseguiu fazer, baseie-se na resposta publicada 
pelo professor.

Implemente as seguintes alterações:
(além das já existentes no T23 !! )

Se não conseguiu abrir o arquivo de dados para leitura, seja vindo
do main, seja tendo sido digitado, faça a leitura dos dados pelo
teclado da mesma forma como no T22!! 

Depois de cadastrado, seja por arquivo, seja por teclado, 
grave um arquivo novo que tenha o seguinte nome:
t24-000N.txt onde N é a quantidade de turmas. Os zeros são
para um dígito de N. Exemplos:

-   5 turmas: t24-0005.txt
-  13 turmas: t24-0013.txt
- 987 turmas: t24-0987.txt

Este arquivo de saida deverá ser CRIADO. Ele terá os dados
de forma crua, exatamente como estão nos arquivos in:

Exemplo para 2 turmas:
## Arquivo t24-0002.txt

2
345
Algoritmos e programacao III
Elgio Schlemer
0
8976
Redes de Computadores II
Elgio Schlemer
1
000000001-2
Anderson dos Santos
5
6
7

Depois de gravar este arquivo, imprima o relatório em duas vias:
- a original, do T22, indo para a saída padrão (tela)
- salvar ele com a formatação no arquivo "t24-relatorios.txt", mas agora
sem apagar o que tinha antes. Fazendo append.


Observe testes:

C:\> T24.exe dados.txt<ENTER>
# ERRO: nao pode abrir dados.txt para leitura
ERRO dados.txt
# Digite arquivo com os dados das turmas:
dados2.txt<ENTER>
# ERRO: nao pode abrir dados2.txt para leitura
ERRO dados2.txt

# Lendo dados do teclado
# Encerrando: sem arquivo de dados
# Quantas turmas voce quer cadastrar?

... // Segue dialogo como no T22, pedindo para digitar

C:\>
*/

#include <stdio.h>
#include <stdlib.h>

#define STRMAX 100

struct ALUNOS {
	char mat[STRMAX];
	char nome[STRMAX];
	double g1, g2, g3;
	double media;
	double mediaFinal;
};

struct TURMAS {
	char nturma[STRMAX];
	char disciplina[STRMAX];
	char professor[STRMAX];
	int qa;
	struct ALUNOS *a;
};

int lestring(char[], int, FILE *, FILE *);
int cadastraturma(struct TURMAS *, int, FILE *, FILE *);
int cadastraalunos(struct TURMAS *, int, FILE *, FILE *);
double lenota(char *, FILE *, FILE *);
int length(char *);
int relatorio(struct TURMAS *, int, FILE *);
int compareNome(struct TURMAS *a, struct TURMAS *b);
int compareNota(struct ALUNOS *a, struct ALUNOS *b);

int main(int argc, char *argv[])
{
	char arqPath[STRMAX],
		tmpStr[STRMAX],
		ch;
	FILE *arq = NULL,
		*saidaRaw = NULL,
		*saidaRel = NULL;
	struct TURMAS *turma = NULL;
	int qt = 0;
	int i;

	if (!(saidaRaw = fopen("t24-0000.txt", "w"))) {
		printf("# Não conseguiu criar um arquivo de raw das entradas\n");
		saidaRaw = tmpfile(); // Só para direcionar para algum lugar que não os file descriptor e não quebrar o programa lá embaixo (o cara lê da tela pelo menos).
	}

	if (argc >= 2) {
		if (!(arq = fopen(argv[1], "r"))) {
			printf("# ERRO: nao pode abrir %s para leitura\n", argv[1]);
			printf("ERRO %s\n", argv[1]);
		}
	}
	if (!arq) {
		printf("# Digite arquivo com os dados das turmas:\n");
		lestring(arqPath, STRMAX, stdin, saidaRaw);

		if (!(arq = fopen(arqPath, "r"))) {
			printf("# ERRO: nao pode abrir %s para leitura\n", arqPath);
			printf("ERRO %s\n", arqPath);
			printf("\n# Lendo dados do teclado\n");
			arq = stdin;
		}
	}

	while (qt <= 0 || !turma) {
		printf("\n# Quantas turmas voce quer cadastrar?\n");
		/*
		* Solução mais safada para ler qualquer entrada, mesmo que texto, para um inteiro e guardar no arquivo de saida raw.
		* Só funciona ¯\_(ツ)_/¯
		*/
		lestring(tmpStr, STRMAX, arq, saidaRaw);
		qt = atoi(tmpStr);
		if (qt == 0 && !(tmpStr[0] >= '0' && tmpStr[0] <= '9')) {
			printf("ERRO entrada invalida\n");
			continue;
		}
		if (qt <= 0) {
			printf("# ERRO Quantidade de turmas deve ser maior que 0\n");
			continue;
		}
		turma = (struct TURMAS *) malloc(qt * sizeof(struct TURMAS));
		if (turma == NULL) {
			printf("ERRO %d\n", qt);
			printf("# ERRO: Nao foi possivel alocar dados para %d disciplinas\n", qt);
		}
	}
	printf("# Alocado com sucesso espaco para %d turmas\n", qt);

	sprintf(arqPath, "t24-%04d.txt", qt); // Monta o nome do arquivo raw dinamicamente (sprintf porque o arquivo tem quantidas de 0 variável dependendo da quantidade de casas da quantidade de turmas lida).
	
	fclose(saidaRaw);

	remove(arqPath); // Com essa minha gambiarra, e como na definição é para sobrescrever, melhor apagar qualquer arquivo com o mesmo nome antes de renomear o temporário.
	rename("t24-0000.txt", arqPath); // Vai isso mesmo porque eu quero guardar todas as entradas, mesmo antes de montar o nome dinâmico com a quantidade de turmas.

	saidaRaw = fopen(arqPath, "a"); // Passa agora pra append porque preciso concatenar com o que veio do temporario.

	qt = cadastraturma(turma, qt, arq, saidaRaw);
	qsort(turma, qt, sizeof(struct TURMAS), compareNome);

	printf("\n# FIM DA ETAPA A que era apenas o cadastro\n");
	relatorio(turma, qt, stdout);
	if (!(saidaRel = fopen("t24-relatorios.txt", "a"))) {
		printf("# Ih rapaz, nao deu para abrir em append o arquivo de relatórios.\n");
		saidaRel = tmpfile(); // Mesma coisa aqui.
	}
	relatorio(turma, qt, saidaRel);

	for (i = 0; i < qt; i++) {
		if (turma[i].a) {
			free(turma[i].a);
		}
	}

	free(turma);

	fclose(arq);
	fclose(saidaRaw);
	fclose(saidaRel);
}

int cadastraturma(struct TURMAS *tur, int qt, FILE *arq, FILE *saidaRaw)
{
	int i;
	int tent;
	char tmpStr[STRMAX];

	for (i = 0; i < qt; i++) {
		printf("\n# --- Turma [%d] ---\n", i);

		printf("# Codigo da turma:\n");
		lestring(tur[i].nturma, STRMAX, arq, saidaRaw);

		printf("\n# Nome da disciplina:\n");
		lestring(tur[i].disciplina, STRMAX, arq, saidaRaw);

		printf("\n# Nome do professor:\n");
		lestring(tur[i].professor, STRMAX, arq, saidaRaw);

		tur[i].a = NULL;

		tent = 0;

		while (tur[i].a == NULL) {
			printf("\n# Quantos alunos tem a turma %s?\n", tur[i].nturma);
			// Olha a solução de novo ¯\_(ツ)_/¯
			lestring(tmpStr, STRMAX, arq, saidaRaw);
			tur[i].qa = atoi(tmpStr);
			if (tur[i].qa == 0 && !(tmpStr[0] >= '0' && tmpStr[0] <= '9')) {
				printf("ERRO entrada invalida\n");
				continue;
			}
			if (tur[i].qa < 0) {
				printf("ERRO %d\n", tur[i].qa);
				printf("# Quantidade de alunos deve ser maior ou igual a 0\n");
				continue;
			}

			tur[i].a = (struct ALUNOS *) malloc(tur[i].qa * sizeof(struct ALUNOS));
			if (tur[i].a == NULL) {
				printf("ERRO %d\n", tur[i].qa);
				printf("# ERRO: Nao foi possivel alocar dados para %d alunos\n", tur[i].qa);
				tur[i].qa = 0;
				tent++;
				if (tent >= 3) {
					printf("# ERRO: Falhou nas 3 tentativas de alocar alunos\n");
					printf("# ERRO: assumindo 0 turmas\n");
					break;
				}
				continue;
			}
		}
		if (tur[i].qa > 0) {
			printf("\n# Alocado com suceso espaco para %d alunos na turma %s\n", tur[i].qa, tur[i].nturma);
			cadastraalunos(tur, i, arq, saidaRaw);
			qsort(tur[i].a, tur[i].qa, sizeof(struct ALUNOS), compareNota);
			printf("# --- TURMA [%d] FIM DO CADASTRO\n", i);
		}
	}
	return (i);
}

int cadastraalunos(struct TURMAS *t, int n, FILE *arq, FILE *saidaRaw)
{
	int i, j, k;
	int qa;
	double m1, m2;
	struct ALUNOS *a;

	qa = t[n].qa;

	if (qa <= 0) {
		return (0);
	}

	a = t[n].a;
	if (a == NULL) {
		printf("ERRO alunos nao alocados em turma[%d]\n", i);
		return (0);
	}
	for (i = 0; i < qa; i++) {
		printf("\n# ------- ALUNO [%i] da turma %s\n", i, t[n].nturma);

		do {
			printf("# Qual o numero da matricula do aluno:\n");
			lestring(a[i].mat, STRMAX, arq, saidaRaw);
			for (j = 0; j < i; j++) {
				if (comparaSemCase(a[i].mat, a[j].mat) == 0) {
					printf("ERRO: matricula %s ja esta na turma\n", a[i].mat);
					a[i].mat[0] = 0;
					break;
				}
			}
		} while (!a[i].mat[0]);

		a[i].nome[0] = 0;

		for (j = 0; j < n; j++) {
			if (t[j].a == NULL)
				continue;
			if (t[j].qa <= 0)
				continue;
			for (k = 0; k < t[j].qa; k++) {
				if (comparaSemCase(t[j].a[k].mat, a[i].mat)) {
					continue;
				}
				copiaseguro(a[i].nome, STRMAX, t[j].a[k].nome);
				break;
			}
			if (a[i].nome[0])
				break;
		}

		if (a[i].nome[0]) {
			printf("# INFO: encontrado matricula. Nao sera solicitado digitacao do nome\n");
		} else {
			printf("\n# Qual o nome do aluno:\n");
			lestring(a[i].nome, STRMAX, arq, saidaRaw);
		}

		printf("\n# Quais as notas G1, G2 e G3 do aluno\n");
		a[i].g1 = a[i].g2 = a[i].g3 = -1;

		a[i].g1 = lenota("# Nota G1:", arq, saidaRaw);
		a[i].g2 = lenota("\n# Nota G2:", arq, saidaRaw);

		a[i].media = ((a[i].g2 * 2) + a[i].g1) / 3.0;

		a[i].g3 = lenota("\n# Nota G3:", arq, saidaRaw);

		a[i].mediaFinal = a[i].media;

		if (a[i].g3 > 0) {
			m1 = ((a[i].g2 * 2) + a[i].g3) / 3.0;
			m2 = ((a[i].g3 * 2) + a[i].g1) / 3.0;

			if (m1 > m2) {
				a[i].mediaFinal = m1;
			} else {
				a[i].mediaFinal = m2;
			}
		}
		printf("\n# ------ ALUNO [%d] FIM DO CADASTRO\n", i);
	}
}

int length(char *o)
{
	int i;
	for (i = 0; o[i]; i++);
	return (i);
}

int relatorio(struct TURMAS *t, int qt, FILE *out)
{
	int i, j;
	int mtur, mmat, mnome, mprof, mdisc, mqa;
	int temp;

	mtur = mmat = mnome = mprof = mdisc = 5;
	mqa = 10;

	for (i = 0; i < qt; i++) {
		temp = length(t[i].nturma);
		mtur = mtur > temp ? mtur : temp;

		temp = length(t[i].disciplina);
		mdisc = mdisc > temp ? mdisc : temp;

		temp = length(t[i].professor);
		mprof = mprof > temp ? mprof : temp;

		for (j = 0; j < t[i].qa; j++) {
			if (t[i].a == NULL) {
				break;
			}
			temp = length(t[i].a[j].mat);
			mmat = mmat > temp ? mmat : temp;

			temp = length(t[i].a[j].nome);
			mnome = mnome > temp ? mnome : temp;
		}
	}
	fprintf(out, "# RELATORIO PARA %d turmas\n\n", qt);

	fprintf(out, "%-*s %-*s %-*s %*s\n", mtur, "TURMA", mdisc, "DISCIPLINA", mprof, "PROFESSOR", mqa, "QTDALUNOS");
	for (i = 0; i < qt; i++) {
		fprintf(out, "%*s %-*s %-*s %*d\n", mtur, t[i].nturma, mdisc, t[i].disciplina, mprof, t[i].professor, mqa, t[i].qa);
	}
	fprintf(out, "\n");

	fprintf(out, "# RELATORIO DOS ALUNOS EM CADA TURMA\n");
	for (i = 0; i < qt; i++) {
		fprintf(out, "\nTURMA %s - %s - %d alunos\n", t[i].nturma, t[i].disciplina, t[i].qa);

		if (t[i].qa > 0) {
			fprintf(out, "%5s %-*s %-*s ", " ", mmat, "MAT", mnome, "ALUNO");
			fprintf(out, "%5s %5s %5s %5s  %10s\n", "G1", "G2", "MEDIA", "G3", "MEDIAFINAL");
		}

		for (j = 0; j < t[i].qa; j++) {
			if (t[i].a == NULL)
				break;
			fprintf(out, "%5s %-*s %-*s ", " ", mmat, t[i].a[j].mat, mnome, t[i].a[j].nome);
			fprintf(out, "%5.1lf %5.1lf %5.1lf %5.1lf %5.1lf", t[i].a[j].g1, t[i].a[j].g2, t[i].a[j].media, t[i].a[j].g3, t[i].a[j].mediaFinal);
			if ((t[i].a[j].mediaFinal + 0.05) >= 6.0) {
				fprintf(out, "%10s\n", "APROVADO");
			} else {
				fprintf(out, "%10s\n", "REPROVADO");
			}
		}
	}
}

double lenota(char *msg, FILE *arq, FILE *saidaRaw)
{
	double nota = -1;
	char tmpStr[STRMAX];

	while (nota < 0) {
		printf("%s\n", msg);
		// E último lugar usado. Eu juro.
		lestring(tmpStr, STRMAX, arq, saidaRaw);
		nota = strtod(tmpStr, NULL);
		if (nota == 0 && !(tmpStr[0] >= '0' && tmpStr[0] <= '9')) {
			nota = -1;
			printf("ERRO entrada invalida\n");
			continue;
		}
		if (nota < 0) {
			printf("# ERRO: Nota deve ser maior ou igual a zero\n");
			continue;
		}
		if (nota > 10) {
			nota = -1;
			printf("# ERRO: Nota deve ser menor ou igual a 10\n");
			continue;
		}
	}
	return (nota);
}

int comparaSemCase(char *s1, char *s2)
{
	char l1, l2;

	while (*s1) {
		l1 = *s1;
		l2 = *s2;
		if ((l1 >= 'a') && (l1 <= 'z')) {
			l1 = l1 - 32;
		}
		if ((l2 >= 'a') && (l2 <= 'z')) {
			l2 = l2 - 32;
		}
		if (l1 != l2) {
			return (l1 - l2);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int copiaseguro(char *d, int max, char *o)
{
	max--;
	while ((max > 0) && (*o)) {
		*d++ = *o++;
		max--;
		*d = 0;
	}
	return (max);
}

// Vai junto o arquivo com o raw de entradas do teclado para não precisar copiar a cada vez que eu leio a tela.
int lestring(char s[], int max, FILE *arq, FILE *saidaRaw)
{
	int i = 0;
	char letra;

	for (i = 0; i < (max - 1); i++) {
		letra = fgetc(arq);


		if (letra == 13) {
			i--;
			continue;
		}
		if ((letra == 10) && (i == 0)) {
			i = i - 1;
			continue;
		}

		if (letra == 10) {
			break;
		}
		s[i] = letra;
		fprintf(saidaRaw, "%c", letra);
	}
	s[i] = 0;
	fprintf(saidaRaw, "\n");

	return (i);
}

int compareNome(struct TURMAS *a, struct TURMAS *b) {
	return comparaSemCase(a->disciplina, b->disciplina);
}

int compareNota(struct ALUNOS *a, struct ALUNOS *b) {
	if (((a->g1 + a->g2 * 2) / 3) > ((b->g1 + b->g2 * 2) / 3)) {
		return 1;
	} else {
		return -1;
	}
	return 0;
}
