public class Main {
	public static void main(String[] args) {
		EscreveLetra a = new EscreveLetra('A');
		EscreveLetra b = new EscreveLetra('B', a);
		EscreveLetra c = new EscreveLetra('C', b);

		a.start();
		b.start();
		c.start();
	}
}
