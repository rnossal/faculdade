/**
 * Created by Rafael Nossal on 23/03/2017.
 */
public class Main {
	public static void main(String[] args) {
		Porta porta = new Porta();

		porta.abre();
		porta.fecha();

		porta.pinta("Azul");
		porta.pinta("Amarelo");
		porta.pinta("Branco");

		System.out.println(porta.estaAberta());
	}
}
