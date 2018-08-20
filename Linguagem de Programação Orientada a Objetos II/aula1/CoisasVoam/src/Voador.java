public class Voador {
	private int metrosVoados;
	private boolean	 voando;

	public void decolar() {
		voando = true;
	}

	public void pousar() {
		voando = false;
	}

	public void voar(int metros) {
		metrosVoados += metros;
	}

	public int getMetrosVoados() {
		return metrosVoados;
	}

	public void setMetrosVoados(int metrosVoados) {
		this.metrosVoados = metrosVoados;
	}

	public boolean isVoando() {
		return voando;
	}

	public void setVoando(boolean voando) {
		this.voando = voando;
	}
}
