package src.model.design_pattern_cor;

import src.model.Forme;
import src.model.Polygone;

import java.util.Scanner;

public class ParserFormeCORPolygone extends ParserFormeCOR {

	/**
	 * Un Polygone est identifié par l'id 4 ou supérieur
	 */
	private char id = '4';

	public ParserFormeCORPolygone(ParserFormeCOR next) {
		super(next);
	}

	/**
	 *
	 * @param line la ligne à analyser
	 * @return un composant forme Polygone si l'id correspond à l'id Polygone, sinon renvoie null
	 */
	@Override
	Forme toParse1(String line) {
		Scanner scanner = new Scanner(line);
		int type = scanner.nextInt();
		if (type < id) return null;

		int[] xPoints = new int[type];
		int[] yPoints = new int[type];

		for (int i = 0; i < type; i++) {
			scanner.next();
			xPoints[i] = scanner.nextInt();
			scanner.next();
			yPoints[i] = scanner.nextInt();
			scanner.next();
		}

		return new Polygone(xPoints, yPoints);
	}
}
