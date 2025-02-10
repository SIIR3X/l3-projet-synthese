package src.model;

import src.view.Fenetre;

import java.awt.*;

public class Triangle extends Forme {
	private int[] xPoints, yPoints;

	public Triangle(int[] xPoints, int[] yPoints) {
		this.xPoints = xPoints;
		this.yPoints = yPoints;
	}

	@Override
	public void appelDessin(Graphics g, Fenetre fenetre) {
		fenetre.dessinerTriangle(g, xPoints, yPoints);
	}
}
