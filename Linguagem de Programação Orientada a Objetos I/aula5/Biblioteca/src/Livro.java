/**
 * Created by Rafael Nossal on 05/04/2017.
 */
public class Livro {
	private String titulo;
	private Autor autor;
	private String ISBN;
	private Usuario usuarioAluguel;

	public Livro() { }
	public Livro(String titulo, Autor autor, String ISBN) {
		this.titulo = titulo;
		this.autor = autor;
		this.ISBN = ISBN;
	}

	public boolean estaEmprestado() {
		return usuarioAluguel != null;
	}

	public Usuario emprestadoParaQuem() {
		return usuarioAluguel;
	}

	public String getTitulo() {
		return titulo;
	}

	public void setTitulo(String titulo) {
		this.titulo = titulo;
	}

	public Autor getAutor() {
		return autor;
	}

	public void setAutor(Autor autor) {
		this.autor = autor;
	}

	public String getISBN() {
		return ISBN;
	}

	public void setISBN(String ISBN) {
		this.ISBN = ISBN;
	}

	public Usuario getUsuarioAluguel() {
		return usuarioAluguel;
	}

	public void setUsuarioAluguel(Usuario usuarioAluguel) {
		this.usuarioAluguel = usuarioAluguel;
	}
}
