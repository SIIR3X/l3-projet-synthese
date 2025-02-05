package src.model;

import java.awt.*;

public class Polygone extends Forme {
	private int[]xPoints, yPoints;

	public Polygone(int[] xPoints, int[] yPoints) {
		this.xPoints = xPoints;
		this.yPoints = yPoints;
	}

	@Override
	public void dessiner(Graphics g) {
		g.fillPolygon(xPoints, yPoints, xPoints.length);
	}
}
