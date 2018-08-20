import com.sun.deploy.util.ArrayUtil;

/**
 * Created by Rafael Nossal on 10/05/2017.
 */
public class Fruteira {
	private  Fruta[] frutas;

	public Fruteira(int qtdFrutas) {
		this.frutas = new Fruta[qtdFrutas];
	}

	public void adiciona(Fruta fruta) {
		int posicaoPossivel = -1;

		for (int i = 0; i < frutas.length; i++) {
			if (frutas[i] == fruta)
				break;

			if (posicaoPossivel == -1 && frutas[i] == null)
				posicaoPossivel = i;

			if (posicaoPossivel != -1 && i == (frutas.length - 1))
				frutas[posicaoPossivel] = fruta;
		}
	}

	public void remove(Fruta fruta) {
		for (int i = 0; i < frutas.length; i++) {
			if (frutas[i] == fruta) {
				frutas[i] = null;
				break;
			}
		}
	}

	public void listaFrutas() {
		int indiceFruta = 1;

		for (int i = 0; i < frutas.length; i++) {
			if (frutas[i] != null) {
				System.out.println(String.format("Fruta %d:\n\tGramas: %f\n\tCalorias por grama: %f",
						indiceFruta,
						frutas[i].getGramas(),
						frutas[i].getCaloriasPorGrama()));
				indiceFruta++;
			}
		}
	}
}
