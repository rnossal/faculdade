import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class Server {
	public static void main(String[] args) {
		try {
			ServerSocket srv = new ServerSocket(6543);
			Socket skt = srv.accept();
			Scanner input = new Scanner(skt.getInputStream());
			PrintWriter output = new PrintWriter(skt.getOutputStream());

			String line;
			while ((line = input.nextLine()) != null) {
				System.out.println(line);
				output.println("PEPO");
				output.flush();
			}

			input.close();
			output.close();
			skt.close();
		} catch (IOException ex) {
			ex.printStackTrace();
		}
	}
}
