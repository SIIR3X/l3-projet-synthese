package src.model;

import src.view.Fenetre;

import java.awt.*;

public class Polygone extends Forme {
	private int[] xPoints, yPoints;

	public Polygone(int[] xPoints, int[] yPoints) {
		this.xPoints = xPoints;
		this.yPoints = yPoints;
	}

	@Override
	public void appelDessin(Graphics g, Fenetre fenetre) {
		fenetre.dessinerPolygone(g, xPoints, yPoints);
	}
}
