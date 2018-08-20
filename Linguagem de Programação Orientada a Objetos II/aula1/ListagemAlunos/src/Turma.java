import java.util.ArrayList;

public class Turma {
	private String nomeDisciplina;
	private int numero;
	private ArrayList<Aluno> alunos;

	public Turma() {
		alunos = new ArrayList<>();
	}

	public void adicionaAluno(Aluno aluno) {
		alunos.add(aluno);
	}

	public void listaAlunos() {
		System.out.println(nomeDisciplina + " - " + numero);

		for (Aluno aluno : alunos) {
			System.out.println(aluno.getNome() + " - " + aluno.getNumero());
		}
	}

	public String getNomeDisciplina() {
		return nomeDisciplina;
	}

	public void setNomeDisciplina(String nomeDisciplina) {
		this.nomeDisciplina = nomeDisciplina;
	}

	public int getNumero() {
		return numero;
	}

	public void setNumero(int numero) {
		this.numero = numero;
	}

	public ArrayList<Aluno> getAlunos() {
		return alunos;
	}

	public void setAlunos(ArrayList<Aluno> alunos) {
		this.alunos = alunos;
	}
}
