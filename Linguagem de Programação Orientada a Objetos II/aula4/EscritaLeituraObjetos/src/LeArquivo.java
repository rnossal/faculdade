import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.util.ArrayList;
import java.util.Scanner;

public class LeArquivo {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		System.out.print("Digite o nome do arquivo a ser lido: ");
		File fileLeitura = new File(scan.nextLine());

		if (fileLeitura.exists()) {
			try {
				ObjectInputStream objStream = new ObjectInputStream(new FileInputStream(fileLeitura));
				ArrayList<Aluno> alunos = (ArrayList<Aluno>)objStream.readObject();

				for(Aluno aluno : alunos){
					System.out.println(aluno.getNome() + ":");
					System.out.println("\tG1: " + aluno.getG1());
					System.out.println("\tG2: " + aluno.getG2());
					System.out.println("\tMédia: " + aluno.getMedia());
					System.out.println("\tSituação: " + aluno.getSituacao());
				}

				objStream.close();
			} catch (IOException | ClassNotFoundException e) {
				e.printStackTrace();
			}
		} else {
			System.out.println("Arquivo não existe!");
		}
	}
}
