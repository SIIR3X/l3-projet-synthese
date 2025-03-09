package src.view;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ComponentAdapter;
import java.awt.event.ComponentEvent;
import java.awt.image.BufferStrategy;
import java.util.ArrayList;

/**
 * Classe représentant une fenêtre qui affiche des formes en active rendering.
 * Elle permet de dessiner des formes et un repère tout en s'adaptant au redimensionnement.
 */
public class Fenetre extends JFrame implements Runnable {
	private ArrayList<Shape> shapes = new ArrayList<>();
	private int color;
	private double scaleX = 1.0, scaleY = 1.0; // Facteurs d'échelle
	private int baseWidth, baseHeight; // Taille initiale de la fenêtre

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

		this.baseWidth = width;  // Stocke la taille de base
		this.baseHeight = height;

		// Listener pour détecter le redimensionnement
		addComponentListener(new ComponentAdapter() {
			@Override
			public void componentResized(ComponentEvent e) {
				updateScaling();
			}
		});

	}

	/**
	 * Met à jour les facteurs d'échelle en fonction de la nouvelle taille de la fenêtre.
	 */
	private void updateScaling() {
		int newWidth = getWidth();
		int newHeight = getHeight();

		scaleX = (double) newWidth / baseWidth;
		scaleY = (double) newHeight / baseHeight;
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
	 * @param g Graphics Le contexte graphique où dessiner
	 */
	private void drawRepere(Graphics g) {
		Graphics2D g2d = (Graphics2D) g;
		g2d.setColor(Color.GRAY); // Couleur du repère
		g2d.setStroke(new BasicStroke(1)); // Épaisseur des lignes

		int width = getWidth();
		int height = getHeight();

		// Axe X (horizontal)
		g2d.drawLine(-width / 2, 0, width / 2, 0);

		// Axe Y (vertical)
		g2d.drawLine(0, -height / 2, 0, height / 2);
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
				Graphics2D graphics = (Graphics2D) strategie.getDrawGraphics();
				graphics.clearRect(0, 0, getWidth(), getHeight()); // Efface l'ancien dessin

				// Applique l'échelle et la translation pour garder le dessin centré
				graphics.translate(getWidth() / 2, getHeight() / 2); // Centre le dessin
				graphics.scale(scaleX, scaleY); // Applique le zoom

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
