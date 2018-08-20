import java.util.Scanner;

/**
 * Created by rnossal on 07/03/17.
 */
public class DiasSemana {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int num;

		System.out.println("Informe um número de semana: ");
		num = scan.nextInt();

		switch (num) {
			case 1:
				System.out.println("Domingo");
				break;
			case 2:
				System.out.println("Segunda-Feira");
				break;
			case 3:
				System.out.println("Terça-Feira");
				break;
			case 4:
				System.out.println("Quarta-Feira");
				break;
			case 5:
				System.out.println("Quinta-Feira");
				break;
			case 6:
				System.out.println("Sexta-Feira");
				break;
			case 7:
				System.out.println("Sábado");
				break;
			default:
				System.out.println("Dia inválido");
		}
	}
}
