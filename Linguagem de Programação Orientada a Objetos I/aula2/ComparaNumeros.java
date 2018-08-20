import java.util.Scanner;

/**
 * Created by rnossal on 07/03/17.
 */
public class ComparaNumeros {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int num1, num2;

		System.out.println("Digite um número: ");
		num1 = scan.nextInt();
		System.out.println("Digite outro número: ");
		num2 = scan.nextInt();

		if (num1 == num2) {
			System.out.println("Números iguais");
		} else {
			if (num1 > num2) {
				System.out.println("Primeiro número maior");
			} else {
				System.out.println("Segundo número maior");
			}
		}
	}
}
