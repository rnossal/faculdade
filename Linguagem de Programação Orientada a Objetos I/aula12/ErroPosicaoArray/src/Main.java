import java.util.Scanner;

/**
 * Created by Rafael Nossal on 27/06/2017.
 */
public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int[] vet = new int[10];

		for(int i = 0; i < vet.length; i++) {
			vet[i] = (int)(Math.random() * 100);
		}

		try {
			int num = scan.nextInt();

			System.out.println(vet[num]);
		} catch (ArrayIndexOutOfBoundsException ex) {
			System.out.println("Essa posição não existe no array.");
			ex.printStackTrace();
		} catch (Exception ex) {
			System.out.println("Erro não tratado:");
			ex.printStackTrace();
		}
	}
}
