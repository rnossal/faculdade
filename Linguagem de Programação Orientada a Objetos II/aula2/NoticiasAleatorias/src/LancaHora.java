import java.text.SimpleDateFormat;
import java.util.Date;

public class LancaHora extends Thread {
	@Override
	public void run() {
		for (int i = 0; i < 5; i++) {
			try {
				sleep(10000);
			} catch (InterruptedException ie) { }

			Date date = new Date();
			SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");

			System.out.println(sdf.format(date));
		}
	}
}
