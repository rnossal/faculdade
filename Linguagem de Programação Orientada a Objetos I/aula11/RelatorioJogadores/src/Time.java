import java.text.DecimalFormatSymbols;
import java.util.ArrayList;
import java.util.Locale;
import java.util.TreeSet;
import java.text.DecimalFormat;

/**
 * Created by Rafael Nossal on 20/06/2017.
 */
public class Time implements IExibicao {
	private String nome;
	private ArrayList<Jogador> jogadores;
	private Tecnico tecnico;
	private TreeSet<Titulo> titulos;

	public Time(String nome) {
		this.nome = nome;
		jogadores = new ArrayList<>();
		titulos = new TreeSet<>();
	}

	public Time() {
		jogadores = new ArrayList<>();
		titulos = new TreeSet<>();
	}

	public void exibeRelatorioCadastral() {
		DecimalFormatSymbols dfs = new DecimalFormatSymbols (new Locale ("pt", "BR"));
		DecimalFormat dFormat = new DecimalFormat("#.00", dfs);

		System.out.println("Nome: " + nome);
		System.out.println("Jogadores");

		for (Jogador jogador : jogadores) {
			System.out.println("- " + jogador.getMatricula() + " - " + jogador.getNome() + " (" + jogador.getPosicao() + ")");
			System.out.println("... Salário = " + dFormat.format(jogador.calculaSalario()) + " (Salário Base: " + dFormat.format(jogador.getSalarioBase()) + "; Bonificação: " + jogador.getValorBonificacao() + "; Gratificação: " + dFormat.format(jogador.getValorGratificacao()) + ")");
			System.out.println("... IMC = " + dFormat.format(jogador.calculaImc()) + " (Peso: " + dFormat.format(jogador.getPeso()) + "; Altura: " + dFormat.format(jogador.getAltura()) + ")");
		}

		System.out.println("Técnico (" + tecnico.getMatricula() + " - " + tecnico.getNome() + ")");
		System.out.println("... Salário = " + dFormat.format(tecnico.calculaSalario()) + " (Salário Base: " + dFormat.format(tecnico.getSalarioBase()) + "; Títulos: " + tecnico.getTitulos() + ")");

		System.out.println("Títulos");
		for (Titulo titulo : titulos) {
			System.out.println("- " + titulo.getAno() + " : " + titulo.getDescricao());
		}
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public ArrayList<Jogador> getJogadores() {
		return jogadores;
	}

	public void setJogadores(ArrayList<Jogador> jogadores) {
		this.jogadores = jogadores;
	}

	public void addJogador(Jogador jogador) {
		jogadores.add(jogador);
	}

	public Tecnico getTecnico() {
		return tecnico;
	}

	public void setTecnico(Tecnico tecnico) {
		this.tecnico = tecnico;
	}

	public TreeSet<Titulo> getTitulos() {
		return titulos;
	}

	public void setTitulos(TreeSet<Titulo> titulos) {
		this.titulos = titulos;
	}

	public void addTitulo(Titulo titulo) {
		titulos.add(titulo);
	}
}
