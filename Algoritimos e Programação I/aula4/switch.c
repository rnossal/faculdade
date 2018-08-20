#include <stdio.h>

main() {
	int num;
	
	printf("Digite um valor: ");
	scanf("%i", &num);
	
	switch(num) {
		case 1:
			printf("Um");
			break;
		case 2:
			printf("Dois");
			break;
		case 3:
			printf("Tres");
			break;
		default:
			printf("Valor desconhecido");
	}
	
	//system("pause");
}