/**
 * Created by Rafael Nossal on 09/05/2017.
 */
public class MatrizQuadrada extends Matriz {
	public MatrizQuadrada(int ordem) {
		super(ordem, ordem);
	}

	public int somaDiagonalPrincipal() {
		int soma = 0;

		for (int i = 0; i < matriz.length; i++) {
			soma += matriz[i][i];
		}

		return soma;
	}

	public int produtoDiagonalSeguncaria() {
		int produto = 1;

		for (int i = 0; i < matriz.length; i++) {
			produto *= matriz[i][matriz.length - i - 1];
		}

		return produto;
	}

	public int somaDemaisValores() {
		int soma = 0;

		for (int i = 0; i < matriz.length; i++) {
			for (int j = 0; j < matriz[i].length; j++) {
				if ((i != j) && ((i + j) != matriz.length - 1)) {
					soma += matriz[i][j];
				}
			}
		}

		return soma;
	}
}
