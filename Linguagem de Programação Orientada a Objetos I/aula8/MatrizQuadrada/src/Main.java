import java.util.Scanner;

/**
 * Created by Rafael Nossal on 09/05/2017.
 */

/*
Faça um programa em Java que solicite ao usuário a dimensão de uma matriz quadrada de valores inteiros.
Após, solicite ao usuário o valor de cada uma das posições.
Por fim, calcule:
	A soma dos valores da diagonal principal
	O produto dos valores da diagonal secundária
	A soma dos valores que não estão nas posições das diagonais
 */
public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		System.out.print("Qual a ordem da matriz quadrada desejada? ");
		MatrizQuadrada qMatriz = new MatrizQuadrada(scan.nextInt());

		for (int i = 0; i < qMatriz.getMatriz().length; i++) {
			for (int j = 0; j < qMatriz.getMatriz()[i].length; j++) {
				System.out.print("Informe o valor da posição " + (i + 1) + "-" + (j + 1) + " da matriz: ");
				qMatriz.getMatriz()[i][j] = scan.nextInt();
			}
		}

		System.out.println(qMatriz.somaDiagonalPrincipal());
		System.out.println("---------------------------------");
		System.out.println(qMatriz.produtoDiagonalSeguncaria());
		System.out.println("---------------------------------");
		System.out.println(qMatriz.somaDemaisValores());
	}
}