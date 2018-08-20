/*
Implemente um Programa em C, que leia um valor inteiro e calcule o seu Fatorial. Apresente ao usuário o valor e o seu respectivo Fatorial da seguinte forma: n! = Fatorial.
Por exemplo, Fatorial de 5 é:
5! = 5 * 4 * 3 * 2 * 1 = 120 (o processamento – não é para imprimir, apenas o valor final)
Saída para o usuário (mensagem que deverá ser emitida): n! = ????, por exemplo, sendo o cálculo do fatorial de 5, ficaria: 5! = 120
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main() {
	setlocale(LC_ALL, "Portuguese");

	int contador = 0,
		valor = 0,
		fatorial = 0;

	printf("Digite um número inteiro: ");
	scanf("%i", &valor);
	fatorial = contador = valor;

	while (contador > 1) {
		fatorial *= contador-1;
		contador--;
	}

	printf("%i! = %i\n",valor , fatorial);

	system("pause");
}