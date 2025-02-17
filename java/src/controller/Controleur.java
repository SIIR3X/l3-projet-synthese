package src.controller;

import src.model.design_pattern_cor.*;
import src.view.Fenetre;

import java.awt.*;

public class Controleur {
	private Fenetre fenetre;
	private ParserFormeCOR Parser = null;

	public Controleur() {}

	public void setFenetre(int width, int height, int color) {
		fenetre = new Fenetre(width, height, color);
	}

	public Fenetre getFenetre() {
		return fenetre;
	}

	public ParserFormeCOR getParser () {
		return Parser;
	}

	public Shape ParsingProcess (String line) {
		this.Parser = new ParserFormeCORPolygone(this.Parser);
		this.Parser = new ParserFormeCORTriangle(this.Parser);
		this.Parser = new ParserFormeCORCercle(this.Parser);
		this.Parser = new ParserFormeCORSegment(this.Parser);
		return Parser.toParse(line);
	}

	public void ajouterForme (Shape s) {
		this.fenetre.ajouterForme(s);
	}

	public void run() {
		fenetre.run();
	}
}
