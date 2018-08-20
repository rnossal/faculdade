import java.util.Locale;
import java.util.Scanner;

/**
 * Created by Rafael Nossal on 23/03/2017.
 */
public class Main {
	private static void printOpcoes() {
		System.out.println("Opções disponíveis:");
		System.out.println("\t0 => Sair");
		System.out.println("\t1 => Aumentar a velocidade");
		System.out.println("\t2 => Diminuir a velocidade\n");
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		System.out.print("Digite a cor do carro: ");
		String cor = scan.nextLine();

		System.out.print("Digite a capacidade do motor do carro: ");
		double capacidade = scan.nextDouble();
		scan.nextLine(); // Consome a quebra de linha que o nextDouble() não captura.

		Carro carro = new Carro(cor, capacidade);

		printOpcoes();

		boolean rodar = true;
		while (rodar) {
			System.out.print("Digite um opção: ");
			String opt = scan.nextLine();

			switch (opt) {
				case "0":
					rodar = false;
					break;
				case "1":
					System.out.println("Digite a quantidade de aumento de velocidade: ");
					carro.aumentarVelocidade(scan.nextDouble());
					scan.nextLine(); // Consome a quebra de linha que o nextDouble() não captura.
					System.out.println("A velocidade do carro no momento é: " + carro.getVelocidade() + "km/h\n");
					break;
				case "2":
					System.out.println("Digite a quantidade de redução de velocidade: ");
					carro.reduzirVelocidade(scan.nextDouble());
					scan.nextLine(); // Consome a quebra de linha que o nextDouble() não captura.
					System.out.println("A velocidade do carro no momento é: " + carro.getVelocidade() + "km/h\n");
					break;
				default:
					System.out.println("Opção inválida. Digite uma das opções disponíveis.");
					printOpcoes();
			}
		}
	}
}
