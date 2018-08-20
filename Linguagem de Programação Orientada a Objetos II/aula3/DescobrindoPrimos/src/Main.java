import java.util.ArrayList;
import java.util.concurrent.ConcurrentSkipListMap;

public class Main {
	public static void main(String[] args) {
		ArrayList<CalculaPrimo> prms = new ArrayList<>();
		ConcurrentSkipListMap<Integer, String> primos = new ConcurrentSkipListMap<>();

		for (int i = 1; i <= (1 + 99999) / 1000; i++) {
			CalculaPrimo prm = new CalculaPrimo(((i * 1000) - 1000), ((i * 1000) - 1), primos);
			prm.start();
			prms.add(prm);
		}

		for (CalculaPrimo prm : prms) {
			try {
				prm.join();
			} catch (InterruptedException e) {}
		}

		for (Integer num : primos.keySet()) {
			System.out.println(num + " - " + primos.get(num));
		}
	}
}
