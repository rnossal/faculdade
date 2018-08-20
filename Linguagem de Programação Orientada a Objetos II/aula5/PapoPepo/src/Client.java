import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

public class Client {
	public static void main(String[] args) {
		try {
			Socket skt = new Socket("localhost", 6543);
			Scanner input = new Scanner(skt.getInputStream());
			PrintWriter output = new PrintWriter(skt.getOutputStream());

			output.println("PAPO");
			output.flush();

			String line;
			while ((line = input.nextLine()) != null) {
				System.out.println(line);
				output.println("PAPO");
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
