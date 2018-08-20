#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

class Circulo {
	protected:
		float areaCirculo;
		float perimetroCirculo;

	public:
		Circulo() {
			areaCirculo = 0;
			perimetroCirculo = 0;
		}

		float AreaCirculo(float r) {
			areaCirculo = M_PI * pow(r, 2);

			return areaCirculo;
		}
		float Perimetro(float r) {
			perimetroCirculo = 2 * M_PI * r;

			return perimetroCirculo;
		}
		int MostrarAreaCirculo() {
			return printf("Area do circulo: %f\n", areaCirculo);
		}
		int MostrarPerimetro() {
			return printf("Perimetro do circulo: %f\n", perimetroCirculo);
		}
};

class Retangulo {
	protected:
		float areaRetangulo;

	public:
		Retangulo() {
			areaRetangulo = 0;
		}

		float AreaRetangulo(float l1, float l2) {
			areaRetangulo = l1 * l2;

			return areaRetangulo;
		}
		int MostrarAreaRetangulo() {
			return printf("Area do retangulo: %f\n", areaRetangulo);
		}
};

class cilindro: public Circulo, public Retangulo {
	protected:
		float areaCilindro;
		float volumeCilindro;

	public:
		cilindro() {
			areaCilindro = 0;
			volumeCilindro = 0;
		}

		int calcular_area_cilindro(float raio, float altura) {
			areaCilindro = (AreaCirculo(raio) * 2) + (2 * M_PI * AreaRetangulo(raio, altura));
			return 1;
		}
		int calcular_volume_cilindro(float raio, float altura) {
			volumeCilindro = AreaCirculo(raio) * altura;
			return 1;
		}
		int mostrar_area_cilindro() {
			return printf("Area do cilindro: %.2f\n", areaCilindro);
		}
		int mostrar_volume_cilindro() {
			return printf("Volume do cilindro: %.2f\n", volumeCilindro);
		}
};