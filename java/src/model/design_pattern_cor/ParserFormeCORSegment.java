package src.model.design_pattern_cor;

import src.model.Cercle;
import src.model.Forme;
import src.model.Segment;

import java.util.Scanner;

public class ParserFormeCORSegment extends ParserFormeCOR {

	/**
	 * Un Segment est identifié par l'id 2
	 */
	private char id = '2';

	public ParserFormeCORSegment(ParserFormeCOR next) {
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

		int[] xPoints = new int[2];
		int[] yPoints = new int[2];

		for (int i = 0; i < 2; i++) {
			scanner.next();
			xPoints[i] = scanner.nextInt();
			scanner.next();
			yPoints[i] = scanner.nextInt();
			scanner.next();
		}

		return new Segment(xPoints[0], yPoints[0], xPoints[1], yPoints[1]);

	}
}
