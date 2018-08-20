import java.util.ArrayList;
import java.util.Scanner;

/**
 * Created by rnossal on 14/03/2017.
 */

public class Main {
	private Scanner scan;

	public Main() {
		scan = new Scanner(System.in);
	}

	public Endereco readEndereco() {
		Endereco endereco = new Endereco();

		System.out.print("Digite o nome da rua: ");
		endereco.setRua(scan.nextLine());
		System.out.print("Digite o número: ");
		endereco.setNumero(scan.nextLine());
		System.out.print("Digite o complemento: ");
		endereco.setComplemento(scan.nextLine());
		System.out.print("Digite o bairro: ");
		endereco.setBairro(scan.nextLine());
		System.out.print("Digite o CEP: ");
		endereco.setCep(scan.nextLine());
		System.out.print("Digite a cidade: ");
		endereco.setCidade(scan.nextLine());

		return endereco;
	}
	public Aluno readAluno() {
		Aluno aluno = new Aluno();

		System.out.print("Digite o nome do aluno: ");
		aluno.setNome(scan.nextLine());
		System.out.print("Digite seu número da pratrícula: ");
		aluno.setNumeroMatricula(scan.nextLine());

		System.out.println("\nInformações referentes ao endereço residencial:\n");
		aluno.setEnderecoResidencial(readEndereco());
		System.out.println("\nInformações referentes ao endereço comercial:\n");
		aluno.setEnderecoComercial(readEndereco());

		return aluno;
	}
	public void printAluno(Aluno aluno) {
		System.out.println("Nome: " + aluno.getNome());
		System.out.println("Número da matrícula: " + aluno.getNumeroMatricula());
		System.out.println("\nEndereço residencial:");
		System.out.println("Rua: " + aluno.getEnderecoResidencial().getRua());
		System.out.println("Número: " + aluno.getEnderecoResidencial().getNumero());
		System.out.println("Complemento: " + aluno.getEnderecoResidencial().getComplemento());
		System.out.println("Bairro: " + aluno.getEnderecoResidencial().getBairro());
		System.out.println("CEP: " + aluno.getEnderecoResidencial().getCep());
		System.out.println("Cidade: " + aluno.getEnderecoResidencial().getCidade());
		System.out.println("\nEndereço comercial:");
		System.out.println("Rua: " + aluno.getEnderecoComercial().getRua());
		System.out.println("Numero: " + aluno.getEnderecoComercial().getNumero());
		System.out.println("Complemento: " + aluno.getEnderecoComercial().getComplemento());
		System.out.println("Bairro: " + aluno.getEnderecoComercial().getBairro());
		System.out.println("CEP: " + aluno.getEnderecoComercial().getCep());
		System.out.println("Cidade: " + aluno.getEnderecoComercial().getCidade());
	}

	public static void main(String[] args) {
		Main main = new Main();

		ArrayList<Aluno> alunos = new ArrayList<>();

		for (int i = 0; i < 2; i++) {
			alunos.add(main.readAluno());
			System.out.println("--------------------");
		}

		for (int i = 0; i < 2; i++) {
			main.printAluno(alunos.get(i));
			System.out.println("--------------------");
		}
	}
}
