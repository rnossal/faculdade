import java.util.ArrayList;
import java.util.Scanner;

/**
 * Created by Rafael Nossal on 06/06/2017.
 */
public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		ArrayList<String> nomes = new ArrayList<>();

		System.out.println("Digite os 10 nomes que irão na lista:");
		for (int i = 0; i < 10; i++) {
			System.out.print("Nome " + (i + 1)  + ": ");
			nomes.add(scan.nextLine());
		}

		System.out.print("Digite um nome para saber se ele está na lista: ");
		String nome = scan.nextLine();

		if (nomes.contains(nome)) {
			System.out.println("O nome está na lista.");
		} else {
			System.out.println("O nome não está na lista.");
		}
	}
}
