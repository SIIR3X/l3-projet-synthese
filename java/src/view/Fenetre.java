package src.view;

import src.model.Forme;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

public class Fenetre extends JFrame {
	private int width, height;
	private affichageDessins affichage;

	public Fenetre(int width, int height, ArrayList<Forme> formes) {
		setTitle("Serveur de dessin");
		setSize(width, height);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		affichage = new affichageDessins(formes);

		getContentPane().add(affichage, BorderLayout.CENTER);
		setVisible(true);

		//affichage.afficher();
	}

	public void afficher () {
		affichage.afficher();
	}
}
