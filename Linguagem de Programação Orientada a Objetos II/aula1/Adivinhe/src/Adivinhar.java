import java.util.Scanner;

public class Adivinhar {
	public static int scanOnlyInt() {
		Scanner sc = new Scanner(System.in);
		int num;

		try {
			num = Integer.parseInt(sc.nextLine());
		} catch(Exception ex) {
			num = 0;
		}

		return num;
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		System.out.println("Um ou dois jogadores? Responda digitando 1 ou 2 de depois ENTER:");

		int numJogadores = scanOnlyInt();

		while (numJogadores != 1 && numJogadores != 2) {
			System.out.println("Responda digitando 1 ou 2 de depois ENTER:");
			numJogadores = scanOnlyInt();
		}

		int numParaAdivinhar;

		if (numJogadores == 1) {
			numParaAdivinhar = (int)(Math.random() * 1000 + 1);
		} else
		{
			System.out.print("Jogador 1, escolha um número de 1 à 1000: ");
			numParaAdivinhar = scanOnlyInt();

			while (numParaAdivinhar < 1 || numParaAdivinhar > 1000) {
				System.out.print("Escolha um número de 1 à 1000: ");
				numParaAdivinhar = scanOnlyInt();
			}
		}

		int numTentativas = 1;

		System.out.println("Jogador " + numJogadores + " adivinhe o número: ");
		int numTetado = scanOnlyInt();

		while (numTetado != numParaAdivinhar) {
			if (numTetado > numParaAdivinhar) {
				System.out.println("O número digitado é maior que o número a ser adivinhado.");
			} else {
				System.out.println("O número digitado é menor que o número a ser adivinhado.");
			}

			System.out.println("Tente novamente: ");
			numTetado = scanOnlyInt();

			numTentativas++;
		}

		System.out.println("Você acertou o número com " + numTentativas + " tentativas!");
	}
}
