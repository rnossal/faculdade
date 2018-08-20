/**
 * Created by rnossal on 16/04/17.
 */
public class LED extends Lampada {
	@Override
	public void mostraEstado() {
		System.out.print("Estado da lâmpada LED: \n\t");
		super.mostraEstado();
	}
}
