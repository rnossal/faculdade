/**
 * Created by Rafael Nossal on 26/06/2017.
 */
public class Main {
	public static void main(String[] args) {
		Usuario usuario = new Usuario("John Doe", "john.doe@gmail.com", "9876-5432");
		Gasto gasto11 = new Gasto("água", 1, 30);
		Gasto gasto12 = new Gasto("telefone", 1, 70);
		Gasto gasto21 = new Gasto("água", 2, 10);
		Gasto gasto22 = new Gasto("telefone", 2, 40);
		Gasto gasto31 = new Gasto("água", 3, 30);
		Gasto gasto32 = new Gasto("telefone", 3, 70);
		Gasto gasto33 = new Gasto("luz", 3, 100);
		Gasto gasto34 = new Gasto("celular novo", 3, 700);
		Gasto gasto41 = new Gasto("água", 4, 30);
		Gasto gasto42 = new Gasto("telefone", 4, 70);
		Gasto gasto43 = new Gasto("luz", 4, 100);
		Gasto gasto44 = new Gasto("refeição", 4, 100);
		Gasto gasto51 = new Gasto("água", 5, 30);
		Gasto gasto52 = new Gasto("telefone", 5, 70);
		Gasto gasto61 = new Gasto("água", 6, 30);
		Gasto gasto62 = new Gasto("telefone", 6, 70);
		Gasto gasto63 = new Gasto("presente para o professor", 6, 5900);

		usuario.incluirGasto(gasto11);
		usuario.incluirGasto(gasto12);
		usuario.incluirGasto(gasto21);
		usuario.incluirGasto(gasto22);
		usuario.incluirGasto(gasto31);
		usuario.incluirGasto(gasto32);
		usuario.incluirGasto(gasto33);
		usuario.incluirGasto(gasto34);
		usuario.incluirGasto(gasto41);
		usuario.incluirGasto(gasto42);
		usuario.incluirGasto(gasto43);
		usuario.incluirGasto(gasto44);
		usuario.incluirGasto(gasto51);
		usuario.incluirGasto(gasto52);
		usuario.incluirGasto(gasto61);
		usuario.incluirGasto(gasto62);
		usuario.incluirGasto(gasto63);

		usuario.exibeRelatorio();
	}
}

/*
É necessário desenvolver um sistema para exibir o seguinte relatório:

Nome: John Doe (john.doe@gmail.com / 9876-5432)
Gastos do primeiro semestre = R$7450,00
- Janeiro = R$100,00
--- água - R$ 30,00
--- telefone - R$ 70,00
- Fevereiro = R$50,00
--- água - R$ 10,00
--- telefone - R$ 40,00
- Março = R$900,00
--- água - R$ 30,00
--- telefone - R$ 70,00
--- luz - R$ 100,00
--- celular novo - R$ 700,00
- Abril = R$300,00
--- água - R$ 30,00
--- telefone - R$ 70,00
--- luz - R$ 100,00
--- refeição - R$ 100,00
- Maio = R$100,00
--- água - R$ 30,00
--- telefone - R$ 70,00
- Junho = R$6000,00
--- água - R$ 30,00
--- telefone - R$ 70,00
--- presente para o professor - R$ 5.900

1. Existe uma classe para guardar as informações do Usuário. Nessa classe existem os seguintes atributos: o nome e os contatos (e-mail e celular).

2. Existem duas interfaces implementadas pela classe de usuário:

a. IExibido: essa interface possui o método “void exibeRelatorio();”.

b. ICalcula: essa interface possui o método “void incluirGasto(Gasto gasto);”.

3. Na classe de usuário existe um mapa para agrupar os gastos por mês.

4. O método “incluirGasto()” deve preencher popular o mapa de gastos, somando o novo valor com o valor existente.

5. Além do mês e do valor do gasto existente no relatório, também é necessário cadastrar a descrição do gasto. Exemplo: água, luz, telefone....
 */