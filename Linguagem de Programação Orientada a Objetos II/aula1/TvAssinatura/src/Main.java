public class Main {
	public static void main(String[] args) {
		Assinante ass1 = new Assinante("Domingos", "123456");
		Assinante ass2 = new Assinante("Rodrigo", "123457");

		Canal can1 = new Canal();
		Canal can2 = new Canal();
		Canal can3 = new Canal();

		can1.setNumeroCanal(13);
		can1.setNomeCanal("RBS");
		can2.setNumeroCanal(97);
		can2.setNomeCanal("Disney Channel");
		can3.setNumeroCanal(39);
		can3.setNomeCanal("SporTV");

		Pacote pac1 = new Pacote();
		Pacote pac2 = new Pacote();

		pac1.setNomePacote("Infantil");
		pac2.setNomePacote("Esportes");

		try {
			pac1.adicionaCanal(can1);
			pac1.adicionaCanal(can2);
			pac2.adicionaCanal(can1);
			pac2.adicionaCanal(can3);
		} catch (ChannelAlreadyAddedException caee){
			System.out.println(caee.getMessage());
		}

		ass1.setPacoteCanal(pac1);
		ass2.setPacoteCanal(pac2);

		pac1.listaDadosPacote();
		pac2.listaDadosPacote();
	}
}