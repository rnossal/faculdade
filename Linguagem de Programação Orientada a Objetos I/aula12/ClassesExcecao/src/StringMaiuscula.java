/**
 * Created by rnossal on 27/06/2017.
 */
public class StringMaiuscula {
	public static void verificaLetraMaiuscula(String texto) throws NotLetterCharacterOnStringException, NotUpcaseCharacterOnStringException {
		for (char letra : texto.toCharArray()) {
			if (!Character.isLetter(letra)) {
				throw new NotLetterCharacterOnStringException("Há um caractere que não é letra.");
			}
			if (!Character.isUpperCase(letra)) {
				throw new NotUpcaseCharacterOnStringException("Há um caractere que não está com letra maiúscula.");
			}
		}
	}
}
