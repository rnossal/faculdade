/**
 * Created by Rafael Nossal on 29/03/2017.
 */
public class Tamagotchi {
	private String nome;
	private double fome;
	private double saude;
	private int idade;

	public Tamagotchi(String nome) {
		this.nome = nome;
		/*
		 * Levando em conta a criação um bichinho com 100% de saúde,
		 * 100% de fome (sem fome) e idade 0.
		 */
		fome = 100;
		saude = 100;
		idade = 0;
	}

	public double getHumor() {
		return (fome + saude) / 2; // Sem nenhuma regra específica para culcular humor, deixei como média.
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public double getFome() {
		return fome;
	}

	public void setFome(double fome) {
		this.fome = fome;
	}

	public double getSaude() {
		return saude;
	}

	public void setSaude(double saude) {
		this.saude = saude;
	}

	public int getIdade() {
		return idade;
	}

	public void setIdade(int idade) {
		this.idade = idade;
	}
}
