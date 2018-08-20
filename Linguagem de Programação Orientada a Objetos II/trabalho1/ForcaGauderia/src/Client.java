import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import model.Palavra;
import model.Ranking;
import model.Usuario;
import model.UsuarioPercentual;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Scanner;

public class Client {
	private static <T> T recebeMensagem(Scanner in, Class<T> classe) {
		GsonBuilder gsonb = new GsonBuilder();
		Gson gson = gsonb.excludeFieldsWithoutExposeAnnotation().create();

		String mensagem = SocketHelper.recebeMensagem(in);

		return gson.fromJson(mensagem, classe);
	}

	private static void printPalavra(Palavra palavra, ArrayList<Character> letrasAcertadas) {
		System.out.print("A palavra sorteada possui " + palavra.getPalavra().length() + " letras: ");

		int qtdCerto = 0;
		for (int i = 0; i < palavra.getPalavra().length(); i++) {
			char charAt = palavra.getPalavra().toUpperCase().charAt(i);

			if (letrasAcertadas.contains(charAt)) {
				qtdCerto++;
				System.out.print(palavra.getPalavra().charAt(i));
			} else if (!Character.isLetter(charAt)) {
				System.out.print(palavra.getPalavra().charAt(i));
			} else {
				System.out.print("_");
			}
		}

		if (qtdCerto >= (palavra.getPalavra().length() / 2))
			System.out.println("\nDica: " + palavra.getDica());

		System.out.println();
	}

	private static boolean acertouPalavra(Palavra palavra, ArrayList<Character> letrasAcertadas) {
		for (int i = 0; i < palavra.getPalavra().length(); i++) {
			char charAt = palavra.getPalavra().toUpperCase().charAt(i);

			if (Character.isLetter(charAt) && !letrasAcertadas.contains(charAt)) {
				return false;
			}
		}

		return true;
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		System.out.print("Informe o endereço do servidor: ");
		String endereco = scan.nextLine();
		while (endereco.length() == 0) {
			System.out.print("Você deve o endereço do servidor: ");
			endereco = scan.nextLine();
		}
		System.out.print("Informe a porta do servidor (somente números): ");
		int porta = 0;
		while (porta == 0) {
			try {
				porta = Integer.parseInt(scan.nextLine());
			} catch (Exception ex) {
				System.out.print("Informe uma porta válida: ");
			}
		}
		System.out.print("Informe o nome do usuário: ");
		String nomeUsuario = scan.nextLine();
		while (nomeUsuario.length() == 0) {
			System.out.print("Você deve informar o nome do usuário: ");
			nomeUsuario = scan.nextLine();
		}
		System.out.print("Informe a chave do usuário: ");
		String chaveUsuario = scan.nextLine();
		while (chaveUsuario.length() == 0) {
			System.out.print("Você deve informar um nome de usuário: ");
			chaveUsuario = scan.nextLine();
		}

		try {
			Socket socket = new Socket(endereco, porta);
			Scanner in = new Scanner(socket.getInputStream());
			PrintWriter out = new PrintWriter(socket.getOutputStream());

			int vitorias = 0;
			int derrotas = 0;
			while (true) {
				SocketHelper.enviaMensagem("BUSCARPALAVRA", out);
				Palavra palavra = recebeMensagem(in, Palavra.class);

				int erros = 0;
				ArrayList<Character> letrasAcertadas = new ArrayList<>();
				while (true) {
					printPalavra(palavra, letrasAcertadas);

					System.out.print("\nDigite uma letra (se digitado mais de uma, só a primeira será considerada): ");
					String lido = scan.nextLine();
					if (lido.length() == 0) {
						System.out.println("Você deve digitar a letra antes de dar enter.");
						continue;
					}

					char letra = Character.toUpperCase(lido.charAt(0));

					if (!Character.isLetter(letra)) {
						System.out.println("Somente letras de A á Z são válidas.");
						continue;
					}

					if (palavra.getPalavra().toUpperCase().indexOf(letra) != -1) {
						if (letrasAcertadas.indexOf(letra) == -1) {
							letrasAcertadas.add(letra);

							if (acertouPalavra(palavra, letrasAcertadas)) {
								System.out.println("Você acertou!");
								System.out.println("A palavra é " + palavra.getPalavra());
								vitorias++;
								break;
							}
						} else {
							System.out.println("Essa letra já foi escolhida. Tente outra letra.");
						}
					} else {
						erros++;
						if (erros <= 4) {
							System.out.println("Não tem essa letra, tente novamente");
						} else {
							System.out.println("Quinto erro. Você perdeu!");
							System.out.println("A palavra era: " + palavra.getPalavra());
							derrotas++;
							break;
						}
					}
				}

				System.out.print("Deseja jogar novamente (responda com SIM ou NÃO)? ");
				String resposta = scan.nextLine().toUpperCase();
				while (!resposta.equals("SIM") && !resposta.equals("NÃO") && !resposta.equals("NAO")) {
					System.out.println("Responda com SIM ou NÃO");
					resposta = scan.nextLine().toUpperCase();
				}
				if (resposta.equals("NÃO") || resposta.equals("NAO")) {
					SocketHelper.enviaMensagem("ENCERRARJOGO " + nomeUsuario + " " + chaveUsuario + " " + vitorias  + " " + derrotas, out);
					Usuario usuario = recebeMensagem(in, Usuario.class);
					break;
				}
			}

			SocketHelper.enviaMensagem("BUSCARRANKING", out);
			Ranking ranking = recebeMensagem(in, Ranking.class);
			System.out.println("Ranking de usuários:");
			for (UsuarioPercentual usuarioPercentual : ranking.getRanking()) {
				System.out.println("\tUsuário: " + usuarioPercentual.getUsuario());
				System.out.println("\tVitórias: " + usuarioPercentual.getVitorias());
				System.out.println("\tDerrotas: " + usuarioPercentual.getDerrotas());
				System.out.println("\tPercentual de vitórias: " + usuarioPercentual.getPercentual() + "\n");
			}

			in.close();
			out.close();
			socket.close();
		} catch (IOException ex) {
			System.out.println("Não foi possível se conectar com o servidor:");
			ex.printStackTrace();
		}
	}
}
