package model;

import com.google.gson.annotations.Expose;

import java.io.Serializable;

public class Usuario implements Serializable {
	@Expose()
	private String usuario;
	private String chave;
	@Expose()
	private int vitorias;
	@Expose()
	private int derrotas;

	public String getUsuario() {
		return usuario;
	}

	public void setUsuario(String usuario) {
		this.usuario = usuario;
	}

	public String getChave() {
		return chave;
	}

	public void setChave(String chave) {
		this.chave = chave;
	}

	public int getVitorias() {
		return vitorias;
	}

	public void setVitorias(int vitorias) {
		this.vitorias = vitorias;
	}

	public int getDerrotas() {
		return derrotas;
	}

	public void setDerrotas(int derrotas) {
		this.derrotas = derrotas;
	}
}
