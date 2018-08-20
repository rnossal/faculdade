import java.util.Scanner;

/**
 * Created by rnossal on 16/04/17.
 */
public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		FabricaLampadas fabrica = new FabricaLampadas();

		System.out.print("Digite \"L\" para criar uma lâmpada LED e \"F\" para uma fluorescente: ");

		Lampada l = fabrica.criaLampada(scan.nextLine().charAt(0));

		if (l == null) {
			System.out.println("Comando inválido e assim nenhuma lâmpada criada.");
		} else {
			l.ligar();
			l.mostraEstado();
			l.desligar();
			l.mostraEstado();
		}
	}
}
