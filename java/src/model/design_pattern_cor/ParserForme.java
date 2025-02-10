package src.model.design_pattern_cor;

import src.model.Forme;

public interface ParserForme {

	/**
	 *
	 * @param line
	 * @return la forme exacte ou null si le texte n'est pas reconnu
	 */
	public Forme toParse(String line);
}
