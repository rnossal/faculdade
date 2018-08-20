/**
 * Created by Rafael Nossal on 20/06/2017.
 */
public class Jogador {
	private String matricula;
	private String nome;
	private double salarioBase;
	private String posicao;
	private double valorBonificacao;
	private double valorGratificacao;
	private double peso;
	private double altura;

	public Jogador(String matricula, String nome, double salarioBase, String posicao, double valorBonificacao, double valorGratificacao, double peso, double altura) {
		this.matricula = matricula;
		this.nome = nome;
		this.salarioBase = salarioBase;
		this.posicao = posicao;
		this.valorBonificacao = valorBonificacao;
		this.valorGratificacao = valorGratificacao;
		this.peso = peso;
		this.altura = altura;
	}

	public Jogador() {}

	public double calculaSalario() {
		return (salarioBase * 2) + valorBonificacao + valorGratificacao;
	}

	public double calculaImc() {
		return peso / (altura * altura);
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

	public String getPosicao() {
		return posicao;
	}

	public void setPosicao(String posicao) {
		this.posicao = posicao;
	}

	public double getValorBonificacao() {
		return valorBonificacao;
	}

	public void setValorBonificacao(double valorBonificacao) {
		this.valorBonificacao = valorBonificacao;
	}

	public double getValorGratificacao() {
		return valorGratificacao;
	}

	public void setValorGratificacao(double valorGratificacao) {
		this.valorGratificacao = valorGratificacao;
	}

	public double getPeso() {
		return peso;
	}

	public void setPeso(double peso) {
		this.peso = peso;
	}

	public double getAltura() {
		return altura;
	}

	public void setAltura(double altura) {
		this.altura = altura;
	}
}
