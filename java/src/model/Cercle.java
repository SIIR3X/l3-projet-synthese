package src.model;

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
	public void dessiner(Graphics g) {
		g.fillOval(x - rayon, y - rayon, 2*rayon, 2*rayon);
	}
}
