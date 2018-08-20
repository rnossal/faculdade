import java.util.ArrayList;
import java.util.TreeMap;

/**
 * Created by Rafael Nossal on 21/06/2017.
 */
public class Usuario implements IExibido, ICalcula{
	private String nome;
	private String email;
	private String celular;
	private TreeMap<Integer, ArrayList<Gasto>> gastos;

	public Usuario(String nome, String email, String celular) {
		this.nome = nome;
		this.email = email;
		this.celular = celular;

		gastos = new TreeMap<>();
		for(int i = 1; i <= 12; i++) {
			gastos.put(i, new ArrayList<>());
		}
	}

	public void incluirGasto(Gasto gasto) {
		gastos.get(gasto.getMes()).add(gasto);
	}

	public void exibeRelatorio() {
		System.out.println("Nome: " + nome + " (" + email + " / " + celular + ")");

		System.out.println("Gastos do primeiro semestre = R$" + getTotalGastos(true));

		for (int key : gastos.keySet()) {
			if (key >= 1 && key <= 6) {
				ArrayList<Gasto> gastosMes = gastos.get(key);

				if (gastosMes.size() > 0) {
					System.out.println("- " + gastosMes.get(0).getMesNome() + " = R$" + getTotalMes(key));

					for (Gasto gasto : gastosMes) {
						System.out.println("--- " + gasto.getDescricao() + " - R$ " + gasto.getValor());
					}
				}
			}
		}
	}

	public double getTotalGastos(boolean primeiroSemestre) {
		double total = 0;

		for (int key : gastos.keySet()) {
			if (((key >= 1 && key <=6) && primeiroSemestre) || ((key >= 7 && key <= 12) && !primeiroSemestre)) {
				total += getTotalMes(key);
			}
		}

		return total;
	}

	public double getTotalMes(int mes) {
		double total = 0;
		ArrayList<Gasto> gastosMes = gastos.get(mes);

		for (Gasto gasto : gastosMes) {
			total += gasto.getValor();
		}

		return total;
	}
}
