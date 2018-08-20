/**
 * Created by Rafael Nossal on 13/04/2017.
 */
public class Cd extends Produto {
	private int numFaixas;

	public Cd(String nome, double preco, int numFaixas) {
		super(nome, preco);
		this.numFaixas = numFaixas;
	}

	public int getNumFaixas() {
		return numFaixas;
	}

	public void setNumFaixas(int numFaixas) {
		this.numFaixas = numFaixas;
	}

	@Override
	public String toString() {
		return super.toString() + "\nNúmero de faixas: " + numFaixas;
	}
}
