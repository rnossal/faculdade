import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

/**
 * Created by Rafael Nossal on 06/06/2017.
 */
public class Main {
	public static ArrayList<Integer> leRemoveEOrdena() {
		Scanner scan = new Scanner(System.in);

		ArrayList<Integer> numeros = new ArrayList<>();

		System.out.println("Digite números inteiros para a lista (quando digitado um número negativo essa leitura será encerrada:");
		Integer num = scan.nextInt();
		while (num >= 0) {
			numeros.add(num);

			num = scan.nextInt();
		}

		System.out.print("Escolha uma posição da lista ao qual o número deverá ser excluído: ");
		num = scan.nextInt();

		while (num > numeros.size() || num  < 0) {
			System.out.print("Coloque um número entre o intervalo da lista: ");
			num = scan.nextInt();
		}

		if (num >=0)
			numeros.remove(num - 1);

		Collections.sort(numeros);

		return numeros;
	}

	public static void main(String[] args) {
		ArrayList<Integer> numerosLidos = leRemoveEOrdena();

		for (Integer num : numerosLidos) {
			System.out.println(num);
		}
	}
}