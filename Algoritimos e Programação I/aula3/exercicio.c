/*

Elabore um programa que leia o código e o número de horas trabalhadas de um operário.

Após, calcule o salário sabendo-se que ele ganha R$10,00 por hora.

Quando o número de horas excederem a 50, calcule o excesso de pagamento.

O valor da hora excedente é de R$20,00.

Deve ser exibido no final do programa o salário total e o valor excedente.

*/



#include <stdio.h>


main() {

	int codFun, horasTrab;

	float salTotal, valExc;



	printf("Digite o codigo do funcionario:\n");

	scanf("%i", &codFun);

	printf("Digite a quantidade de horas trabalhadas:\n");

	scanf("%i", &horasTrab);



	if (horasTrab <= 50) {

		salTotal = horasTrab * 10;

	} else {

		salTotal = 50 * 10;

		valExc = (horasTrab - 50) * 20;

		salTotal += valExc;

	}


	printf("Salario total: %f\nValor excedente: %f\n", salTotal, valExc);

	system("pause");

}