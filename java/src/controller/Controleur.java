package src.controller;

import src.model.Forme;
import src.view.Fenetre;

import java.util.ArrayList;

public class Controleur {
	private Fenetre fenetre;
	private ArrayList<Forme> formes;

	public Controleur(int width, int height, ArrayList<Forme> formes) {
		fenetre = new Fenetre(width, height, formes);
		this.formes = formes;
	}

	public void ajouterForme(Forme forme) {
		formes.add(forme);
	}

	public void afficher() {
		fenetre.afficher();
	}
}
