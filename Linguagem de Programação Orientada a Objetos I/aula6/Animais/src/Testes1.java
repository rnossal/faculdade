/**
 * Created by Rafael Nossal on 11/04/2017.
 */
public class Testes1 {
	public static void main(String[] args) {
		Mamifero camelo = new Mamifero("Camelo", 230, "Marrom", 18.05);
		camelo.listaDados();
		System.out.println("\n");
		Peixe tubarao = new Peixe("Tubarão", 123.123, 456.456);
		tubarao.listaDados();
		System.out.println("\n");
		Mamifero urso = new Mamifero("Urso-Canadense", 170, "Marrom", 13.88);
		urso.listaDados();
	}
}
