#include <stdio.h>

main() {
	char nome[00];
	int sexo;
	float altura;
	
	printf("Digite o nome: ");
	scanf("%s", nome);
	printf("Digite o sexo:\n1 = Masculino\n2 = Feminino\n");
	scanf("%i", &sexo);
	printf("Digite a altura: ");
	scanf("%f", &altura);
	
	switch(sexo) {
		case 1:
			printf("Nome: %s\nPeso ideal: %.2f\n", nome, (72.7 * altura) - 58);
			break;
		case 2:
			printf("Nome: %s\nPeso ideal: %.2f\n", nome, (62.1 * altura) - 44.7);
			break;
		default:
			printf("Sexo invalido\n");
	}

	system("pause");
}