/**
 * Created by Rafael Nossal on 23/03/2017.
 */
public class Carro {
	private String cor;
	private double capacidadeMotor;
	private double velocidade;

	public Carro(String cor, double capacidadeMotor) {
		this.cor = cor;
		this.capacidadeMotor = capacidadeMotor;
	}

	public void aumentarVelocidade(double quantidade) {
		if (quantidade < 0) {
			System.out.println("A velocidade não pode ser negativa.");
			return;
		}
		if ((quantidade + velocidade) > (capacidadeMotor * 110)) {
			System.out.println("Não é possível aumentar a velocidade acima da capacidade do motor.");
			return;
		}

		velocidade += quantidade;
	}

	public void reduzirVelocidade(double quantidade) {
		if (quantidade < 0) {
			System.out.println("A velocidade não pode ser negativa.");
			return;
		}

		if ((velocidade - quantidade) < 0) {
			System.out.println("A velocidade não pode ser reduzida e resultar em um valor negativo.");
			return;
		}

		if (quantidade >= 60) {
			System.out.println("O air-bag foi disparado!");
		}

		velocidade -= quantidade;
	}

	public String getCor() {
		return cor;
	}

	public void setCor(String cor) {
		this.cor = cor;
	}

	public double getCapacidadeMotor() {
		return capacidadeMotor;
	}

	public double getVelocidade() {
		return velocidade;
	}
}
