package src.controller;

import src.model.Forme;

public class ParserFormeCORTriangle extends ParserFormeCOR {

	private char id;

	public ParserFormeCORTriangle(ParserFormeCOR next, char id) {
		super(next);
		this.id = id;
	}

	/**
	 *
	 * @param texte
	 * @return un composant forme Triangle si l'id correspond à l'id Triangle, sinon renvoie null
	 */
	@Override
	Forme toParse1(String texte) {
		try {
			char c = texte.charAt(0);

			if (c != id) return null;

			int[] xPoints;
			int[] yPoints;

			return Triangle(xPoints, yPoints);
		}
	}
}
