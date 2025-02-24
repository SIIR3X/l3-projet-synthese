package src.model.design_pattern_cor;

import java.awt.*;

public interface ParserForme {

	/**
	 *
	 * @param line String : la ligne à analyser
	 * @return la forme exacte ou null si le texte n'est pas reconnu
	 */
	Shape toParse(String line);
}
