/**
 * Created by Rafael Nossal on 13/06/2017.
 */
public class Pedido {
	private String nome;
	private double valor;

	public Pedido(String nome, double valor) {
		this.nome = nome;
		this.valor = valor;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public double getValor() {
		return valor;
	}

	public void setValor(double valor) {
		this.valor = valor;
	}
}
