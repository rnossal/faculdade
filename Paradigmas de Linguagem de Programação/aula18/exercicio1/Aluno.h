#include <stdio.h>
#include <string.h>
#include <iostream>
#define TAM 60

using namespace std;

class Aluno {
	private:
		char nome[TAM];
		char cgu[TAM];
		float g1, g2, media;
	public:
	Aluno() {
		strcpy(nome, "");
		g1 = 0.0;
		g2 = 0.0;
	}
	int getNome() {
		cout << nome;
	}
	int setNome(char str[TAM]) {
		strcpy(nome, str);
	}
	int getCgu() {
		cout << cgu;
	}
	int setCgu(char str[TAM]) {
		strcpy(cgu, str);
	}
	int getG1() {
		cout << g1;
	}
	int setG1(double nota) {
		g1 = nota;
	}
	int getG2() {
		cout << g2;
	}
	int setG2(double nota) {
		g2 = nota;
	}
	int getMedia() {
		cout << media;
	}
	int setMedia() {
		media = (g1 + g2 * 2) / 3;
	}
};