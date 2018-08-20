import model.Palavra;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Scanner;

public class Server {
	public static void main(String[] args) {
		ServerSocket server;
		ArrayList<Palavra> palavras = new ArrayList<>();

		//region Carrega o arquivo de palavras e joga para dentro do ArrayList palavras.
		try {
			Scanner scan = new Scanner(new File("resources/ListaPalavras.txt"), "UTF-8");

			String linha;
			while (scan.hasNextLine() && (linha = scan.nextLine()) != null) {
				String[] lineSplit = linha.split("\\|");
				if (lineSplit.length == 2)
					palavras.add(new Palavra(lineSplit[0], lineSplit[1]));
			}

			scan.close();
		} catch (FileNotFoundException ex) {
			System.out.println("Arquivo de palavras não encontrado. Verifique se o arquivo \"ListaPalavras.txt\" está no diretório \"resources\" que deverá estar mesmo diretório em que esse servidor está sendo executado.");
			System.out.println("Diretório executado: " + System.getProperty("user.dir"));
			System.exit(1);
		}
		//endregion

		//region Levanta o servidor e escuta as conexões.
		try {
			server = new ServerSocket(8765 );

			while (true) {
				Socket socket = server.accept();

				new ServerConnection(socket, palavras).start();
			}
		} catch (IOException ex) {
			System.out.println("Problemas em iniciar o socket na porta selecionada.");
			System.exit(1);
		}
		//endregion
	}
}
