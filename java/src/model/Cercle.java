package src.model;

import java.awt.*;

public class Cercle extends Forme {
	private int x, y, rayon;
	private Color color;

	public Cercle(int x, int y, int rayon, Color color) {
		this.x = x;
		this.y = y;
		this.rayon = rayon;
		this.color = color;
	}

	@Override
	public void dessiner(Graphics g) {
		g.setColor(color);
		g.fillOval(x - rayon, y - rayon, 2*rayon, 2*rayon);
	}
}
