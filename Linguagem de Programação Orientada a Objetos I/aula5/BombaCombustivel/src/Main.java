/**
 * Created by Rafael Nossal on 29/03/2017.
 */
public class Main {
	public static void main(String[] args) {
		BombaCombustivel bomba = new BombaCombustivel();

		bomba.setTipoDeCombustivel("Gasolina Comum");
		bomba.setValorPorLitro(3.41);
		bomba.setQuantidadeDeCombustivel(1000);

		System.out.print("Testes para a bomba com: " + bomba.getTipoDeCombustivel());
		System.out.print(" com " + bomba.getQuantidadeDeCombustivel() +  "L de combustível");
		System.out.println(" à R$" + bomba.getValorPorLitro() +  " em valor por litro.\n");

		// Testes de abastecimento por valor:
		System.out.println("Abestecendo R$50: " + bomba.abastecerPorValor(50));
		System.out.println("Quantidade de combustível agora: " + bomba.getQuantidadeDeCombustivel() + "\n");

		System.out.println("Abestecendo R$3,50: " + bomba.abastecerPorValor(3.50));
		System.out.println("Quantidade de combustível agora: " + bomba.getQuantidadeDeCombustivel() + "\n");

		System.out.println("Abestecendo R$-10: " + bomba.abastecerPorValor(-10));
		System.out.println("Quantidade de combustível agora: " + bomba.getQuantidadeDeCombustivel() + "\n");

		System.out.println("Abestecendo R$10.000: " + bomba.abastecerPorValor(10000));
		System.out.println("Quantidade de combustível agora: " + bomba.getQuantidadeDeCombustivel() + "\n");

		// Testes de abastecimento por litros:
		System.out.println("Abestecendo 30L: " + bomba.abastecerPorLitro(30));
		System.out.println("Quantidade de combustível agora: " + bomba.getQuantidadeDeCombustivel() + "\n");

		System.out.println("Abestecendo 1L: " + bomba.abastecerPorLitro(1));
		System.out.println("Quantidade de combustível agora: " + bomba.getQuantidadeDeCombustivel() + "\n");

		System.out.println("Abestecendo 7.5L: " + bomba.abastecerPorLitro(7.5));
		System.out.println("Quantidade de combustível agora: " + bomba.getQuantidadeDeCombustivel() + "\n");

		System.out.println("Abestecendo -100: " + bomba.abastecerPorLitro(-100));
		System.out.println("Quantidade de combustível agora: " + bomba.getQuantidadeDeCombustivel() + "\n");

		System.out.println("Abestecendo 1.000L: " + bomba.abastecerPorLitro(1000));
		System.out.println("Quantidade de combustível agora: " + bomba.getQuantidadeDeCombustivel());
	}
}
