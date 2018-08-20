/**
 * Created by Rafael Nossal on 31/05/2017.
 */
public class Quadrado extends Quadrilatero implements FiguraGeometrica {
	public Quadrado(double lado) {
		super(lado, lado, lado, lado);
	}

	public double calculaPerimetro() {
		return super.calculaPerimetro();
	}

	public double calculaArea() {
		return lado1 * lado2;
	}

	public double asdasdasd() {
		return lado1 * lado2;
	}
}
