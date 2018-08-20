/**
 * Created by rnossal on 16/04/17.
 */
public class Lampada {
	private String estado;

	public Lampada() {
		estado = "desligada";
	}

	public void ligar() {
		estado = "ligada";
	}
	public void desligar() {
		estado = "desligada";
	}
	public void mostraEstado() {
		System.out.println(estado);
	}
}
