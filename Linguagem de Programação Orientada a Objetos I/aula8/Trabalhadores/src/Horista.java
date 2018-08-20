/**
 * Created by Rafael Nossal on 09/05/2017.
 */
public class Horista extends  Trabalhador {
	private double horasTrabalhadas;

	public Horista(String nome, double salarioPorHora, double horasTrabalhadas) {
		super(nome, salarioPorHora);
		this.horasTrabalhadas = horasTrabalhadas;
	}

	public double calculaPagamento() {
		return super.getSalarioHora() * horasTrabalhadas;
	}

	public double getHorasTrabalhadas() {
		return horasTrabalhadas;
	}

	public void setHorasTrabalhadas(double horasTrabalhadas) {
		this.horasTrabalhadas = horasTrabalhadas;
	}
}
