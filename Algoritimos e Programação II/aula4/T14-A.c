/*
Definição:

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
*/
#include <stdio.h>
#include <string.h>

#define PARTAM 501

main() {
	char texto[PARTAM * 10],
		paragrafo[PARTAM];

	int qtdPar = 0;

	while (qtdPar != 10) {
		printf("Digite o %dº paragrafo:\n", qtdPar + 1);
		fgets(paragrafo, PARTAM, stdin);
		if (strcmp(paragrafo, "\n") == 0) {
			break;
		}
		qtdPar++;
		strncat(texto, paragrafo, PARTAM);
	}
}
