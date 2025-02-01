package src.model;

import java.awt.*;

public class Triangle extends Forme {
	private int[] xPoints;
	private int[] yPoints;

	public Triangle(int[] xPoints, int[] yPoints) {
		this.xPoints = xPoints;
		this.yPoints = yPoints;
	}

	@Override
	public void dessiner(Graphics g) {
		Polygon triangle = new Polygon(xPoints, yPoints, 3);
		g.fillPolygon(triangle);
	}
}
