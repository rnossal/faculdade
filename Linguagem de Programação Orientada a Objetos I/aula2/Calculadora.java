import java.util.Scanner;

/**
 * Created by rnossal on 06/03/17.
 */
public class Calculadora {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int num1, num2;

		System.out.println("Digite o primeiro número: ");
		num1 = scan.nextInt();
		System.out.println("Digite o segundo número: ");
		num2 = scan.nextInt();

		System.out.println("Soma: " + (num1 + num2));
		System.out.println("Subtração: " + (num1 - num2));
		System.out.println("Multiplicação: " + (num1 * num2));
		System.out.println(num2 == 0? "Impossível dividir por zero." : "Divisão: " + (double)(num1 / num2));
	}
}
