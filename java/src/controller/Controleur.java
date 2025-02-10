package src.controller;

import src.model.Forme;
import src.model.design_pattern_cor.*;
import src.view.Fenetre;

import java.util.ArrayList;

public class Controleur {
	private Fenetre fenetre;
	private ArrayList<Forme> formes;
	private ParserFormeCOR Parser = null;

	public Controleur() {
		this.formes = new ArrayList<>();
	}

	public void setFenetre(int width, int height, int color) {
		fenetre = new Fenetre(width, height, color);
	}

	public Forme ParsingProcess (String line) {
		this.Parser = new ParserFormeCORPolygone(this.Parser);
		this.Parser = new ParserFormeCORTriangle(this.Parser);
		this.Parser = new ParserFormeCORCercle(this.Parser);
		this.Parser = new ParserFormeCORSegment(this.Parser);
		return Parser.toParse(line);
	}

	public void ajouterForme (Forme f) {
		this.formes.add(f);
	}

	public void afficherDessin() {
		fenetre.afficher(formes);
	}
}
