public class Main {
	public static void main(String[] args) {
		LancaHora lh = new LancaHora();
		GeraNoticias gn = new GeraNoticias();

		lh.start();
		gn.start();

		try {
			lh.join();

			System.exit(0);
		} catch (InterruptedException ie) { }
	}
}
