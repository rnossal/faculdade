import java.util.ArrayList;

public class Pacote {
	private String nomePacote;

	private ArrayList<Canal> canais;

	public Pacote() {
		canais = new ArrayList<>();
	}
	public Pacote(String nomePacote) {
		this.nomePacote = nomePacote;
		canais = new ArrayList<>();
	}

	public void adicionaCanal(Canal canal) throws ChannelAlreadyAddedException {
		for (Canal canalAdicionado : canais) {
			if (canalAdicionado.getNumeroCanal() == canal.getNumeroCanal())
				throw new ChannelAlreadyAddedException();
		}

		canais.add(canal);
	}

	public void listaDadosPacote() {
		System.out.println(nomePacote);
		for (Canal canal : canais) {
			System.out.println("\t" + canal.getNomeCanal() + " - " + canal.getNumeroCanal());
		}
	}

	public String getNomePacote() {
		return nomePacote;
	}

	public void setNomePacote(String nomePacote) {
		this.nomePacote = nomePacote;
	}
}
