public class Main {
	public static void main(String[] args) {
		Ping ping = new Ping();
		Pong pong = new Pong();

		ping.setP(pong);
		pong.setP(ping);

		ping.start();
		pong.start();
	}
}
