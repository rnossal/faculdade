/**
 * Created by rnossal on 13/03/17.
 */
public class Empregado {
	private String nome;
	private double salario;

	public double aumentaSalario(double percentual) {
		if (percentual >= 0) {
			salario += salario * (percentual / 100);
		}
		return salario;
	}
	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public double getSalario() {
		return salario;
	}

	public void setSalario(double salario) {
		if (salario >= 0) {
			this.salario = salario;
		} else {
			this.salario = 0;
		}
	}
}
