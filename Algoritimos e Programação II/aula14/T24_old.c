/*
Considere uma sala de cinema com cadeiras numeradas. Cada FILA tem uma
letra do alfabeto e em cada fila tem cadeiras de numeros 1 até N.
Considera-se que qualquer sala, por maior que seja, nunca terá mais
do que 26 filas (A a Z) e 100 cadeiras em cada fila. Porém uma sala pode
ter menos filas e em cada fila podem ter menos cadeiras.

Faça um programa que gerencie esta sala através de uma matriz FILAxCADEIRAS.

As filas na matriz serão numeradas de 0 a 25, como são os índices de
uma matriz, mas você jamais deverá informar ao usuário FILA 0, mas sim
FILA A (A=0, B=1, ... Z=25). Também não diga A0, cadeira 0 da fila A,
mas sim A1, cadeira número 1 da fila A (internamente, na sua matriz,
este assento estará na matriz [0][0]).

Ao iniciar o sistema pergunte ao usuário quantas filas a sala tem,
não permitindo ser maior do que o máximo (26). Depois pergunte quantos
assentos tem a maior fila (tamMaiorFila), não podendo ser maior que 100.

Inicialize a matriz da seguinte forma:

- para cada fila, pergunte quantos assentos tem aquela fila em específico,
não ultrapassando o tamMaiorFila. Coloque 0 em todos os assentos
daquela fila e -1 nos assentos que não fazem parte.

Exemplo: se a fila A tem 20 assentos, as colunas [0] a [19] desta fila
recebem 0 e as colunas de [20] até [tamMaiorFila-1] recebem -1.
-1 indica cadeira inixistente.

O sistema deverá automaticamente ignorar os assentos de [tamMaiorFila] até
[99] porque já foi dito no início que a maior fila tem tamMaiorFila assentos.

- Depois de inicializada a sala, assentos disponíveis tem 0. Permita ao usuário
que faça reservas de salas. Cada "cliente" terá um número, começando
em 1. A reserva de salas do cinema deverá ser nesta ordem:
  - Sistema pergunta quantos assentos ele quer (0 ou negativo ENCERRA
    ESTA PARTE).
  - Se o cliente disser que quer 5 acentos, o sistema deverá procurar
    cinco cadeiras em sequencia para ele e colocar nestes assentos o
    o seu ID (os assentos devem devem estar em ZERO)

  - Se o sistema não encontrar a quantidade de assentos em sequencia
    que o cliente solicitou, deve pegar o máximo possivel e tentar os
    demais na fila de cima ou de baixo.
    Exemplo: cliente 23 pediu cinco lugares, mas não tem nenhuma fila
    com cinco lugares em sequencia. Mas o sistema encontrou na fila
    F tres lugares nas cadeiras 3,4,5 e na fileira G, acima, as
    cadeiras 3,4. Reserva estes.

  - Se o pedido do cliente não for possível de atender em sequencia
    e nem próximos, então será com cadeiras, lugares, bem dispersos.

  - Por fim, se realmente não tiver tantos lugares disponíveis, o sistema
    deve informar ao cliente que a sala está lotada e dizer quantos
    lugares ainda estão disponíveis em toda a sala.

- Feita a reserva para o cliente, o sistema deverá informar quais cadeiras
o cliente 'comprou' e pedir para que o próximo cliente faça a sua compra.

Lembrando: o primeiro cliente tem seu número sendo 1, depois 2, 3, e assim
por diante. Ao solicitar quantidade de salas, se for digitado 0 ou negativo
o sistema de reservas ENCERRA.

======= FIM DA RESERVA DE SALAS. FINALIZA QUANDO CLIENTE INFORMAR 0 OU
======= NEGATIVO PARA QUANTIDADE DE LUGARES


- Ao encerrar a compra de cadeiras, deve-se imprimir uma relação da sala,
colocando 'O' para cada cadeira ocupada e 'L' para cada cadeira livre:

Exemplo para um sistema com 4 filas e 6 cadeiras no máximo
  1 2 3 4 5 6
A O O O L
B O L L O O O
C L L L L
D L O O

Observe que a fila A tem apenas 4 cadeiras. É o tamanho dela, as cadeiras
inexistentes (que tem -1, de acordo com a inicizalização) não aparecem
no relatório. O mesmo para a sala C e D. A sala B tem o máximo de cadeiras
informado: 6 cadeiras.

Obs: o relatório mostra FILA A, e 'O' para Ocupado e 'L' para livre,
mas na matriz é armazenado 0 para Livre, o ID do cliente para ocupado
e -1 para inexistente. E as cadeiras começam no número 1: A1 deve
ser a posição [0][0] da matriz que, pelo exemplo, deve ter um número
positivo.

Agora que encerrou a reserva, o sistema está pronto para gerar
relatórios. Aguarde que o usuário digite um ID de cliente e, após o
ID, procure na matriz quais acentos estão reservados para aquele usuário
e imprima. Se for digitado ID 0, então finalmente o programa encerra
a sua executação.

DESAFIO: se quiser e tiver tempo, tente imprimir os relatórios como
uma tabela ASCII, usando traços e pipes. Aquele relatório, como desafio,
ficaria assim:

      1   2   3   4   5   6
   ++===+===+===+===+===+===+
 A || O | O | O | L |
   ++---+---+---+---+---+---+
 B || O | L | L | O | O | O |
   ++---+---+---+---+---+---+
 C || L | L | L | L |
   ++---+---+---+---+
 D || L | O | O |
   ++---+---+---+

================
*/
#include <stdio.h>

