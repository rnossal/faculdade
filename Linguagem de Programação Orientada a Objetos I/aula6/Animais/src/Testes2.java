import java.util.Scanner;

/**
 * Created by Rafael Nossal on 11/04/2017.
 */
public class Testes2 {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		Animal anim;

		System.out.println("Qual o tipo de animal deseja criar:\n\t1 - Peixe\n\t2 - Mamífero");

		String tipo = scan.nextLine();
		while(!tipo.equals("1") && !tipo.equals("2")) {
			System.out.print("Responda com 1 ou 2: ");
			tipo = scan.nextLine();
		}

		System.out.print("Digite o nome: ");
		String nome = scan.nextLine();

		System.out.print("Digite o comprimento: ");
		double comprimento = scan.nextDouble();
		scan.nextLine();

		String cor = "";
		if(tipo.equals("2")) {
			System.out.print("Digite a cor: ");
			cor = scan.nextLine();
		}

		System.out.print("Digite a velocidade: ");
		double velocidade = scan.nextDouble();
		scan.nextLine();

		if(tipo.equals("1")) {
			anim = new Peixe(nome, comprimento, velocidade);
		} else {
			anim = new Mamifero(nome, comprimento, cor, velocidade);
		}

		System.out.println("\n");
		anim.listaDados();
	}
}
/*
Crie uma segunda classe de testes para que o usuário possa definir qual tipo de animal criar e informar os dados deles. Depois do usuário informar os dados, imprima os valores dos animais.
 */