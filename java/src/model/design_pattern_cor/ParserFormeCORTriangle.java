package src.model.design_pattern_cor;

import java.awt.*;
import java.awt.geom.Path2D;
import java.util.Locale;
import java.util.Scanner;

public class ParserFormeCORTriangle extends ParserFormeCOR {

	/**
	 * Un Triangle est identifié par l'id 3
	 */
	private int id = 3;

	public ParserFormeCORTriangle(ParserFormeCOR next) {
		super(next);
	}

	/**
	 *
	 * @param line la ligne à analyser
	 * @return un composant forme Triangle si l'id correspond à l'id Triangle, sinon renvoie null
	 */
	@Override
	Shape toParse1(String line) {
		try (Scanner scanner = new Scanner(line)) {
			scanner.useLocale(Locale.US);
			int type = scanner.nextInt();
			if (type != id) return null;

			Path2D.Double triangle = new Path2D.Double();
			triangle.moveTo(scanner.nextDouble(), scanner.nextDouble());
			triangle.lineTo(scanner.nextDouble(), scanner.nextDouble());
			triangle.lineTo(scanner.nextDouble(), scanner.nextDouble());

			triangle.closePath();

			return triangle;
		} catch (Exception e) {
			throw new RuntimeException(e);
		}

	}
}
