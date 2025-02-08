package src.controller;

import src.model.Forme;
import src.model.Triangle;

public class ParserFormeCORTriangle extends ParserFormeCOR {

	/**
	 * Un Triangle est identifié par l'id 3
	 */
	private char id = '3';

	public ParserFormeCORTriangle(ParserFormeCOR next) {
		super(next);
	}

	/**
	 *
	 * @param texte
	 * @return un composant forme Triangle si l'id correspond à l'id Triangle, sinon renvoie null
	 */
	@Override
	Forme toParse1(String texte) {
		char c = texte.charAt(0);

		if (c != id) return null;

		int[] xPoints  = {2, 3};
		int[] yPoints  = {2, 3};

		return new Triangle(xPoints, yPoints);

	}
}
