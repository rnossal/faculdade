/**
 * Created by Rafael Nossal on 05/04/2017.
 */
public class Lampada {
	private boolean acesa;

	public Lampada() {
		acesa = false;
	}

	public void acender() {
		acesa = true;
	}
	public void apagar() {
		acesa = false;
	}
	public boolean estaLigada() {
		return acesa;
	}
}
