import java.util.ArrayList;

/**
 * Created by Rafael Nossal on 13/06/2017.
 */
public class Mesa {
	private int numero;
	private String cliente;
	private ArrayList<Pedido> pedido;

	public Mesa() {
		pedido = new ArrayList<>();
	}

	public Mesa(int numero) {
		this.numero = numero;
		pedido = new ArrayList<>();
	}

	public int getNumero() {
		return numero;
	}

	public void setNumero(int numero) {
		this.numero = numero;
	}

	public String getCliente() {
		return cliente;
	}

	public void setCliente(String cliente) {
		this.cliente = cliente;
	}

	public ArrayList<Pedido> getPedido() {
		return pedido;
	}

	public void setPedido(ArrayList<Pedido> pedido) {
		this.pedido = pedido;
	}

	public void addPedido(Pedido pedido) {
		this.pedido.add(pedido);
	}
}
