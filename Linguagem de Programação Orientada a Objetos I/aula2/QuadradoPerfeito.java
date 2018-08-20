/**
 * Created by rnossal on 07/03/17.
 */
public class QuadradoPerfeito {
	public static void main(String[] args) {
		int contador = 0;
		int numero = 1;

		while (contador < 10) {
			int soma = 0;
			int termos = 0;

			for (int i = 1; soma < numero; i++) {
				if (i % 2 != 0) {
					soma += i;
					termos++;
				}
			}

			if (soma == numero && numero == (termos * termos)) {
				System.out.println(numero);
				contador++;
			}
			numero++;
		}
	}
}
