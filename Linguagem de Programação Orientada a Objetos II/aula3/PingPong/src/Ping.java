public class Ping extends Thread {
	Pong p;
	boolean played = false;

	public Pong getP() {
		return p;
	}

	public void setP(Pong p) {
		this.p = p;
	}

	public boolean isPlayed() {
		return played;
	}

	public void setPlayed(boolean played) {
		this.played = played;
	}

	@Override
	public void run() {
		while (true) {
			if (p.isPlayed() && !played) {
				p.setPlayed(false);
				System.out.println("Ping");
				played = true;
			} else {
				try {
					Thread.sleep(100);
				} catch (InterruptedException e) {}
			}
		}
	}
}
