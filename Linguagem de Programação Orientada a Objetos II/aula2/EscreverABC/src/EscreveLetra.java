public class EscreveLetra extends Thread {
	char letra;
	EscreveLetra esperaretra;

	public EscreveLetra(char letra) {
		this.letra = letra;
	}

	public EscreveLetra(char letra, EscreveLetra esperarLetra) {
		this.letra = letra;
		this.esperaretra = esperarLetra;
	}

	@Override
	public void run() {
		if (esperaretra != null) {
			try {
				esperaretra.join();
			} catch (InterruptedException ie) { }
		}

		System.out.println(letra);
	}
}
