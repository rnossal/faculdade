import java.lang.Math;

/**
 * Created by Rafael Nossal on 05/06/2017.
 */
public class Circulo implements FiguraGeometrica {
	private double raio;

	public Circulo(double raio) {
		this.raio = raio;
	}

	public double calculaPerimetro() {
		return (2 * Math.PI * raio);
	}

	public double calculaArea() {
		return (Math.PI * Math.pow(raio, 2));
	}

	public double getRaio() {
		return raio;
	}
}
