import java.util.Scanner;

/**
 * Created by rnossal on 22/05/17.
 */
public class Main {
	public static String normalizeString(String str) {
		return str
				.trim()
				.replaceAll("\\W+|[0-9]", "")
				.toLowerCase();
	}
	public static int getCharArrayProduct(char[] charr) {
		int product = 1;

		for (char aCharr : charr) {
			product *= aCharr;
		}

		return product;
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		char[] palavra1 = normalizeString(scan.nextLine()).toCharArray();
		char[] palavra2 = normalizeString(scan.nextLine()).toCharArray();

		if (getCharArrayProduct(palavra1) == getCharArrayProduct(palavra2)) {
			System.out.println("As duas expressões são anagramas");
		} else {
			System.out.println("As duas expressões não são anagramas");
		}
	}
}
