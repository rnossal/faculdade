/**
 * Created by Rafael Nossal on 05/04/2017.
 */
public class Main {
	public static void main(String[] args) {
		Lampada lamp = new Lampada();

		System.out.println(lamp.estaLigada());
		lamp.acender();
		System.out.println(lamp.estaLigada());
		lamp.apagar();
		System.out.println(lamp.estaLigada());
		lamp.acender();
		lamp.apagar();
		System.out.println(lamp.estaLigada());
	}
}
