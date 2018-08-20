import java.util.Scanner;

/**
 * Created by rnossal on 07/03/17.
 */
public class SomaImpares {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int num;

		System.out.println("Digite um número: ");
		num = scan.nextInt();

		if (num >= 0) {
			int soma = 0;
			for (int i = 0; i <= num; i++) {
				if (i % 2 != 0) {
					soma += i;
				}
			}

			System.out.println(soma);
		} else {
			System.out.println("Número inválido");
		}
	}
}
