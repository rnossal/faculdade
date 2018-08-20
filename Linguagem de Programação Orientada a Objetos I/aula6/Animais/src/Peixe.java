/**
 * Created by Rafael Nossal on 11/04/2017.
 */
public class Peixe extends Animal {
	public Peixe(String nome, double comprimento, double velocidade) {
		super(nome, comprimento, "Cinza", "Mar", velocidade);
		setNumPatas(0);
	}

	@Override
	public void listaDados() {
		System.out.println("Dados de um peixe:");
		super.listaDados();
	}
}
