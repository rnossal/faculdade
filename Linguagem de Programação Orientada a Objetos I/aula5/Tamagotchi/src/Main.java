/**
 * Created by Rafael Nossal on 29/03/2017.
 */
public class Main {
	public static void main(String[] args) {
		Tamagotchi tama = new Tamagotchi("Jubileu");

		tama.setFome(70);
		tama.setIdade(1);
		tama.setSaude(98.7);

		System.out.println("Nome: " + tama.getNome());
		System.out.println("Idade: " + tama.getIdade());
		System.out.println("Fome: " + tama.getFome());
		System.out.println("Saúde: " + tama.getSaude());
		System.out.println("Humor: " + tama.getHumor());
	}
}
