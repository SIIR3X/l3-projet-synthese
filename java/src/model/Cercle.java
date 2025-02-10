package src.model;

import src.view.Fenetre;

import java.awt.*;

public class Cercle extends Forme {
	private int x, y, rayon;
	private Color color;

	public Cercle(int x, int y, int rayon) {
		this.x = x;
		this.y = y;
		this.rayon = rayon;
	}

	@Override
	public void appelDessin(Graphics g, Fenetre fenetre) {
		fenetre.dessinerCercle(g, x, y, rayon);
	}
}
