package src.model.design_pattern_cor;

import java.awt.*;

public abstract class ParserFormeCOR implements ParserForme {
	ParserFormeCOR next;

	/**
	 *
	 * @param next ParserFormeCOR : le chainon ParserFormeCOR suivant
	 */
	public ParserFormeCOR(ParserFormeCOR next) {
		this.next = next;
	}

	/**
	 *
	 * @param line String : la ligne à analyser
	 * @return la Shape associée aux points de la ligne lue
	 */
	@Override
	public Shape toParse (String line) {
		Shape forme = this.toParse1(line);

		if (forme != null) {
			return forme;
		}
		else if (this.next != null) {
			return this.next.toParse(line);
		}
		else {
			return null;
		}
	}

	/**
	 * Méthode différente et spécifique à chaque ParserForme
	 * @param line String : la ligne à analyser
	 * @return la Shape associée aux points de la ligne lue
	 */
	abstract Shape toParse1(String line);
}
