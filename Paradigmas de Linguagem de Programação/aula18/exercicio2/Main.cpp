#include "Carro.h"
#include <iostream>
#include <stdio.h>

#define STRTAM 100
#define QTDCOR 5

using namespace std;

int main() {
	int i;
	float f;
	Carro car;
	char str[STRTAM];
	tipoCor *cores = car.getCoresDisponiveis();

	cout << "Digite a marca do carro: ";
	fgets(str, STRTAM, stdin);
	car.setMarca(str);
	cout << "Digite valor inicial do carro: ";
	scanf("%f", &f);
	car.setPreco(f);
	cout << "Digite a quantidade de portas (2 ou 4): ";
	scanf("%i", &i);
	car.setPortas(i);
	cout << "Digite o código da cor conforme abaixo:\n";
	for (i = 0; i < QTDCOR; i++) {
		cout << '\t' << cores[i].codigo << " - " << cores[i].nome << (cores[i].metalica?" - Metálica\n":" - Não metálica\n");
	}
	scanf("%i", &i);
	car.setCor(i);

	car.printCaracteristicas();
}