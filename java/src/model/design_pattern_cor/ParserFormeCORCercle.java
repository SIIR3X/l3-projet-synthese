package src.model.design_pattern_cor;

import src.model.Cercle;
import src.model.Forme;

import java.util.Scanner;

public class ParserFormeCORCercle extends ParserFormeCOR {

	/**
	 * Un Cercle est identifié par l'id 1
	 */
	private char id = '1';

	public ParserFormeCORCercle(ParserFormeCOR next) {
		super(next);
	}

	/**
	 *
	 * @param line la ligne à analyser
	 * @return un composant forme Cercle si l'id correspond à l'id Cercle, sinon renvoie null
	 */
	@Override
	Forme toParse1(String line) {
		Scanner scanner = new Scanner(line);
		int type = scanner.nextInt();
		if (type != id) return null;

		scanner.next();
		int x = scanner.nextInt();
		scanner.next();
		int y = scanner.nextInt();
		scanner.next();
		int rayon = scanner.nextInt();

		return new Cercle(x, y, rayon);

	}
}
