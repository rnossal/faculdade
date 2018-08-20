import java.util.ArrayList;

public class Main {
	public static ArrayList<Lebre> chegada = new ArrayList<>();

	public static void main(String[] args) {
		Lebre l1 = new Lebre("Lebre 1");
		Lebre l2 = new Lebre("Lebre 2");
		Lebre l3 = new Lebre("Lebre 3");
		Lebre l4 = new Lebre("Lebre 4");
		Lebre l5 = new Lebre("Lebre 5");

		l1.start();
		l2.start();
		l3.start();
		l4.start();
		l5.start();

		try {
			l1.join();
			l2.join();
			l3.join();
			l4.join();
			l5.join();
		} catch (InterruptedException e) {}

		System.out.println("\nA lebre " + chegada.get(0).getName() + " é a vencedora com " + chegada.get(0).getSaltos() + " saltos!");
		System.out.println("Ordem de chegada: ");
		for (int i = 0; i < chegada.size(); i++) {
			System.out.println("\t" + (i + 1) + "º lugar - " + chegada.get(i).getName() + " com " + chegada.get(i).getSaltos() + " saltos.");
		}
	}
}
