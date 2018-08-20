import java.util.Scanner;

/**
 * Created by rnossal on 06/03/17.
 */
public class Quadrado {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int num1, num2;

		System.out.println("Digite a altura: ");
		num1 = scan.nextInt();
		System.out.println("Digite a largura: ");
		num2 = scan.nextInt();

		for(int i = 0; i < num1; i++) {
			for (int j = 0; j < num2; j++) {
				System.out.print("X");
			}
			System.out.println("");
		}
	}
}
