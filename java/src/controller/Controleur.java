package src.controller;

import src.model.Forme;
import src.view.Fenetre;

import java.util.ArrayList;

public class Controleur {
	private Fenetre fenetre;


	public Controleur(int width, int height, ArrayList<Forme> formes) {
		fenetre = new Fenetre(width, height, formes);
		fenetre.afficher();
	}
}
