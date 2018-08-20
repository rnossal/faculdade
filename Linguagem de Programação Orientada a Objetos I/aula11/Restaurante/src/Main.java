import java.util.Scanner;

/**
 * Created by Rafael Nossal on 13/06/2017.
 */
public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		Restaurante restaurante = new Restaurante();

		boolean ct = true;
		while (ct) {
			System.out.println("Opções:");
			System.out.println("\t0 - Sair.");
			System.out.println("\t1 - Criar mesa.");
			System.out.println("\t2 - Remover mesa.");
			System.out.println("\t3 - Alocar cliente numa mesa.");
			System.out.println("\t4 - Registrar pedido na mesa.");
			System.out.println("\t5 - Encerrar pedidos da mesa.");
			System.out.println("\t6 - Verificar faturamento do restaurante.");
			System.out.println("\t7 - Listar mesas.");

			int numMesa;
			String cliente;
			String nomePedido;
			double valor;

			switch (scan.nextInt()) {
				case 0:
					ct = false;
					break;
				case 1:
					System.out.print("Digite o número da mesa: ");
					numMesa = scan.nextInt();
					restaurante.addMesa(new Mesa(numMesa));
					break;
				case 2:
					System.out.print("Digite o número da mesa: ");
					numMesa = scan.nextInt();
					restaurante.removeMesa(numMesa);
					break;
				case 3:
					System.out.print("Digite o número da mesa: ");
					numMesa = scan.nextInt();
					scan = new Scanner(System.in);
					System.out.print("Digite o nome do cliente: ");
					cliente = scan.nextLine();
					restaurante.addCliente(numMesa, cliente);
					break;
				case 4:
					System.out.print("Digite o número da mesa: ");
					numMesa = scan.nextInt();
					scan = new Scanner(System.in);
					System.out.print("Digite o nome do pedido: ");
					nomePedido = scan.nextLine();
					System.out.print("Digite o valor do pedido: ");
					valor = scan.nextDouble();
					restaurante.addPedidoMesa(numMesa, new Pedido(nomePedido, valor));
					break;
				case 5:
					System.out.print("Digite o número da mesa: ");
					numMesa = scan.nextInt();
					restaurante.encerraMesa(numMesa);
					break;
				case 6:
					System.out.println("Faturamento: " + restaurante.getFaturamento());
					break;
				case 7:
					restaurante.listarMesas();
					break;
				default:
					System.out.println("Opção inválida. Tente novamente digitando um dos números listados:");
			}
		}
	}
}
