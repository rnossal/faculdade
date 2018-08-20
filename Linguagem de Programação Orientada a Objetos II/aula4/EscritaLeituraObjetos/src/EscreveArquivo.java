import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.Scanner;

public class EscreveArquivo {
	public static void main(String[] args) {
		ArrayList<Aluno> alunos = new ArrayList<>();
		Scanner scan = new Scanner(System.in);

		File fileEscrita = new File("alunos.dat");

		for (int i = 0; i < 5; i++) {
			Aluno aluno = new Aluno();

			System.out.print("Digite o nome do aluno " + (i + 1) + ": ");
			aluno.setNome(scan.nextLine());
			System.out.print("A nota da G1 do aluno " + aluno.getNome() + ": ");
			aluno.setG1(scan.nextDouble());
			System.out.print("A nota da G2 do aluno " + aluno.getNome() + ": ");
			aluno.setG2(scan.nextDouble());
			scan = new Scanner(System.in);

			alunos.add(aluno);
		}

		try {
			ObjectOutputStream objStream = new ObjectOutputStream(new FileOutputStream(fileEscrita));
			objStream.writeObject(alunos);
			objStream.close();

			System.out.println("Arquivo com os dados de alunos criados com sucesso!");
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