#define TAMFILA 26
#define TAMCADEIRA 100

char getNomeFila(int num) {
	return num + 65;
}
initCadeiras(int sala[][TAMCADEIRA], int vagas[], int qtdFila, int tamMaiorFila) {
	int i, j, qtdAssentos;
	for (i = 0; i < qtdFila; i++) {
		printf("Quantos assentos possui a fila %c? ", getNomeFila(i));
		scanf("%i", &qtdAssentos);
		while (qtdAssentos > tamMaiorFila) {
			printf("O tamanho eh maior que a maior fila. Informe um valor valido: ");
			scanf("%i", &qtdAssentos);
		}
		vagas[i] = qtdAssentos;

		for (j = 0; j < qtdAssentos; j++) {
			sala[i][j] = 0;
		}
		for (j=j; j < tamMaiorFila; j++) {
			sala[i][j] = -1;
		}
	}
}
int alocCadeiras(int sala[][TAMCADEIRA], int vagas[], int cli, int qtdReserva, int qtdFila, int tamMaiorFila) {
	int i,
		j,
		maior[2]; // Primeira posição é a quantidade livre e segunda posição em que fila ele está;

	if (listaTotalLugares(sala, vagas, qtdFila) >= qtdReserva) {
		maior[0] = vagas[0];
		maior[1] = 0;

		for (i = 0; i < qtdFila; i++) {
			if(vagas[i] > maior[0]) {
				maior[0] = vagas[i];
				maior[1] = i;
			}
			if (vagas[i] >= qtdReserva) {
				i = qtdFila;
			}
		}

		qtdReserva = tentaReserva(cli, qtdReserva, tamMaiorFila, sala, vagas, maior[1]);

		if (qtdReserva == 0) {
			return 1;
		} else {
			qtdReserva += reverteReserva(cli, tamMaiorFila, qtdFila, sala, vagas);
			if (maior[1] == 0) {
				if (vagas[maior[1] + 1] >= (qtdReserva - maior[0])) {
					qtdReserva = tentaReserva(cli, qtdReserva, tamMaiorFila, sala, vagas, maior[1]);
					qtdReserva = tentaReserva(cli, qtdReserva, tamMaiorFila, sala, vagas, maior[1] + 1);
					return 1;
				}
			} else if (maior[1] == (qtdFila - 1)) {
				if (vagas[maior[1] - 1] >= (qtdReserva - maior[0])) {
					qtdReserva = tentaReserva(cli, qtdReserva, tamMaiorFila, sala, vagas, maior[1]);
					qtdReserva = tentaReserva(cli, qtdReserva, tamMaiorFila, sala, vagas, maior[1] - 1);
					return 1;
				}
			}

			for (i = 0; i < qtdFila; i++) {
				if(vagas[maior[1]] == vagas[i] && maior[1] != i && vagas[i] != 0) {
					maior[1] = i;
					i = qtdFila;
				}
			}

			if ((vagas[maior[1] - 1] + vagas[maior[1] + 1]) >= (qtdReserva - maior[0])) {
				qtdReserva = tentaReserva(cli, qtdReserva, tamMaiorFila, sala, vagas, maior[1] - 1);
				qtdReserva = tentaReserva(cli, qtdReserva, tamMaiorFila, sala, vagas, maior[1]);
				qtdReserva = tentaReserva(cli, qtdReserva, tamMaiorFila, sala, vagas, maior[1] + 1);
				return 1;
			} else if (listaTotalLugares(sala, vagas, qtdFila) >= qtdReserva) {
				for (i = 0; i < qtdFila; i++) {
					for (j = 0; j < tamMaiorFila && qtdReserva > 0; j++) {
						if (sala[i][j] == 0) {
							qtdReserva--;
							sala[i][j] = cli;
							vagas[i] -= 1;
						}
					}
				}
				return 1;
			}
		}
	}

	reverteReserva(cli, tamMaiorFila, qtdFila, sala, vagas);
	return 0;
}
int tentaReserva(int cli, int qtdReserva, int tamMaiorFila, int sala[][TAMCADEIRA], int vagas[], int maior) {
	int i;

	for (i = 0; i < tamMaiorFila && qtdReserva > 0; i++) {
		if (sala[maior][i] == 0) {
			qtdReserva--;
			sala[maior][i] = cli;
			vagas[maior] -= 1;
		}
	}

	return qtdReserva;
}
int reverteReserva(int cli, int tamMaiorFila, int qtdFila, int sala[][TAMCADEIRA], int vagas[]) {
	int i, j, qtdReserva = 0;

	for (i = 0; i < qtdFila; i++) {
		for (j = 0; j < tamMaiorFila; j++) {
			if (sala[i][j] == cli) {
				sala[i][j] = 0;
				vagas[i] += 1;
				qtdReserva++;
			}
		}
	}

	return qtdReserva;
}
printReservas(int sala[][TAMCADEIRA], int cli, int qtdFila, int tamMaiorFila) {
	// Aqui percorro a sala duas vezes por não conseguir método melhor de verificar primeiro se há ocorrência e depois imprimir algo com concatenação de inteiros sem usar algo "que não vimos"
	int i, j, cont = 0;

	for (i = 0; i < qtdFila; i++) {
		for (j = 0; j < tamMaiorFila; j++) {
			if (sala[i][j] == cli) {
				cont = 1;
				i = qtdFila;
				j = tamMaiorFila;
			}
		}
	}

	if (cont) {
		printf("Reservas para o cliente %d nos assentos:", cli);
		for (i = 0; i < qtdFila; i++) {
			for (j = 0; j < tamMaiorFila; j++) {
				if (sala[i][j] == cli) {
					printf(" %c%d", getNomeFila(i), j + 1);
				}
			}
		}
		printf(".\n\n");
	} else {
		printf("Não foram encontradas reservas para o cliente informado.\n\n");
	}
}
int listaTotalLugares(int sala[][TAMCADEIRA], int vagas[], int qtdFila) {
	int i,
		tot = 0;
	for (i = 0; i < qtdFila; i++) {
		tot += vagas[i];
	}

	return tot;
}
printSala(int sala[][TAMCADEIRA], int qtdFila, int tamMaiorFila) {
	int i, j;

	printf("\n     ");
	for(i = 0; i < tamMaiorFila; i++) {
		printf(" %d  ", i+1);
	}
	printf("\n   ++");
	for(i = 0; i < tamMaiorFila; i++) {
		printf("===+");
	}
	printf("\n");
	for(i = 0; i < qtdFila; i++) {
		printf(" %c ||", getNomeFila(i));
		for(j = 0; j < tamMaiorFila; j++) {
			if(sala[i][j] == 0) {
				printf(" L |");
			} else if (sala[i][j] >= 1) {
				printf(" O |");
			} else {
				printf("    ");
			}
		}
		printf("\n   ++");
		for(j = 0; j < tamMaiorFila; j++) {
			printf("---+");
		}
		printf("\n");
	}
}
main() {
	int qtdFila,
		tamMaiorFila,
		sala[TAMFILA][TAMCADEIRA],
		vagas[TAMFILA],
		cli = 1,
		qtdReserva = 1;

	printf("Informe quantas filas havera na sala: ");
	scanf("%i", &qtdFila);
	while(qtdFila > 26 || qtdFila <= 0) {
		printf("Tamanho invalido. Informe novamente: ");
		scanf("%i", &qtdFila);
	}
	printf("Informe quantas cadeiras tem a maior fila: ");
	scanf("%i", &tamMaiorFila);
	while(tamMaiorFila > 100 || tamMaiorFila <= 0) {
		printf("Tamanho invalido. Informe novamente: ");
		scanf("%i", &tamMaiorFila);
	}

	initCadeiras(sala, vagas, qtdFila, tamMaiorFila);

	printf("-----\nInicio das reservas:\n\n");

	while(qtdReserva > 0) {
		printf("Quantos assentos deseja reservar? ");
		scanf("%i", &qtdReserva);
		if (qtdReserva > 0) {
			if (alocCadeiras(sala, vagas, cli, qtdReserva, qtdFila, tamMaiorFila)) {
				printReservas(sala, cli, qtdFila, tamMaiorFila);
				cli++;
			} else {
				printf("A sala esta lotada para essa quantidade de lugares.\nQuantidade de lugares ainda diponiveis eh: %d\n\n", listaTotalLugares(sala, vagas, qtdFila));
			}
		}
	}

	printf("\n-----\nReservas encerradas com o seguinte relatório da sala:\n");

	printSala(sala, qtdFila, tamMaiorFila);

	printf("\n-----\nAbertura para relatorio de reservas:\n\n");

	while (cli > 0) {
		printf("Qual cliente voce deseja informacao de reservas? ");
		scanf("%i", &cli);
		if (cli > 0) {
			printReservas(sala, cli, qtdFila, tamMaiorFila);
		}
	}

	printf("\n-----\nEncerrando sistema...\n");
}
