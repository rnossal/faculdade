package model;

import com.google.gson.annotations.Expose;

import java.io.Serializable;
import java.util.ArrayList;

public class Ranking implements Serializable {
	@Expose()
	private ArrayList<UsuarioPercentual> ranking;

	public Ranking() {
		ranking = new ArrayList<>();
	}

	public Ranking(ArrayList<UsuarioPercentual> ranking) {
		this.ranking = ranking;
	}

	public ArrayList<UsuarioPercentual> getRanking() {
		return ranking;
	}

	public void setRanking(ArrayList<UsuarioPercentual> ranking) {
		this.ranking = ranking;
	}
}
