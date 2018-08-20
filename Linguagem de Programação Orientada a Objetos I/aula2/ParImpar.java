import java.util.Scanner;

/**
 * Created by rnossal on 06/03/17.
 */
public class ParImpar {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int num1, num2;

		System.out.println("Digite o primeiro número: ");
		num1 = scan.nextInt();
		System.out.println("Digite o segundo número: ");
		num2 = scan.nextInt();

		if ((num1 + num2) % 2 == 0) {
			System.out.println("PAR");
		} else {
			System.out.println("IMPAR");
		}
	}
}
