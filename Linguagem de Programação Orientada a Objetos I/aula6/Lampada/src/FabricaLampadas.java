/**
 * Created by rnossal on 16/04/17.
 */
public class FabricaLampadas {
	public Lampada criaLampada(char tipo) {
		if (tipo == 'F' || tipo == 'f') {
			return new Fluorescente();
		} else if (tipo == 'L' || tipo == 'l') {
			return new LED();
		} else {
			return null;
		}
	}
}
