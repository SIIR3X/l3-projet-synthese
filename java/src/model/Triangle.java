package src.model;

import java.awt.*;

public class Triangle extends Forme {
	private int[] xPoints;
	private int[] yPoints;

	public Triangle(int[] x, int[] y) {
		this.xPoints = x;
		this.yPoints = y;
	}

	@Override
	public void dessiner(Graphics g) {
		Polygon triangle = new Polygon(xPoints, yPoints, 3);
		g.fillPolygon(triangle);
	}
}
