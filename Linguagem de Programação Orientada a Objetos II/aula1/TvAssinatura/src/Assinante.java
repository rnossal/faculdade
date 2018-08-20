public class Assinante {
	private String nome;
	private String CPF;
	private String endereco;
	private Pacote pacoteCanal;

	public Assinante(String nome, String CPF) {
		this.nome = nome;
		this.CPF = CPF;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getCPF() {
		return CPF;
	}

	public void setCPF(String CPF) {
		this.CPF = CPF;
	}

	public String getEndereco() {
		return endereco;
	}

	public void setEndereco(String endereco) {
		this.endereco = endereco;
	}

	public Pacote getPacoteCanal() {
		return pacoteCanal;
	}

	public void setPacoteCanal(Pacote pacoteCanal) {
		this.pacoteCanal = pacoteCanal;
	}
}
