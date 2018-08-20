import java.util.ArrayList;

public class GeraNoticias extends Thread {
	ArrayList<String> noticias = new ArrayList<String>(){{
		add("Americano é preso após roubar banco, fazer strip e jogar dinheiro pela rua");
		add("Americano é flagrado dirigindo a 180 km/h para fazer foto para o Snapchat");
		add("Bombeiros resgatam homem que caiu no lixo ao buscar celular perdido nos EUA");
		add("Cachorrinha é filmada andando a cavalo no Texas");
		add("Polícia americana 'prende' patos que estavam 'vadiando'");
		add("Malásia quebra recorde de multidão fantasiada de gatos");
		add("Homem intrigado com conta da água descobre que gato aprendeu a dar descarga");
		add("Polícia está à procura de 'ladrão de ovos' em zona rural dos EUA");
		add("Homem atira em tatu, bala ricocheteia e atinge atirador no rosto");
		add("Cachorro é flagrado 'dirigindo' caminhão nos EUA");
	}};

	@Override
	public void run() {
		while (true) {
			for (String noticia : noticias) {
				try {
					sleep(5000);
				} catch (InterruptedException ie) {}

				System.out.println(noticia);
			}
		}
	}
}
