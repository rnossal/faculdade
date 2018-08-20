public class CalculaLinha extends Thread {
	private int soma;
	private int[][] matriz;
	private int linha;

	public CalculaLinha(int[][] matriz, int linha) {
		this.matriz = matriz;
		this.linha = linha;
	}

	@Override
	public void run() {
		for (int val : matriz[linha])
			soma += val;
	}

	public int getSoma() {
		return soma;
	}
}
