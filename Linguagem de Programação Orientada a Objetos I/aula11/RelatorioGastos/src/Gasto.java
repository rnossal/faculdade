/**
 * Created by Rafael Nossal on 21/06/2017.
 */
public class Gasto {
	private String descricao;
	private int mes;
	private double valor;

	public Gasto(String descricao, int mes, double valor) {
		if (mes > 12 || mes < 1)
			System.out.println("Mês inválido");

		this.descricao = descricao;
		this.mes = mes;
		this.valor = valor;
	}

	public String getDescricao() {
		return descricao;
	}

	public void setDescricao(String descricao) {
		this.descricao = descricao;
	}

	public int getMes() {
		return mes;
	}

	public String getMesNome() {
		switch (mes) {
			case 1:
				return "Janeiro";
			case 2:
				return "Fevereiro";
			case 3:
				return "Março";
			case 4:
				return "Abril";
			case 5:
				return "Maio";
			case 6:
				return "Junho";
			case 7:
				return "Julho";
			case 8:
				return "Agosto";
			case 9:
				return "Setembro";
			case 10:
				return "Outubro";
			case 11:
				return "Novembro";
			case 12:
				return "Dezembro";
			default:
				return "Mês inválido";
		}
	}

	public void setMes(int mes) {
		this.mes = mes;
	}

	public double getValor() {
		return valor;
	}

	public void setValor(double valor) {
		this.valor = valor;
	}
}
