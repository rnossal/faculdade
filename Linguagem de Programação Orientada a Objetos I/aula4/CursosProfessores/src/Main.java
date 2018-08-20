/**
 * Created by Rafael Nossal on 23/03/2017.
 */
public class Main {
	public static void main(String[] args) {
		Professor professor1 = new Professor();
		Professor professor2 = new Professor();

		Curso curso1 = new Curso();
		Curso curso2 = new Curso();
		Curso curso3 = new Curso();

		professor1.setNumero(1);
		professor1.setNome("Imdudran");
		professor2.setNumero(10);
		professor2.setNome("Gimri");

		curso1.setNumero(1);
		curso1.setNome("Forjando Armaduras I");
		curso1.setProfessor(professor1);
		curso2.setNumero(10);
		curso2.setNome("Batalhas com Machado");
		curso2.setProfessor(professor2);
		curso3.setNumero(11);
		curso3.setNome("Forjando Armas III");
		curso3.setProfessor(professor1);

		curso1.exibeDados();
		System.out.println("------------------------------");
		curso2.exibeDados();
		System.out.println("------------------------------");
		curso3.exibeDados();
	}
}
