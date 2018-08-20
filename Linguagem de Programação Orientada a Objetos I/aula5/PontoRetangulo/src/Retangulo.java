/**
 * Created by Rafael Nossal on 29/03/2017.
 */
public class Retangulo {
	private double largura;
	private double altura;
	private Ponto vertice;

	public Retangulo(double altura, double largura) {
		this.altura = altura;
		this.largura = largura;
	}

	public Ponto getCentro() {
		Ponto centro = new Ponto();

		centro.setX(vertice.getX() + largura / 2);
		centro.setY(vertice.getY() - altura / 2);

		return centro;
	}

	public double getLargura() {
		return largura;
	}

	public void setLargura(double largura) {
		this.largura = largura;
	}

	public double getAltura() {
		return altura;
	}

	public void setAltura(double altura) {
		this.altura = altura;
	}

	public Ponto getVertice() {
		return vertice;
	}

	public void setVertice(Ponto vertice) {
		this.vertice = vertice;
	}
}