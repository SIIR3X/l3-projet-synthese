package src.view;

import src.model.Forme;

import javax.swing.*;
import java.awt.*;
import java.awt.image.BufferStrategy;
import java.util.ArrayList;

public class affichageDessins extends Canvas {

	private Forme forme;

	public affichageDessins(Forme forme) {
		this.forme = forme;

		setBackground(Color.WHITE);
		setIgnoreRepaint(true);
	}

	public void afficher () {
		try {
			// Attendre que le Canvas soit bien affiché avant de créer la stratégie de buffering
			if (!isDisplayable()) {
				System.err.println("Le Canvas n'est pas affiché !");
				return;
			}

			int numBuffers = 2;
			createBufferStrategy(numBuffers);

			Thread.sleep(150);

			BufferStrategy strategie = getBufferStrategy();

			Graphics graphics = strategie.getDrawGraphics();



			forme.dessiner(graphics);


			strategie.show();

			graphics.dispose();
		} catch (Exception e) {
			throw new RuntimeException(e);
		}
	}
}
