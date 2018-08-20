/**
 * Created by Rafael Nossal on 29/03/2017.
 */
public class Ponto {
	private double x;
	private double y;

	public Ponto(double x, double y) {
		this.x = x;
		this.y = y;
	}
	public Ponto() {}

	public void imprime() {
		System.out.println("X: " + x);
		System.out.println("Y: " + y);
	}

	public double getX() {
		return x;
	}

	public void setX(double x) {
		this.x = x;
	}

	public double getY() {
		return y;
	}

	public void setY(double y) {
		this.y = y;
	}
}
