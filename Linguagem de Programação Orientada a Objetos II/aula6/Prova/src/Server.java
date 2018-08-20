import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
	public static void main(String[] args) {
		try {
			ServerSocket server = new ServerSocket(12345 );

			while (true) {
				Socket socket = server.accept();

				new ConexaoServidor(socket).start();
			}
		} catch (IOException ex) {
			ex.printStackTrace();
			System.out.println("Problemas em iniciar o socket na porta selecionada.");
			System.exit(1);
		}
	}
}
