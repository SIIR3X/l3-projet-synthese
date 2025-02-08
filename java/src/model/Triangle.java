package src.model;

import java.awt.*;

public class Triangle extends Forme {
	private int[] xPoints, yPoints;

	public Triangle(int[] xPoints, int[] yPoints) {
		this.xPoints = xPoints;
		this.yPoints = yPoints;
	}

	@Override
	public void dessiner(Graphics g) {
		g.fillPolygon(xPoints, yPoints, 3);
	}
}
