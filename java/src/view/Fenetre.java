package src.view;

import javax.swing.*;
import java.awt.*;
import java.awt.image.BufferStrategy;
import java.util.ArrayList;

public class Fenetre extends JFrame implements Runnable {
	private ArrayList<Shape> shapes = new ArrayList<>();

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

	public void afficher () {
		try {
			int numBuffers = 2;
			createBufferStrategy(numBuffers);

			Thread.sleep(150);

			BufferStrategy strategie = getBufferStrategy();

			Graphics graphics = strategie.getDrawGraphics();
			setColor(graphics, color);

			Graphics2D drawer = (Graphics2D)graphics;
			for (Shape s : shapes) {
				drawer.draw(s);
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

	public void setFormes(ArrayList<Shape> formes) {
		this.shapes = formes;
	}

	@Override
	public void run() {
		afficher();
	}
}
