import java.util.ArrayList;

/**
 * Created by Rafael Nossal on 07/06/2017.
 */
public class Turma {
	private String nomeDisciplina;
	private int numero;
	private ArrayList<Aluno> listaAlunos;

	public Turma() {
		listaAlunos = new ArrayList<>();
	}

	public void adicionaAluno(Aluno al) {
		listaAlunos.add(al);
	}

	public void listaAlunos() {
		System.out.println(nomeDisciplina  + " - " + numero);
		for (Aluno aluno : listaAlunos) {
			System.out.println(aluno.getNomeAluno() + " - " + aluno.getNumero());
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

	public ArrayList<Aluno> getListaAlunos() {
		return listaAlunos;
	}

	public void setListaAlunos(ArrayList<Aluno> listaAlunos) {
		this.listaAlunos = listaAlunos;
	}
}
