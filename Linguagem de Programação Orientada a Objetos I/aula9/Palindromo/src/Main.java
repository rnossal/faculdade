import java.util.Scanner;
import java.lang.StringBuilder;

/**
 * Created by rnossal on 24/05/17.
 */
public class Main {
	public static String normalizeString(String str) {
		return str
				.trim()
				.replaceAll("\\W+|[0-9]", "")
				.toLowerCase();
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		String texto = normalizeString(scan.nextLine());

		System.out.println(texto);

		if (texto.equals(new StringBuilder(texto).reverse().toString())) {
			System.out.println("A expressão é um palíndromo");
		} else {
			System.out.println("A expressão não é um palíndromo");
		}
	}
}
