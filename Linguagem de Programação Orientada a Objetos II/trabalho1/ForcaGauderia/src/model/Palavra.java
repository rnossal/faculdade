package model;

import com.google.gson.annotations.Expose;

import java.io.Serializable;

public class Palavra implements Serializable {
	@Expose()
	private String palavra;
	@Expose()
	private String dica;

	public Palavra() {}

	public Palavra(String palavra, String dica) {
		this.palavra = palavra;
		this.dica = dica;
	}

	public String getPalavra() {
		return palavra;
	}

	public void setPalavra(String palavra) {
		this.palavra = palavra;
	}

	public String getDica() {
		return dica;
	}

	public void setDica(String dica) {
		this.dica = dica;
	}
}
