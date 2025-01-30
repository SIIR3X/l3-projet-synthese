package src.view;

import src.model.Forme;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

public class Fenetre extends JFrame {
	private int width, height;
	private affichageDessins affichage;
	private ArrayList<Forme> formes;

	public Fenetre(int width, int height) {
		setTitle("Serveur de dessin");
		setSize(width, height);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		formes = new ArrayList<>();
		affichage = new affichageDessins(formes);

		//getContentPane().add(affichage, BorderLayout.CENTER);
	}
}
