#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "Circulo.h"

using namespace std;

int main() {
	float b, a;
	cilindro cl;

	cout << "\n\n TESTE DA CLASSE CILINDRO\n";
	cout << "\n Entre com o raio da base do Cilindro: ";
	scanf("%f", & b);
	cout << "\n Entre com a altura do Retangulo: ";
	scanf("%f", & a);
	cl.calcular_area_cilindro(b, a);
	cl.calcular_volume_cilindro(b, a);
	cl.mostrar_area_cilindro();
	cl.mostrar_volume_cilindro();

	getch();
}