/**
 * Created by Rafael Nossal on 20/06/2017.
 */
public class Tecnico {
	private String matricula;
	private String nome;
	private double salarioBase;
	private int titulos;

	public Tecnico(String matricula, String nome, double salarioBase, int titulos) {
		this.matricula = matricula;
		this.nome = nome;
		this.salarioBase = salarioBase;
		this.titulos = titulos;
	}

	public Tecnico() {}

	public double calculaSalario() {
		return (salarioBase * 2) + (titulos * 250);
	}

	public String getMatricula() {
		return matricula;
	}

	public void setMatricula(String matricula) {
		this.matricula = matricula;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public double getSalarioBase() {
		return salarioBase;
	}

	public void setSalarioBase(double salarioBase) {
		this.salarioBase = salarioBase;
	}

	public int getTitulos() {
		return titulos;
	}

	public void setTitulos(int titulos) {
		this.titulos = titulos;
	}
}
