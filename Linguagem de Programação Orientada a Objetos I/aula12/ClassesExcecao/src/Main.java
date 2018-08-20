/**
 * Created by rnossal on 27/06/2017.
 */
public class Main {
	public static void main(String[] args) {
		String teste1 = "KJSYGFK98ASIKHB";
		String teste2 = "AIUOFHuEAKJFBGL";
		String teste3 = "KLDSAFHGKSDJFHG";

		try {
			StringMaiuscula.verificaLetraMaiuscula(teste1);
		} catch (NotLetterCharacterOnStringException | NotUpcaseCharacterOnStringException ex) {
			System.out.print("Erro ao verificar o texto de teste1: ");
			System.out.println(ex);
		}

		try {
			StringMaiuscula.verificaLetraMaiuscula(teste2);
		} catch (NotLetterCharacterOnStringException | NotUpcaseCharacterOnStringException ex) {
			System.out.print("Erro ao verificar o texto de teste2: ");
			System.out.println(ex);
		}

		try {
			StringMaiuscula.verificaLetraMaiuscula(teste3);
		} catch (NotLetterCharacterOnStringException | NotUpcaseCharacterOnStringException ex) {
			System.out.print("Erro ao verificar o texto de teste3: ");
			System.out.println(ex);
		}
	}
}
