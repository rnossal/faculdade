/**
 * Created by Rafael Nossal on 09/05/2017.
 */
public class Trabalhador {
	private String nome;
	private  double salarioPorHora;

	public Trabalhador(String nome, double salarioPorHora) {
		this.nome = nome;
		this.salarioPorHora = salarioPorHora;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public double getSalarioHora() {
		return salarioPorHora;
	}

	public void setSalarioPorHora(double salarioPorHora) {
		this.salarioPorHora = salarioPorHora;
	}
}
