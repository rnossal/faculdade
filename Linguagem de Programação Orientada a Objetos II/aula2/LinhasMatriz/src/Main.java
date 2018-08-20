public class Main {
	public static void main(String[] args) {
		int[][] matriz = {
			{1, 2, 3, 4},
			{2, 3, 4, 5},
			{3, 4, 5, 6},
			{4, 5, 6, 7}
		};

		CalculaLinha c1 = new CalculaLinha(matriz, 0);
		CalculaLinha c2 = new CalculaLinha(matriz, 1);
		CalculaLinha c3 = new CalculaLinha(matriz, 2);
		CalculaLinha c4 = new CalculaLinha(matriz, 3);

		c1.start();
		c2.start();
		c3.start();
		c4.start();

		try {
			c1.join();
			c2.join();
			c3.join();
			c4.join();
		} catch (InterruptedException ie) { }

		System.out.println(c1.getSoma());
		System.out.println(c2.getSoma());
		System.out.println(c3.getSoma());
		System.out.println(c4.getSoma());

		System.out.println(c1.getSoma() + c2.getSoma() + c3.getSoma() + c4.getSoma());
	}
}
