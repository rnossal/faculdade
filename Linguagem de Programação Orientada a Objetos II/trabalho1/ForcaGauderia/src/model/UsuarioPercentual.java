package model;

import com.google.gson.annotations.Expose;

import java.io.Serializable;

public class UsuarioPercentual extends Usuario implements Serializable {
	@Expose()
	private double percentual;

	public UsuarioPercentual() {
		// percentual = (getVitorias() * 100) / (getVitorias() + getDerrotas());
	}

	public UsuarioPercentual(String usuario, int vitorias, int derrotas) {
		setUsuario(usuario);
		setVitorias(vitorias);
		setDerrotas(derrotas);
		percentual = (getVitorias() * 100) / (getVitorias() + getDerrotas());
	}

	public double getPercentual() {
		return percentual = (getVitorias() * 100) / (getVitorias() + getDerrotas());
	}
}
