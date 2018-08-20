import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		System.out.println("Informe o nome do arquivo a ser acessado: ");
		File arq = new File(scan.nextLine());

		if (arq.exists()) {
			int vogalA = 0, vogalE = 0, vogalI = 0, vogalO = 0, vogalU = 0;
			try {
				Scanner txt = new Scanner(arq);

				while (txt.hasNextLine()) {
					String linha = txt.nextLine();

					vogalA += linha.length() - linha.toUpperCase().replace("A", "").length();
					vogalE += linha.length() - linha.toUpperCase().replace("E", "").length();
					vogalI += linha.length() - linha.toUpperCase().replace("I", "").length();
					vogalO += linha.length() - linha.toUpperCase().replace("O", "").length();
					vogalU += linha.length() - linha.toUpperCase().replace("U", "").length();
				}

				System.out.println("Total de A: " + vogalA);
				System.out.println("Total de E: " + vogalE);
				System.out.println("Total de I: " + vogalI);
				System.out.println("Total de O: " + vogalO);
				System.out.println("Total de U: " + vogalU);
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		} else {
			System.out.println("O arquivo informado não existe!");
		}
	}
}
