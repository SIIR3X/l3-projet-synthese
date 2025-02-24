package src.controller;

import src.model.design_pattern_cor.*;
import src.view.Fenetre;

import java.awt.*;

/**
 * Classe Controleur qui gère la Vue et le Modèle
 */
public class Controleur {
	private Fenetre fenetre;
	private ParserFormeCOR Parser = null;

	/**
	 * Constructeur de Controleur
	 */
	public Controleur() {}

	/**
	 * Setter permettant d'initialiser le champ Fenetre
 	 * @param width
	 * @param height
	 * @param color
	 */
	public void setFenetre(int width, int height, int color) {
		fenetre = new Fenetre(width, height, color);
	}

	/**
	 *
	 * @return Fenetre
	 */
	public Fenetre getFenetre() {
		return fenetre;
	}

	/**
	 *
	 * @return ParserFormeCOR
	 */
	public ParserFormeCOR getParser () {
		return Parser;
	}

	/**
	 *
	 * @param line le String à lire
	 * @return un composant Shape si un Parser a répondu favorablement, sinon null
	 */
	public Shape ParsingProcess (String line) {
		this.Parser = new ParserFormeCORPolygone(this.Parser);
		this.Parser = new ParserFormeCORTriangle(this.Parser);
		this.Parser = new ParserFormeCORCercle(this.Parser);
		this.Parser = new ParserFormeCORSegment(this.Parser);
		return Parser.toParse(line);
	}

	/**
	 * Ajoute une forme à la liste de Shape de fenetre
	 * @param s une forme géométrique Shape
	 */
	public void ajouterForme (Shape s) {
		this.fenetre.ajouterForme(s);
	}

	/**
	 * Lance la génération du dessin dans fenetre
	 */
	public void run() {
		fenetre.run();
	}
}
