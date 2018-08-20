/**
 * Created by Rafael Nossal on 31/05/2017.
 */
public class Retangulo extends Quadrilatero implements FiguraGeometrica {
	public Retangulo(double base, double altura) {
		super(base, altura, base, altura);
	}

	public double calculaPerimetro() {
		return super.calculaPerimetro();
	}

	public double calculaArea() {
		return lado1 * lado2;
	}
}
