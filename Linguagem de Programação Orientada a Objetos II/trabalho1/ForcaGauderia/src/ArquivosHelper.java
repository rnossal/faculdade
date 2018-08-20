import java.io.*;
import java.lang.reflect.Type;

public class ArquivosHelper {
	public static <T> T leArquivoObjeto(String camnho, Class<T> classe) throws FileNotFoundException, IOException, ClassNotFoundException{
		File fileLeitura = new File(camnho);
		ObjectInputStream objStream = new ObjectInputStream(new FileInputStream(fileLeitura));
		Object classeLida = objStream.readObject();
		objStream.close();

		return classe.cast(classeLida);
	}

	public static void escreveArquivoObjeto(String caminho, Object objeto) throws FileNotFoundException, IOException {
		File fileEscrita = new File(caminho);
		ObjectOutputStream objStream = new ObjectOutputStream(new FileOutputStream(fileEscrita));
		objStream.writeObject(objeto);
		objStream.close();
	}
}
