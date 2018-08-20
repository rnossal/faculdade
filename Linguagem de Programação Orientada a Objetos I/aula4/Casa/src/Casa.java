/**
 * Created by Rafael Nossal on 23/03/2017.
 */
public class Casa {
	private String cor;
	private Porta porta1;
	private Porta porta2;
	private Porta porta3;

	public void pinta(String cor) {
		this.cor = cor;
	}

	public String getCor() {
		return cor;
	}

	public int quantasPortasEstaoAbertas() {
		int qtd = 0;

		if (porta1 != null && porta1.estaAberta()) {
			qtd++;
		}
		if (porta2 != null && porta2.estaAberta()) {
			qtd++;
		}
		if (porta3 != null && porta3.estaAberta()) {
			qtd++;
		}

		return qtd;
	}
	public int totalDePortasInstaladas() {
		int qtd = 0;

		if (porta1 != null) {
			qtd++;
		}
		if (porta2 != null) {
			qtd++;
		}
		if (porta3 != null) {
			qtd++;
		}

		return  qtd;
	}

	public Porta getPorta1() {
		return porta1;
	}

	public void setPorta1(Porta porta1) {
		this.porta1 = porta1;
	}

	public Porta getPorta2() {
		return porta2;
	}

	public void setPorta2(Porta porta2) {
		this.porta2 = porta2;
	}

	public Porta getPorta3() {
		return porta3;
	}

	public void setPorta3(Porta porta3) {
		this.porta3 = porta3;
	}
}
