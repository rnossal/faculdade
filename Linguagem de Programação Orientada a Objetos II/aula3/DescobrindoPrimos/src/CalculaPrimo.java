import java.util.concurrent.ConcurrentSkipListMap;

public class CalculaPrimo extends Thread {
	private int inicio;
	private int fim;
	ConcurrentSkipListMap <Integer, String> primos;

	public CalculaPrimo(int inicio, int fim, ConcurrentSkipListMap <Integer, String> primos) {
		this.inicio = inicio;
		this.fim = fim;
		this.primos = primos;
	}

	@Override
	public void run() {
		for (int i = inicio; i <= fim; i++) {
			if (ehPrimo(i)) {
				primos.put(i, getName());
			}
		}
	}

	private boolean ehPrimo(int num) {
		if((num > 2 && num % 2 == 0) || num == 1 || num == 0)
			return false;

		for (int i = 3; i <= (int)Math.sqrt(num); i += 2)
			if (num % i == 0)
				return false;

		return true;
	}
}
