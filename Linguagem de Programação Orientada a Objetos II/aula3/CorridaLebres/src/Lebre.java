import java.util.ArrayList;

public class Lebre extends Thread {
	int distanciaPercorrida;
	int saltos;

	public int getDistanciaPercorrida() {
		return distanciaPercorrida;
	}

	public void setDistanciaPercorrida(int distanciaPercorrida) {
		this.distanciaPercorrida = distanciaPercorrida;
	}

	public int getSaltos() {
		return saltos;
	}

	public void setSaltos(int saltos) {
		this.saltos = saltos;
	}

	public Lebre(String name) {
		super(name);
	}

	@Override
	public void run() {
		while (true) {
			int distancia = (int)((Math.random() * 3) + 1);
			distanciaPercorrida += distancia;
			saltos++;

			System.out.println(this.getName() + " pulou " + distancia + " metros");

			if (distanciaPercorrida >= 20) {
				Main.chegada.add(this);
				break;
			}

			yield();
		}
	}
}
