/*
Construa um algoritmo para pagamento de comissão de vendedores de peças, levando em consideração que sua comissão será de 5% do total da venda e que você tem os seguintes dados que deverão ser fornecidos pelo usuário: preço unitário das peças e a quantidade de peças vendidas.
*/
#include <stdio.h>
int main (void) {
	float preco, qtdTotal;
	printf("Digite o preco unitario por peca:\n");
	scanf("%f", &preco);
	printf("Digite a quantidade de pecas vendidas:\n");
	scanf("%f", &qtdTotal);

	float total = (preco * qtdTotal) * 0.05;

	printf("Valor da comicao: %f\n", total);
	system("pause");
}
