package src.model.design_pattern_cor;

import java.awt.*;
import java.awt.geom.Ellipse2D;
import java.util.Locale;
import java.util.Scanner;

public class ParserFormeCORCercle extends ParserFormeCOR {

	/**
	 * Un Cercle est identifié par l'id 1 (Nombre de points nécessaires)
	 */
	private int id = 1;

	public ParserFormeCORCercle(ParserFormeCOR next) {
		super(next);
	}

	/**
	 *
	 * @param line String : la ligne à analyser
	 * @return un composant Shape représentant un Cercle si l'id correspond à l'id Cercle (1), sinon renvoie null
	 */
	@Override
	Shape toParse1(String line) {
		try (Scanner scanner = new Scanner(line)) {
			scanner.useLocale(Locale.US);
			int type = scanner.nextInt();
			if (type != id) return null;

			double x = scanner.nextDouble();

			double y = scanner.nextDouble();
			double rayon = 2*scanner.nextDouble();

			return new Ellipse2D.Double(x, y, rayon, rayon);

		} catch (Exception e) {
			throw new RuntimeException(e);
		}

	}
}
