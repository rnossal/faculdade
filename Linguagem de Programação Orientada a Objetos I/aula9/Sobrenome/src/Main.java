import java.util.Scanner;

/**
 * Created by rnossal on 22/05/17.
 */
public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		String[] nomeCompleto = scan.nextLine().trim().replace(" +", " ").split(" ");

		if (nomeCompleto.length == 1 || nomeCompleto.length == 0) {
			System.out.println("Sobrenome não informado");
		} else {
			System.out.println(nomeCompleto[nomeCompleto.length -1]);
		}
	}
}
