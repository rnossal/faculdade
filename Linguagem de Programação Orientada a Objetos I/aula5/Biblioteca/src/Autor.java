/**
 * Created by Rafael Nossal on 05/04/2017.
 */
public class Autor {
	private String nome;
	private int registro;

	public Autor(){ }
	public Autor(String nome, int registro){
		this.nome = nome;
		this.registro = registro;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public int getRegistro() {
		return registro;
	}

	public void setRegistro(int registro) {
		this.registro = registro;
	}
}
