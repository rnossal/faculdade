/**
 * Created by Rafael Nossal on 23/03/2017.
 */
public class Porta {
	private boolean aberto;
	private String cor;

	public Porta() {
		aberto = false;
	}

	public void abre() {
		aberto = true;
	}

	public void fecha() {
		aberto = false;
	}

	public boolean estaAberta() {
		return aberto;
	}

	public  void pinta (String cor) {
		this.cor = cor;
	}

	public String getCor() {
		return cor;
	}
}
