public class Pong extends Thread {
	Ping p;
	boolean played = true;

	public Ping getP() {
		return p;
	}

	public void setP(Ping p) {
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
				System.out.println("Pong");
				played = true;
			} else {
				try {
					Thread.sleep(100);
				} catch (InterruptedException e) {}
			}
		}
	}
}
