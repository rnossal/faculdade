/*
Seu programa irá trabalhar com parágrafos de um texto. Define-se como
um parágrafo um texto qualquer, com letras, números, simbolos, espaços
e etc, até a ocorrência de uma quebra de linha. Quebras de linha separam
um parágrafo de outro parágrafo. Para este exercício e por motivos de
compatibilidade, não use acentos (ver nota ao fim).

Seu programa suportará apenas 10 parágrafos com 500 cars cada um (por
favor, definidos em constantes). Crie quantas variáveis strings você
quiser, mas uma delas, de nome "texto" deverá ter o texto inteiro, ou
seja, todos os parágrafos digitados (e você deverá definir o tamanho
dela suficiente para caber isto).

A) peça para o usuário digitar seu texto livremente. Ele digita, digita
e digita. Se ele apertar ENTER, temos um parágrafo. Se ele apertar DOIS
ENTERs seguidos, um para terminar o parágrafo que estava digitando e
outro para o próximo parágrafo SEM LETRA ALGUMA, então o usuário encerrou
a digitação do texto. Mesmo que ele não digite dois ENTERs, a digitação
será automaticamente encerrada quando ele digitar o número máximo de
parágrafos do sistema (no caso 10).

Na etapa A não deve ser feito mais nada, nenhum outro processamento das
etapas seguintes. Apenas a leitura dos parágrafos e a "montagem" da string
frase que deverá ter o texto inteiro digitado (uma string pode ter vários
'\n' sem problema algum. O problema aqui será o fgets que termina a leitura
após digitar '\n').

Após a digitação de tudo, ou seja, ao término do item A, a única string
que deve ser mantida é a frase com todos os parágrafos digitados.
(traduzindo: não vale guardar cada parágrafo em uma string diferente, como
  char p1[STRMAX];
  char p2[STRMAX];
  ...
  char p10[STRMAX];

  ISSO NÃO PODE. Pode ter um temp para ler o parágrafo atual. Nada mais
)

B) Somente após a completa realização do item A, imprima na tela o tamanho
e o conteúdo do maior parágrafo digitado (lembrando: não vale ter guardado
isso na etapa A. Tem que ser obtendo esta informação da string texto
Obvio que você poderá usar variáveis auxiliares para obter isto).
É permitido ter contado quantos parágrafos foram digitados no item A e
usar esta informação aqui. Mas não pode ter contado o tamanho de cada
um no item A.

C) Diga quantas palavras tem o maior parágrafo digitado. Considere que
apenas espaços em branco separam palavras. Cuide na hora de digitar para
não deixar uma palavra sem um espaço em relação a outra. Exemplo:
"OK, isto foi bom". Errado: "OK,isto foi bom".


Exemplo de uso:

Digamos que o usuário digite isso:

   Entao ELE me disse:<ENTER>
   Gostaria muito de ter um Elefante. Mas sei que sao pesados.<ENTER>
   Parece brincadeira, mas elefantes comem muito.<ENTER>
   Como tenho cerca eletrica, tenho ate medo que morram eletrocutados.<ENTER>
   <ENTER>

 Ele podia ter digitado 10 parágrafos, mas digitou apenas 4. A string texto
 deverá ser montada tendo (considere tudo na mesma linha):

   "Entao ELE me disse:\nGostaria muito de ter um Elefante. Mas sei que
   sao pesados.\nParece brincadeira, mas elefantes comem muito.\nComo tenho
   cerca eletrica, tenho ate medo que morram eletrocutados.\n"

Veja os '\n' separando os parágrafos. A montagem da string texto
é o ITEM A.

Item B:
O maior parágrafo digitado foi:
"Como tenho cerca eletrica, tenho ate medo que morram eletrocutados."
Com 67 caracteres

(obs: contou o '.' no fim, mas não a quebra de linha)

Item C:
O maior parágrafo tem 10 palavras.

Durante a semana o professor poderá enviar dicas pelo moodle em um forum
que será aberto. Todos poderão opinar neste forum. Todos podem, se desejar,
dar dicas. Só não pode enviar a solução, nem em parte. Qualquer post no
forum não deve envolver trechos da tua solução em andamento.
*/
#include <stdio.h>
#include <string.h>

#define PARTAM 501

main() {
	//Variáveis loops
	int i;

	//Variáveis etapa a e b
	char texto[PARTAM * 10],
		paragrafo[PARTAM];
	int qtdPara = 0;

	//Variáveis etapa b e c
	char maiorPara[PARTAM],
		posMaiorPara[PARTAM];

	//Variáveis etapa c
	int qtdPal = 1;

	//Etapa a
	strncpy(texto, "", PARTAM);
	while (qtdPara != 10) {
		printf("Digite o %dº paragrafo:\n", qtdPara + 1);
		fgets(paragrafo, PARTAM, stdin);
		if (strcmp(paragrafo, "\n") == 0) {
			break;
		}
		qtdPara++;
		strncat(texto, paragrafo, PARTAM);
	}

	//Etapa b
	strncpy(maiorPara, strtok(texto, "\n"), PARTAM);
	for (i = 1; i < qtdPara; i++) {
		strncpy(posMaiorPara, strtok(NULL, "\n"), PARTAM);
		if (strlen(posMaiorPara) > strlen(maiorPara)) {
			strncpy(maiorPara, posMaiorPara, PARTAM);
		}
	}
	printf("O maior paragrado eh:\n\t%s\nEsse paragrafo possui %d caracteres.\n", maiorPara, strlen(maiorPara));

	//Etapa c
	strtok(maiorPara, " ");
	while (strtok(NULL, " ") != NULL) {
		qtdPal++;
	}
	printf("O maior paragrafo possui %d palavras.\n", qtdPal);
}
