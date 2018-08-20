/**
 * Created by Rafael Nossal on 29/03/2017.
 */
public class BombaCombustivel {
	private String tipoDeCombustivel;
	private double valorPorLitro;
	private double quantidadeDeCombustivel;

	public double abastecerPorValor(double valor) {
		double qtdLitros = valor / valorPorLitro;

		if (valor < 0) {
			System.out.println("Só são válidos valores positivos");
			return 0;
		}
		if (quantidadeDeCombustivel - qtdLitros < 0) {
			System.out.println("A bomba não possui combustível suficiente");
			return 0;
		}

		quantidadeDeCombustivel -= qtdLitros;

		return qtdLitros;
	}
	public double abastecerPorLitro(double litros) {
		if (litros < 0) {
			System.out.println("Só são válidos valores positivos");
			return 0;
		}
		if ((quantidadeDeCombustivel - litros) < 0) {
			System.out.println("A bomba não possui combustível suficiente");
			return 0;
		}

		quantidadeDeCombustivel -= litros;

		return litros * valorPorLitro;
	}

	public String getTipoDeCombustivel() {
		return tipoDeCombustivel;
	}

	public void setTipoDeCombustivel(String tipoDeCombustivel) {
		this.tipoDeCombustivel = tipoDeCombustivel;
	}

	public double getValorPorLitro() {
		return valorPorLitro;
	}

	public void setValorPorLitro(double valorPorLitro) {
		this.valorPorLitro = valorPorLitro;
	}

	public double getQuantidadeDeCombustivel() {
		return quantidadeDeCombustivel;
	}

	public void setQuantidadeDeCombustivel(double quantidadeDeCombustivel) {
		this.quantidadeDeCombustivel = quantidadeDeCombustivel;
	}
}
