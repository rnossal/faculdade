import java.io.Serializable;

public class Aluno implements Serializable {
	private String nome;
	private double g1;
	private double g2;

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public double getG1() {
		return g1;
	}

	public void setG1(double g1) {
		this.g1 = g1;
	}

	public double getG2() {
		return g2;
	}

	public void setG2(double g2) {
		this.g2 = g2;
	}

	public double getMedia() {
		return (g1 + g2 * 2) / 3;
	}

	public String getSituacao() {
		if (getMedia() >= 6) {
			return "APROVADO";
		} else {
			return "SUBSTITUIÇÃO";
		}
	}
}
