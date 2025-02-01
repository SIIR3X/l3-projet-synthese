package src.controller;

import src.model.Forme;

public interface ParserForme {

	/**
	 *
	 * @param texte
	 * @return la forme exacte ou null si le texte n'est pas reconnu
	 */
	public Forme toParse(String texte);
}
