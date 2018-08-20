/**
 * Created by Rafael Nossal on 20/06/2017.
 */
public class Titulo implements Comparable{
	private int ano;
	private String descricao;

	public Titulo(int ano, String descricao) {
		this.ano = ano;
		this.descricao = descricao;
	}

	public Titulo() {}

	public int getAno() {
		return ano;
	}

	public void setAno(int ano) {
		this.ano = ano;
	}

	public String getDescricao() {
		return descricao;
	}

	public void setDescricao(String descricao) {
		this.descricao = descricao;
	}

	public int compareTo(Object o) {
		Titulo titulo = (Titulo)o;

		if (this.ano < titulo.getAno()) {
			return -1;
		} else if (this.ano > titulo.getAno()) {
			return 1;
		}

		return 0;
	}
}
