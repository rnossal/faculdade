import java.util.Scanner;

/**
 * Created by Rafael Nossal on 05/06/2017.
 */
public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		FiguraGeometrica[] figuras;

		System.out.print("Quantas forma deseja criar? ");
		int qtdFormas = scan.nextInt();

		figuras = new FiguraGeometrica[qtdFormas];

		for (int i = 0; i < qtdFormas; i++) {
			System.out.println("Qual forma deseja criar?");
			System.out.println("\t1 - Quadrado\n\t2 - Retângulo\n\t3 - Círculo");

			int tipo = scan.nextInt();

			if (tipo < 1 && tipo > 3) {
				System.out.println("Tipo de forma inválida!");
				i--;
				continue;
			}

			if (tipo == 1) {
				System.out.print("Digite o tamanho do lado do quadrado: ");
				figuras[i] = new Quadrado(scan.nextDouble());
			} else if (tipo == 2) {
				System.out.print("Digite a base e altura respectivamente: ");
				figuras[i] = new Retangulo(scan.nextDouble(), scan.nextDouble());
			} else {
				System.out.print("Digite o raio do círculo: ");
				figuras[i] = new Circulo(scan.nextDouble());
			}
		}

		for (FiguraGeometrica figura : figuras) {
			if (figura instanceof Quadrado) {
				System.out.println("Quadrado:");
				System.out.println("Lado: " + ((Quadrado) figura).getLado1());
			} else if (figura instanceof Retangulo) {
				System.out.println("Retângulo:");
				System.out.println("Base: " + ((Retangulo) figura).getLado1());
				System.out.println("Altura: " + ((Retangulo) figura).getLado2());
			} else if (figura instanceof Circulo) {
				System.out.println("Círculo");
				System.out.println("Raio: " + ((Circulo) figura).getRaio());
			}

			System.out.println("Perímetro: " + figura.calculaPerimetro());
			System.out.println("Área: " + figura.calculaArea());

			System.out.println("");
		}
	}
}
