import java.util.ArrayList;
import java.util.TreeSet;

/**
 * Created by Rafael Nossal on 20/06/2017.
 */
public class Main {
	public static void main(String[] args) {
		Tecnico tecnico = new Tecnico("123456789", "Renato Portaluppi", 15000, 1);

		Titulo titulo1 = new Titulo(2001, "Copa do Brasil");
		Titulo titulo2 = new Titulo(2005, "Campeonato Brasileiro - Série B");
		Titulo titulo3 = new Titulo(2006, "Campeonato Gaúcho");
		Titulo titulo4 = new Titulo(2007, "Campeonato Gaúcho");
		Titulo titulo5 = new Titulo(2010, "Campeonato Gaúcho");

		Jogador jogador1 = new Jogador("0001", "Marcelo Grohe", 10000, "Goleiro", 5000, 2500, 90, 1.80);
		Jogador jogador2 = new Jogador("0002", "Luan", 15000, "Atacante", 7000, 5000, 85, 1.70);

		Time time = new Time("Grêmio Foot-Baal Portoalegrense");
		time.setTecnico(tecnico);
		time.setTitulos(new TreeSet<Titulo>() {{
			add(titulo1);
			add(titulo2);
			add(titulo3);
			add(titulo4);
			add(titulo5);
		}});
		time.setJogadores(new ArrayList<Jogador>(){{
			add(jogador1);
			add(jogador2);
		}});

		time.exibeRelatorioCadastral();
	}
}
