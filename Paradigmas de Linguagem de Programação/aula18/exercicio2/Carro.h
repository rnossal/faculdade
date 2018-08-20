#include <iostream>
#include <string.h>

#define STRTAM 100
#define QTDCOR 5

typedef struct {
	int codigo;
	char nome[STRTAM];
	int metalica;
} tipoCor;

using namespace std;

class Carro {
	private:
		int cor;
		char marca[STRTAM];
		int portas;
		float preco;
		tipoCor coresDisponiveis[QTDCOR] = {
			{1, "Branco", 0},
			{2, "Preto", 1},
			{3, "Prata", 1},
			{4, "Azul", 0},
			{5, "Vermelho", 0}
		};

	public:
		Carro() {
			cor = 1;
			strncpy(marca, "", STRTAM);
			portas = 2;
			preco = 0;
		}
		
		int setCor(int cor) {
			if (cor >= 1 && cor <= 5) {
				return this->cor = cor;
			}
			return 0;
		}
		tipoCor * getCoresDisponiveis() {
			return coresDisponiveis;
		}
		int setMarca(char *marca) {
			strncpy(this->marca, marca, STRTAM);
		}
		int setPortas(int portas) {
			if (portas == 2 || portas == 4) {
				return this->portas = portas;
			}
			return 0;
		}
		int setPreco(float preco) {
			this->preco = preco;
		}
		float getPreco() {
			float preco = this->preco;

			if (portas == 4) {
				preco += this->preco * 0.2; 
			}
			for (int i = 0; i < QTDCOR; i++) {
				if (coresDisponiveis[i].codigo == cor &&
					coresDisponiveis[i].metalica) {
					preco += this->preco * 0.07;
				}
			}
			preco += this->preco * 0.28;
			preco += preco * 0.07;

			return preco;
		}
		int printCaracteristicas() {
			cout << "\nMarca: " << marca;
			cout << "Número de portas: " << portas;
			for (int i = 0; i < QTDCOR; i++) {
				if (coresDisponiveis[i].codigo == cor) {
					cout << "\nCor: " << coresDisponiveis[i].codigo << " - " << coresDisponiveis[i].nome;
				}
			}
			cout << "\nValor final: " << getPreco();
			cout << '\n';
		}
};