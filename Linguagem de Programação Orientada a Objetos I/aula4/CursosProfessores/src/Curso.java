/**
 * Created by Rafael Nossal on 23/03/2017.
 */
public class Curso {
	private int numero;
	private String nome;
	private Professor professor;

	public void exibeDados() {
		System.out.println("Número: " + numero);
		System.out.println("Nome: " + nome);
		if (professor != null) {
			System.out.println("Professor: " + professor.getNome());
		}
	}
	public int getNumero() {
		return numero;
	}

	public void setNumero(int numero) {
		this.numero = numero;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public Professor getProfessor() {
		return professor;
	}

	public void setProfessor(Professor professor) {
		this.professor = professor;
	}
}
