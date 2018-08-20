/**
 * Created by Rafael Nossal on 05/04/2017.
 */
public class Main {
	public static void main(String[] args) {
		Autor autor1 = new Autor("qwe", 1);
		Autor autor2 = new Autor("asd", 2);

		Livro livro1 = new Livro("aaaaa", autor1, "aaa111");
		Livro livro2 = new Livro("bbbbb", autor2, "bbb222");
		Livro livro3 = new Livro("ccccc", autor1, "ccc333");

		Usuario usuario1 = new Usuario("!@#", 0);
		Usuario usuario2 = new Usuario("$%¨", 1);

		System.out.println("Livro: " + livro1.getTitulo());
		System.out.println(livro1.estaEmprestado());
		if (livro1.emprestadoParaQuem() != null) {
			System.out.println(livro1.emprestadoParaQuem().getNome());
			System.out.println(livro1.emprestadoParaQuem().getRegistro());
		}

		livro1.setUsuarioAluguel(usuario1);
		livro2.setUsuarioAluguel(usuario2);

		System.out.println("Livro: " + livro1.getTitulo());
		System.out.println(livro1.estaEmprestado());
		if (livro1.emprestadoParaQuem() != null) {
			System.out.println(livro1.emprestadoParaQuem().getNome());
			System.out.println(livro1.emprestadoParaQuem().getRegistro());
		}
		System.out.println("Livro: " + livro2.getTitulo());
		System.out.println(livro2.estaEmprestado());
		if (livro2.emprestadoParaQuem() != null) {
			System.out.println(livro2.emprestadoParaQuem().getNome());
			System.out.println(livro2.emprestadoParaQuem().getRegistro());
		}
		System.out.println("Livro: " + livro3.getTitulo());
		System.out.println(livro3.estaEmprestado());
		if (livro3.emprestadoParaQuem() != null) {
			System.out.println(livro3.emprestadoParaQuem().getNome());
			System.out.println(livro3.emprestadoParaQuem().getRegistro());
		}
	}
}
