package src.view;

import src.model.Forme;

import javax.swing.*;
import java.awt.*;
import java.awt.image.BufferStrategy;
import java.util.ArrayList;

public class Fenetre extends JFrame {
	private int width, height, color;
	private static final Color[] COLORS = {
			Color.BLACK,
			Color.BLUE,
			Color.RED,
			Color.GREEN,
			Color.YELLOW,
			Color.CYAN
	};



	public Fenetre(int width, int height, int color) {
		setTitle("Serveur de dessin");
		setSize(width, height);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBackground(Color.WHITE);
		setIgnoreRepaint(true);
		this.color = color;
	}

	public void afficher (ArrayList<Forme> formes) {
		try {
			int numBuffers = 2;
			createBufferStrategy(numBuffers);

			Thread.sleep(150);

			BufferStrategy strategie = getBufferStrategy();

			Graphics graphics = strategie.getDrawGraphics();
			setColor(graphics, color);

			for (Forme f : formes) {
				f.appelDessin(graphics, this);
			}

			strategie.show();

			graphics.dispose();
			setVisible(true);
		} catch (InterruptedException e) {
			throw new RuntimeException(e);
		}
	}

	public void setColor(Graphics g, int color) {
		g.setColor((color >= 0 && color < COLORS.length) ? COLORS[color] : Color.BLACK);
	}

	public void dessinerSegment(Graphics g, int x1, int y1, int x2, int y2) {
		g.drawLine(x1, y1, x2, y2);
	}

	public void dessinerPolygone(Graphics g, int[] xPoints, int[] yPoints) {
		g.fillPolygon(xPoints, yPoints, xPoints.length);
	}

	public void dessinerTriangle(Graphics g, int[] xPoints, int[] yPoints) {
		g.fillPolygon(xPoints, yPoints, xPoints.length);
	}

	public void dessinerCercle(Graphics g, int x, int y, int rayon) {
		g.fillOval(x - rayon, y - rayon, 2*rayon, 2*rayon);
	}
}
