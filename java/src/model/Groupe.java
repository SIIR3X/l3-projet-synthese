package src.model;

import java.awt.*;
import java.util.ArrayList;

public class Groupe extends Forme {
	ArrayList<Forme> formes;

	public Groupe (ArrayList<Forme> formes) {
		this.formes = formes;
	}

	@Override
	public void dessiner (Graphics g) {
		for (Forme f : formes) {
			f.dessiner(g);
		}
	}

}
