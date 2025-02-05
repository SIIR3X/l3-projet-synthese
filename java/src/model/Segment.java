package src.model;

import java.awt.*;

public class Segment extends Forme {
	private int x1, y1, x2, y2;

	public Segment(int x1, int y1, int x2, int y2) {
		this.x1 = x1;
		this.y1 = y1;
		this.x2 = x2;
		this.y2 = y2;

	}

	@Override
	void dessiner(Graphics g) {
		g.drawLine(x1, y1, x2, y2);
	}
}
