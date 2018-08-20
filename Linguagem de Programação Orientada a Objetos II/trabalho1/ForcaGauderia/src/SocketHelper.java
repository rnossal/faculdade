import java.io.PrintWriter;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class SocketHelper {
	public static String recebeMensagem(Scanner in) {
		try {
			String texto = in.nextLine();

			// String linha;
			// while (in.hasNextLine() && (linha = in.nextLine()) != null) {
			// 	if (linha.length() == 0)
			// 		break;
			// 	texto += linha;
			// }

			return texto;
		} catch (NoSuchElementException ex) {
			return null;
		}
	}

	public static void enviaMensagem(String mensagem, PrintWriter out) {
		out.println(mensagem);
		// out.println();
		out.flush();
	}
}
