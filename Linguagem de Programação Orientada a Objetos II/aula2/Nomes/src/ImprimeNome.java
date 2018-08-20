public class ImprimeNome extends Thread {
	private String nome;

	public ImprimeNome(String nome) {
		this.nome = nome;
	}

	@Override
	public void run() {
		System.out.println(nome);
	}
}
