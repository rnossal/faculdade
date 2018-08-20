import java.util.Locale;
import java.util.Scanner;

/**
 * Created by rnossal on 13/03/17.
 */
public class Main {
	public static void main(String[] args) {
		// Forçando localidade para en-US porque digitar número de ponto flutuante com vírgula é zoado.
		Scanner scan = new Scanner(System.in).useLocale(Locale.US);

		Empregado empregado = new Empregado();

		System.out.print("Digite o nome do empregado: ");
		empregado.setNome(scan.nextLine());
		System.out.print("Digite o salário do empregado: ");
		empregado.setSalario(scan.nextDouble());

		System.out.print("Digite o percentual de aumento: ");
		empregado.aumentaSalario(scan.nextDouble());

		System.out.print("Novo salário: " + empregado.getSalario() + "\n");
	}
}
