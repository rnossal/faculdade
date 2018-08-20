/**
 * Created by Rafael Nossal on 09/05/2017.
 */
public class Matriz {
	protected int[][] matriz;

	public Matriz(int linhas, int colunas) {
		matriz = new int[linhas][colunas];
	}

	public int[][] getMatriz() {
		return matriz;
	}

	public void setMatriz(int[][] matriz) {
		this.matriz = matriz;
	}
}
