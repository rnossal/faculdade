/**
 * Created by Rafael Nossal on 11/04/2017.
 */
public class Mamifero extends Animal {
	public Mamifero(String nome, double comprimento, String cor, double velocidade) {
		super(nome, comprimento, cor, "Terra", velocidade);
	}

	@Override
	public void listaDados() {
		System.out.println("Dados de um mamífero:");
		super.listaDados();
	}
}
