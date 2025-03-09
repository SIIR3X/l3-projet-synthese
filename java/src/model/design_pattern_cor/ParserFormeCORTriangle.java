package src.model.design_pattern_cor;

import java.awt.*;
import java.awt.geom.Path2D;
import java.util.Locale;
import java.util.Scanner;

/**
 * Classe permettant de construire une forme (Shape) Triangle si les conditions sont vérifiées
 */
public class ParserFormeCORTriangle extends ParserFormeCOR {

	/**
	 * Un Triangle est identifié par l'id 3 (Nombre de sommets nécessaires)
	 */
	private int id = 3;

	public ParserFormeCORTriangle(ParserFormeCOR next) {
		super(next);
	}

	/**
	 * Méthode spécifique qui construit la forme seulement si c'est la bonne forme lue correspondante
	 * @param line String : la ligne à analyser
	 * @return un composant Shape représentant un Triangle si l'id correspond à l'id Triangle (3), sinon renvoie null
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
