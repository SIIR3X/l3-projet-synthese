package src.model.design_pattern_cor;

import java.awt.*;

public interface ParserForme {

	/**
	 *
	 * @param line
	 * @return la forme exacte ou null si le texte n'est pas reconnu
	 */
	public Shape toParse(String line);
}
