/**
 * Created by Rafael Nossal on 09/05/2017.
 */
public class Assalariado extends  Trabalhador{
	public Assalariado(String nome, double salarioPorHora) {
		super(nome, salarioPorHora);
	}

	public double calculaPagamento() {
		return super.getSalarioHora() * 250;
	}
}
