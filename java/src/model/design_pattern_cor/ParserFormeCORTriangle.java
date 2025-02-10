package src.model.design_pattern_cor;

import src.model.Forme;
import src.model.Triangle;

import java.util.Scanner;

public class ParserFormeCORTriangle extends ParserFormeCOR {

	/**
	 * Un Triangle est identifié par l'id 3
	 */
	private char id = '3';

	public ParserFormeCORTriangle(ParserFormeCOR next) {
		super(next);
	}

	/**
	 *
	 * @param line la ligne à analyser
	 * @return un composant forme Triangle si l'id correspond à l'id Triangle, sinon renvoie null
	 */
	@Override
	Forme toParse1(String line) {
		Scanner scanner = new Scanner(line);
		int type = scanner.nextInt();
		if (type != id) return null;

		int[] xPoints = new int[3];
		int[] yPoints = new int[3];

		for (int i = 0; i < 3; i++) {
			scanner.next();
			xPoints[i] = scanner.nextInt();
			scanner.next();
			yPoints[i] = scanner.nextInt();
			scanner.next();
		}

		return new Triangle(xPoints, yPoints);

	}
}
