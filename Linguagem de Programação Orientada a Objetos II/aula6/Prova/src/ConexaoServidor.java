import java.io.File;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.*;

public class ConexaoServidor extends Thread {
	private Socket socket;

	public ConexaoServidor(Socket socket) {
		this.socket = socket;
	}

	public String listaArquivos(File[] lista) {
		String arquivos = "";
		for (File entrada : lista) {
			if (entrada.isFile()) {
				arquivos += entrada.getName() + "\n";
			}// else {
				//arquivos += listaArquivos(entrada.listFiles());
			//}
		}

		return arquivos;
	}

	@Override
	public void run() {
		try {
			Scanner in = new Scanner(socket.getInputStream());
			PrintWriter out = new PrintWriter(socket.getOutputStream());

			while (true) {
				String mensagem = TrocaMensagens.recebeMensagem(in);

				if (mensagem != null) {
					mensagem = mensagem.trim();

					File pasta = new File(mensagem);
					if (pasta.exists() && pasta.isDirectory() && pasta.canRead()) {
						String arquivos = listaArquivos(pasta.listFiles());

						TrocaMensagens.enviaMensagem(arquivos, out);
					} else if (pasta.isDirectory() && !pasta.canRead()) {
						TrocaMensagens.enviaMensagem("SEM_PERMISSÃO", out);
					} else if (!pasta.isDirectory()) {
						TrocaMensagens.enviaMensagem("PASTA_INEXISTENTE", out);
					}
				}
			}
		} catch (Exception ex) {
			System.out.println("Houve uma exceção inesperada na conexão do servidor " + getName() + ".");
			ex.printStackTrace();
		}
	}
}
