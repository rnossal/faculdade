import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import model.Palavra;
import model.Ranking;
import model.Usuario;
import model.UsuarioPercentual;

import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.*;

public class ServerConnection extends Thread {
	private Socket socket;
	List<Palavra> palavras;

	public ServerConnection(Socket socket, List<Palavra> palavras) {
		this.socket = socket;
		this.palavras = palavras;
	}

	@Override
	public void run() {
		try {
			String caminhoBinario = "usuarios.bin";
			GsonBuilder gsonb = new GsonBuilder();
			Gson gson = gsonb.excludeFieldsWithoutExposeAnnotation().create();
			Scanner in = new Scanner(socket.getInputStream());
			PrintWriter out = new PrintWriter(socket.getOutputStream());

			while (true) {
				String mensagem = SocketHelper.recebeMensagem(in);

				if (mensagem != null && mensagem.trim().toUpperCase().equals("BUSCARPALAVRA")) {
					int index = (int)(Math.random() * palavras.size());

					SocketHelper.enviaMensagem(gson.toJson(palavras.get(index)), out);
				} else if (mensagem != null && mensagem.trim().toUpperCase().equals("BUSCARRANKING")) {
					ArrayList<Usuario> store = new ArrayList<>();
					ArrayList<UsuarioPercentual> storePercentual = new ArrayList<>();
					try {
						store = ArquivosHelper.leArquivoObjeto(caminhoBinario, ArrayList.class);
					} catch (FileNotFoundException ex) {}

					for (Usuario usuarioStore : store) {
						storePercentual.add(new UsuarioPercentual(usuarioStore.getUsuario(), usuarioStore.getVitorias(), usuarioStore.getDerrotas()));
					}

					storePercentual.sort((sp1, sp2) -> Double.compare(sp2.getPercentual(), sp1.getPercentual()));

					SocketHelper.enviaMensagem(gson.toJson(new Ranking(storePercentual)), out);
				} else if (mensagem != null && mensagem.trim().toUpperCase().startsWith("ENCERRARJOGO")) {
					try {
						String[] dados = mensagem.trim().split(" ");

						ArrayList<Usuario> store = new ArrayList<>();
						try {
							store = ArquivosHelper.leArquivoObjeto(caminhoBinario, ArrayList.class);
						} catch (FileNotFoundException ex) {}
						Usuario usuario = null;
						for (Usuario usuarioStore : store) {
							if (usuarioStore.getUsuario().equals(dados[1]) && usuarioStore.getChave().equals(dados[2])) {
								usuarioStore.setVitorias(usuarioStore.getVitorias() + Integer.parseInt(dados[3]));
								usuarioStore.setDerrotas(usuarioStore.getDerrotas() + Integer.parseInt(dados[4]));
								usuario = usuarioStore;
							}
						}

						if (usuario == null) {
							usuario = new Usuario();
							usuario.setUsuario(dados[1]);
							usuario.setChave(dados[2]);
							usuario.setVitorias(Integer.parseInt(dados[3]));
							usuario.setDerrotas(Integer.parseInt(dados[4]));
							store.add(usuario);
						}

						ArquivosHelper.escreveArquivoObjeto(caminhoBinario, store);

						SocketHelper.enviaMensagem(gson.toJson(usuario), out);
					} catch (Exception ex) {
						System.out.println("Erro ao coletar e salvar as informações do usuário. Fechando conexão com o servidor");
						ex.printStackTrace();
						break;
					}
				} else if (mensagem == null) {
					break;
				}
			}

			in.close();
			out.close();
			socket.close();
		} catch (Exception ex) {
			System.out.println("Houve uma exceção inesperada na conexão do servidor " + getName() + ".");
			ex.printStackTrace();
		}
	}
}
