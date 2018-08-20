/**
 * Created by rnossal on 16/04/17.
 */
public class Fluorescente extends Lampada {
	@Override
	public void mostraEstado() {
		System.out.print("Estado da lâmpada fluorescente: \n\t");
		super.mostraEstado();
	}
}
