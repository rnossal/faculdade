public class Preenchedor extends Thread {
	Vetor v;

	public Preenchedor(Vetor v) {
		this.v = v;
	}

	@Override
	public void run() {
		while (v.getIndex() + 1 < v.getVetor().length) {
			v.setIndex(v.getIndex() + 1);

			v.getVetor()[v.getIndex()] = v.getIndex();
		}
	}
}
