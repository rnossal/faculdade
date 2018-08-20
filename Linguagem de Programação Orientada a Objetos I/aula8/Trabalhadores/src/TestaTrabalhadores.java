/**
 * Created by Rafael Nossal on 09/05/2017.
 */

/*
Uma empresa necessita controlar os pagamentos dos seus funcionários. Para ajudar esta empresa, faça o seguinte:
	a) Crie uma classe chamada Trabalhador, com os atributos nome e salárioPorHora, bem como os métodos acessores destes atributos.
	b) Crie uma subclasse de Trabalhador chamada Horista, com o atributo quantidade de horas trabalhadas e os métodos acessores deste atributo.
	c) Crie outra subclasse de Trabalhador chamada Assalariado.
	d) Na classe Horista, crie um método chamado “calculaPagamento”, que multiplica a quantidade de horas trabalhadas pelo valor da hora e retorna o valor a ser pago.
	e) Na classe Assalariado, o método calculaPagamento deve multiplicar o valor da hora sempre por 250 e retornar o valor a ser pago.
	f) Suas classes devem funcionar com o código abaixo. Caso algo não esteja implementado, você deve complementar as classes criadas para que o código abaixo funcione. Além disso, informe o que será impresso em tela após a execução do programa.
 */

public class TestaTrabalhadores {
	public static void main(String[] args) {
		Horista horista1 = new Horista("Telmo", 100, 10);

		Assalariado assalariado1 = new Assalariado("Paulo", 100);

		double salarioHorista = horista1.calculaPagamento();

		double salarioAssalariado = assalariado1.calculaPagamento();

		assalariado1.setSalarioPorHora(130);

		System.out.println(salarioHorista);

		System.out.println(salarioAssalariado);
	}
}