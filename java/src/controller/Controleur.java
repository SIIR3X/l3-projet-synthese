package src.controller;

import src.model.design_pattern_cor.*;
import src.view.Fenetre;

import java.awt.*;
import java.util.ArrayList;

public class Controleur {
	private Fenetre fenetre;
	private ArrayList<Shape> formesBuffer = new ArrayList<>();
	private ParserFormeCOR Parser = null;

	public Controleur() {}

	public void setFenetre(int width, int height, int color) {
		fenetre = new Fenetre(width, height, color);
	}

	public Shape ParsingProcess (String line) {
		this.Parser = new ParserFormeCORPolygone(this.Parser);
		this.Parser = new ParserFormeCORTriangle(this.Parser);
		this.Parser = new ParserFormeCORCercle(this.Parser);
		this.Parser = new ParserFormeCORSegment(this.Parser);
		return Parser.toParse(line);
	}

	public void ajouterForme (Shape s) {
		this.formesBuffer.add(s);
	}

	public void majFormes () {
		this.fenetre.setFormes(formesBuffer);
	}

	public void run() {
		fenetre.run();
	}
}
