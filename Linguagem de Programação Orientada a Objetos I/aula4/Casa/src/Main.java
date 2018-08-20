/**
 * Created by Rafael Nossal on 23/03/2017.
 */
public class Main {
	public static void main(String[] args) {
		Casa casa = new Casa();

		Porta porta1 = new Porta();
		Porta porta2 = new Porta();

		casa.pinta("Verde");

		System.out.println(casa.getCor());
		System.out.println(casa.quantasPortasEstaoAbertas());
		System.out.println(casa.totalDePortasInstaladas());

		casa.setPorta1(porta1);
		casa.setPorta3(porta2);

		casa.getPorta1().abre();

		System.out.println(casa.quantasPortasEstaoAbertas());
		System.out.println(casa.totalDePortasInstaladas());
	}
}
