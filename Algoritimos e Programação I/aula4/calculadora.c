#include <stdio.h>

main() {
	float num1, num2;
	char ope;
	
	printf("Digite o primeiro valor: ");
	scanf("%f", &num1);
	printf("Digite o tipo de operacao:\n/ = Divisao\n* = Multiplicacao\n- = Subtracao\n+ = Adicao\n");
	scanf("%s", &ope);
	printf("Digite o segundo valor: ");
	scanf("%f", &num2);
	
	switch(ope) {
		case '/':
			printf("%.2f / %.2f = %.2f\n", num1, num2, num1 / num2);
			break;
		case '*':
			printf("%.2f * %.2f = %.2f\n", num1, num2, num1 * num2);
			break;
		case '-':
			printf("%.2f - %.2f = %.2f\n", num1, num2, num1 - num2);
			break;
		case '+':
			printf("%.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
			break;
		default:
			printf("Tipo de operacao invalida\n");
	}

	//system("pause");
}