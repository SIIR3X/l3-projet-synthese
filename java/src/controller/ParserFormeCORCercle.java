package src.controller;

import src.model.Cercle;
import src.model.Forme;

public class ParserFormeCORCercle extends ParserFormeCOR {

	/**
	 * Un Cercle est identifié par l'id 2
	 */
	private char id = '2';

	public ParserFormeCORCercle(ParserFormeCOR next) {
		super(next);
	}

	/**
	 *
	 * @param texte
	 * @return un composant forme Cercle si l'id correspond à l'id Cercle, sinon renvoie null
	 */
	@Override
	Forme toParse1(String texte) {
		char c = texte.charAt(0);

		if (c != id) return null;

		int x = 2;
		int y = 3;
		int rayon = 10;

		return new Cercle(x, y, rayon);

	}
}
