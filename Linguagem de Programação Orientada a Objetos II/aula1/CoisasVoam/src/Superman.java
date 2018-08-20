public class Superman extends Voador {
	private boolean clarkKent;

	public void disfarcar() {
		clarkKent = true;
	}

	public void serHeroi() {
		clarkKent = false;
	}

	public void voar(int metros) {
		super.voar(metros * 5);
	}

	public boolean estahDisfarcado() {
		return clarkKent;
	}

	public void setClarkKent(boolean clarkKent) {
		this.clarkKent = clarkKent;
	}
}
