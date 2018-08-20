import java.util.ArrayList;
import java.util.Scanner;

public class NomeLista {
	public static void main(String[] args) {
		ArrayList<String> nomes = new ArrayList<>();
		nomes.add("Alice");
		nomes.add("Miguel");
		nomes.add("Arthur");
		nomes.add("Júlia");
		nomes.add("Luiza");
		nomes.add("Helena");
		nomes.add("Gabriel");
		nomes.add("Giovanna");
		nomes.add("Lucas");
		nomes.add("Laura");

		Scanner sc = new Scanner(System.in);
		System.out.print("Digite um nome para verificar se está na lista: ");
		if (nomes.contains(sc.nextLine())) {
			System.out.println("O nome está na lista.");
		} else {
			System.out.println("O nome não está na lista.");
		}
	}
}
