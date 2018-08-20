import javafx.geometry.Pos;

/**
 * Created by Rafael Nossal on 29/03/2017.
 */
public class Main {
	public static void main(String[] args) {
		Retangulo ret1 = new Retangulo(2, 3);
		ret1.setVertice(new Ponto(3, 5));

		Retangulo ret2 = new Retangulo(2, 3);
		ret2.setVertice(new Ponto(-4, 5));

		Retangulo ret3 = new Retangulo(10, 11);
		ret3.setVertice(new Ponto(2, -4));

		ret1.getCentro().imprime();
		ret2.getCentro().imprime();
		ret3.getCentro().imprime();
	}
}
