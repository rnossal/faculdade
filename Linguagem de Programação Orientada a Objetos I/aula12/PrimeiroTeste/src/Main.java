import java.util.Scanner;

/**
 * Created by Rafael Nossal on 27/06/2017.
 */
public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		try {
			int num1 = scan.nextInt();
			int num2 = scan.nextInt();

			System.out.println(num1 / num2);
		} catch (ArithmeticException ex) {
			System.out.println("Message: " + ex.getMessage());
			ex.printStackTrace();
		} catch (Exception ex) {
			System.out.println("Erro não tratado:");
			ex.printStackTrace();
		}
	}
}
