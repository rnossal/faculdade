import java.util.Scanner;

/**
 * Created by rnossal on 07/03/17.
 */
public class Detetive {
	public static boolean pergunta() {
		Scanner scan = new Scanner(System.in);

		String resposta = scan.nextLine();
		while(!resposta.equalsIgnoreCase("sim") && !resposta.equalsIgnoreCase("nao")&& !resposta.equalsIgnoreCase("não")) {
			System.out.println("Responda com sim ou não");
			resposta = scan.nextLine();
		}

		return resposta.equalsIgnoreCase("sim") ? true : false;
	}

	public static void main(String[] args) {
		int questoesPositivas = 0;

		System.out.println("Telefonou para a vítima?");
		questoesPositivas += pergunta() == true ? 1 : 0;

		System.out.println("Esteve no local do crime?");
		questoesPositivas += pergunta() == true ? 1 : 0;

		System.out.println("Mora perto da vítima?");
		questoesPositivas += pergunta() == true ? 1 : 0;

		System.out.println("Devia para a vítima?");
		questoesPositivas += pergunta() == true ? 1 : 0;

		System.out.println("Já trabalhou com a vítima?");
		questoesPositivas += pergunta() == true ? 1 : 0;

		if (questoesPositivas == 2) {
			System.out.println("Suspeita");
		} else if (questoesPositivas >= 3 && questoesPositivas <= 4) {
			System.out.println("Cúmplice");
		} else if (questoesPositivas == 5) {
			System.out.println("Assassino");
		} else {
			System.out.println("Inocente");
		}
	}
}
