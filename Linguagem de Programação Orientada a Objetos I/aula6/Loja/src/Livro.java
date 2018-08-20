/**
 * Created by Rafael Nossal on 13/04/2017.
 */
public class Livro extends Produto {
	private String autor;

	public Livro(String nome, double preco, String autor) {
		super(nome, preco);
		this.autor = autor;
	}

	public String getAutor() {
		return autor;
	}

	public void setAutor(String autor) {
		this.autor = autor;
	}

	@Override
	public String toString() {
		return super.toString() + "Autor: " + autor;
	}
}
