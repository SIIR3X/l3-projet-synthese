package src.view;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ComponentAdapter;
import java.awt.event.ComponentEvent;
import java.awt.image.BufferStrategy;
import java.util.ArrayList;

public class Fenetre extends JFrame implements Runnable {
	private ArrayList<Shape> shapes = new ArrayList<>();
	private boolean dessinFini = false;
	private int color;
	private int lastX, lastY;

	/**
	 * Tableau des couleurs possibles pour les formes
	 */
	private static final Color[] COLORS = {
			Color.BLACK,
			Color.BLUE,
			Color.RED,
			Color.GREEN,
			Color.YELLOW,
			Color.CYAN
	};

	/**
	 * Constructeur de Fenetre
	 * @param width int
	 * @param height int
	 * @param color int
	 */
	public Fenetre(int width, int height, int color) {
		setTitle("Serveur de dessin");
		setSize(width, height);
		setLocationRelativeTo(null);
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		setBackground(Color.WHITE);
		setIgnoreRepaint(true);
		setVisible(true);
		this.color = color;

		addComponentListener(new ComponentAdapter() {
			@Override
			public void componentMoved(ComponentEvent e) {
				// Récupère la position actuelle
				int newX = getLocation().x;
				int newY = getLocation().y;

				// Calcule le décalage
				int dx = newX - lastX;
				int dy = newY - lastY;

				// Met à jour la position
				lastX = newX;
				lastY = newY;

				// Applique la translation au rendu
				appliquerTransformation(dx, dy);
			}
		});

	}

	/**
	 * Gère le déplacement de la fenetre en recalculant les points des formes
	 * @param dx int
	 * @param dy int
	 */
	private void appliquerTransformation(int dx, int dy) {
		if (dx != 0 || dy != 0) {
			int numBuffers = 2;
			createBufferStrategy(numBuffers);
			try {
				Thread.sleep(150);
			} catch (InterruptedException e) {
				throw new RuntimeException(e);
			}
			BufferStrategy strategie = getBufferStrategy();
			if (strategie == null) return;

			Graphics2D graphics = (Graphics2D) strategie.getDrawGraphics();
			graphics.translate(dx, dy); // Décale tout le dessin

			// Efface et redessine tout
			graphics.clearRect(0, 0, getWidth(), getHeight());
			drawRepere(graphics);
			setColor(graphics, color);

			for (Shape s : shapes) {
				graphics.draw(s);
			}

			strategie.show();
			graphics.dispose();
		}
	}

	/**
	 * Attribue la couleur donnée au dessin (par défaut noir)
	 * @param g
	 * @param color
	 */
	public void setColor(Graphics g, int color) {
		g.setColor((color >= 0 && color < COLORS.length) ? COLORS[color] : Color.BLACK);
	}

	/**
	 * Ajoute la Shape donnée à la liste shapes de la Fenetre
	 * @param forme Shape
	 */
	public void ajouterForme(Shape forme) {
		this.shapes.add(forme);
	}

	/**
	 * Dessine un repère centré sur la Fenetre
	 * @param g Graphics
	 */
	private void drawRepere(Graphics g) {
		Graphics2D g2d = (Graphics2D) g;
		g2d.setColor(Color.GRAY); // Couleur du repère
		g2d.setStroke(new BasicStroke(1)); // Épaisseur des lignes

		int midX = getWidth() / 2;
		int midY = getHeight() / 2;

		// Dessiner l'axe X
		g2d.drawLine(0, midY, getWidth(), midY);

		// Dessiner l'axe Y
		g2d.drawLine(midX, 0, midX, getHeight());
	}

	/**
	 * Dessine les Shape contenues dans la liste shapes
	 */
	@Override
	public void run() {
		try {
			int numBuffers = 2;
			createBufferStrategy(numBuffers);
			Thread.sleep(150);
			BufferStrategy strategie = getBufferStrategy();

			while (isDisplayable()) {
				Graphics graphics = strategie.getDrawGraphics();
				graphics.clearRect(0, 0, getWidth(), getHeight()); // Efface l'ancien dessin
				drawRepere(graphics);
				setColor(graphics, color);

				Graphics2D drawer = (Graphics2D) graphics;
				for (Shape s : shapes) {
					drawer.draw(s);
				}

				strategie.show();
				graphics.dispose();

				try {
					Thread.sleep(16); // Limite le framerate (~60 FPS)
				} catch (InterruptedException e) {
					Thread.currentThread().interrupt();
					break;
				}
			}
		} catch (InterruptedException e) {
			throw new RuntimeException(e);
		}
	}
}
