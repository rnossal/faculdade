#include "Aluno.h"
#include <iostream>
#include <stdio.h>
#define TAM 60

using namespace std;

int main() {
	char str[TAM];
	float nota;
	Aluno al;

	cout << "Digite o nome do aluno: ";
	fgets(str, TAM, stdin);
	strtok(str, "\n");
	al.setNome(str);
	cout << "Digite o CGU: ";
	fgets(str, TAM, stdin);
	strtok(str, "\n");
	al.setCgu(str);
	cout << "Digite a nota da G1: ";
	scanf("%f", &nota);
	al.setG1(nota);
	cout << "Digite a nota da G2: ";
	scanf("%f", &nota);
	al.setG2(nota);
	al.setMedia();

	cout << "\nNome: ";
	al.getNome();
	cout << '\n';
	cout << "CGU: ";
	al.getCgu();
	cout << '\n';
	cout << "G1: ";
	al.getG1();
	cout << '\n';
	cout << "G2: ";
	al.getG2();
	cout << '\n';
	cout << "Media: ";
	al.getMedia();
	cout << '\n';

	// Verificar se foi aprovado e se não foi, dizer quanto precisa na G3.
}