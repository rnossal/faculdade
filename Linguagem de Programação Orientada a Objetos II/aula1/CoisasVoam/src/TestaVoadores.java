public class TestaVoadores {
	public static void main(String[] args) {
		Voador passarinho = new Voador();
		Aviao airbus = new Aviao();
		Superman heroi = new Superman();

		passarinho.decolar();
		passarinho.voar(100);
		passarinho.pousar();

		airbus.quantidadePassageiros = 30;
		airbus.setMetrosVoados(1000);

		heroi.disfarcar();
		if (heroi.estahDisfarcado()){
			System.out.println("O Heroi esta disfarcado? ");
		} else {
			System.out.println("O Heroi nao esta disfarcado.");
		}

		heroi.voar(1000);

		System.out.println("Metros voados pelo passarinho: " + passarinho.getMetrosVoados());
		System.out.println("Metros voados pelo Airbus: " + airbus.getMetrosVoados());
		System.out.println("Metros voados pelo Superman: " + heroi.getMetrosVoados());
	}
}