package src.controller;

import src.model.Forme;
import src.model.Polygone;

public class ParserFormeCORPolygone extends ParserFormeCOR {

	/**
	 * Un Polygone est identifié par l'id 4
	 */
	private char id = '4';

	public ParserFormeCORPolygone(ParserFormeCOR next) {
		super(next);
	}

	/**
	 *
	 * @param texte
	 * @return un composant forme Polygone si l'id correspond à l'id Polygone, sinon renvoie null
	 */
	@Override
	Forme toParse1(String texte) {
		char c = texte.charAt(0);

		if (c != id) return null;

		int[] xPoints = {2, 3};
		int[] yPoints = {2, 5};

		return new Polygone(xPoints, yPoints);
	}
}
