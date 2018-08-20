import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

public class Client {
	public static void main(String[] args) {
		try {
			Scanner scan = new Scanner(System.in);

			System.out.print("Digite o caminho de uma pasta a ser localizada no servidor: ");
			String dir = scan.nextLine();

			Socket socket = new Socket("localhost", 12345);
			Scanner in = new Scanner(socket.getInputStream());
			PrintWriter out = new PrintWriter(socket.getOutputStream());

			TrocaMensagens.enviaMensagem(dir, out);
			String mensagem = TrocaMensagens.recebeMensagem(in);

			System.out.println("Lista de arquivos nessa pasta:");
			System.out.println(mensagem);

			in.close();
			out.close();
			socket.close();
		} catch (IOException ex) {
			System.out.println("Não foi possível se conectar com o servidor:");
			ex.printStackTrace();
		}
	}
}
