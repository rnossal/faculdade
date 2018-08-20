import java.util.ArrayList;

/**
 * Created by Rafael Nossal on 13/06/2017.
 */
public class Restaurante {
	private ArrayList<Mesa> mesas;
	private double faturamento;

	public Restaurante() {
		mesas = new ArrayList<>();
	}

	public ArrayList<Mesa> getMesas() {
		return mesas;
	}

	public void setMesas(ArrayList<Mesa> mesas) {
		this.mesas = mesas;
	}

	public double getFaturamento() {
		return faturamento;
	}

	public void setFaturamento(double faturamento) {
		this.faturamento = faturamento;
	}

	public void addMesa(Mesa mesaAdd) {
		for (Mesa mesa : mesas) {
			if (mesa.getNumero() == mesaAdd.getNumero()) {
				System.out.println("Já existe uma mesa com esse número.");
				return;
			}
		}

		mesas.add(mesaAdd);
	}

	public void removeMesa(int numMesa) {
		int index = -1;

		for (int i = 0; i < mesas.size(); i++) {
			if (mesas.get(i).getNumero() == numMesa) {
				index = i;
				break;
			}
		}

		if (index != -1) {
			if (mesas.get(index).getCliente() != null)
				encerraMesa(mesas.get(index).getNumero());

			mesas.remove(index);
		} else {
			System.out.println("Não existe uma mesa com esse número.");
		}
	}

	public void listarMesas() {
		if (mesas.size() > 0) {
			for (int i = 0; i < mesas.size(); i++) {
				String cliente = mesas.get(i).getCliente();
				ArrayList<Pedido> pedidos = mesas.get(i).getPedido();

				System.out.println("Número: " + mesas.get(i).getNumero());
				System.out.println(cliente == null ? "Livre" : "Cliente: " + cliente);

				if (cliente != null) {
					if (pedidos.size() != 0) {
						System.out.println("Pedido" + (pedidos.size() > 1 ? "s:" : ":"));
						for (int j = 0; j < pedidos.size(); j++) {
							System.out.println("\tNome: " + pedidos.get(j).getNome());
							System.out.println("\tValor: " + pedidos.get(j).getValor());

							if (j != (pedidos.size() - 1))
								System.out.println("--------------------");
						}
					} else {
						System.out.println("Sem pedidos.");
					}
				}

				if (i != (mesas.size() - 1))
					System.out.println("--------------------");
			}
		} else {
			System.out.println("Não existem mesas cadastradas.");
		}
	}

	public void addCliente(int numMesa, String cliente) {
		boolean found = false;

		for (Mesa mesa : mesas) {
			if (mesa.getNumero() == numMesa) {
				found = true;

				if (mesa.getCliente() == null) {
					mesa.setCliente(cliente);
				} else {
					System.out.println("Já existe um cliente nessa mesa.");
					return;
				}

				break;
			}
		}

		if (!found)
			System.out.println("Nenhuma mesa com esse número foi encontrada.");
	}

	public void encerraMesa(int numMesa) {
		boolean found = false;

		for (Mesa mesa : mesas) {
			if (mesa.getNumero() == numMesa) {
				found = true;

				if (mesa.getCliente() == null) {
					System.out.println("Não existe cliente na mesa para ser encerrada.");
					return;
				}

				mesa.setCliente(null);

				for (Pedido pedido : mesa.getPedido()) {
					faturamento += pedido.getValor();
				}

				mesa.setPedido(new ArrayList<>());

				break;
			}
		}

		if (!found)
			System.out.println("Nenhuma mesa com esse número foi encontrada.");
	}

	public void addPedidoMesa(int numMesa, Pedido pedido) {
		boolean found = false;

		for (Mesa mesa : mesas) {
			if (mesa.getNumero() == numMesa) {
				found = true;

				if (mesa.getCliente() != null) {
					mesa.addPedido(pedido);
				} else {
					System.out.println("Não existe cliente nessa mesa para um pedido ser adicionado.");
				}

				break;
			}
		}

		if (!found)
			System.out.println("Nenhuma mesa com esse número foi encontrada.");
	}
}
