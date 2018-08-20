public class Main {
	public static void main(String[] args) {
		Vetor v = new Vetor();

		Preenchedor p1 = new Preenchedor(v);
		Preenchedor p2 = new Preenchedor(v);

		p1.start();
		p2.start();

		try {
			p1.join();
			p2.join();
		} catch (InterruptedException e) {}

		for (int i : v.getVetor()) {
			System.out.println(i);
		}
	}
}
