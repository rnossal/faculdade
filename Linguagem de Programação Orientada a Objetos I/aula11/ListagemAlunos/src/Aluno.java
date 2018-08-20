/**
 * Created by Rafael Nossal on 07/06/2017.
 */
public class Aluno {
	private String nomeAluno;
	private int numero;

	public Aluno() { }
	public Aluno(String nomeAluno, int numero) {
		this.nomeAluno = nomeAluno;
		this.numero = numero;
	}

	public String getNomeAluno() {
		return nomeAluno;
	}

	public void setNomeAluno(String nomeAluno) {
		this.nomeAluno = nomeAluno;
	}

	public int getNumero() {
		return numero;
	}

	public void setNumero(int numero) {
		this.numero = numero;
	}
}
