package src.model.design_pattern_cor;

import java.awt.*;
import java.awt.geom.Path2D;
import java.util.Locale;
import java.util.Scanner;

/**
 * Classe permettant de construire une forme (Shape) Polygone si les conditions sont vérifiées
 */
public class ParserFormeCORPolygone extends ParserFormeCOR {

	/**
	 * Un Polygone est identifié par l'id 4 ou supérieur (Nombre de sommets nécessaires)
	 */
	private int id = 4;

	public ParserFormeCORPolygone(ParserFormeCOR next) {
		super(next);
	}

	/**
	 * Méthode spécifique qui construit la forme seulement si c'est la bonne forme lue correspondante
	 * @param line String : la ligne à analyser
	 * @return un composant Shape représentant un Polygone si l'id correspond à l'id Polygone (4), sinon renvoie null
	 */
	@Override
	Shape toParse1(String line) {
		try (Scanner scanner = new Scanner(line);) {
			scanner.useLocale(Locale.US);
			int type = scanner.nextInt();
			if (type < id) return null;

			Path2D.Double polygone = new Path2D.Double();
			polygone.moveTo(scanner.nextDouble(), scanner.nextDouble());

			for (int i = 1; i < type; i++) {
				polygone.lineTo(scanner.nextDouble(), scanner.nextDouble());
			}
			polygone.closePath();
			return polygone;
		} catch (Exception e) {
			throw new RuntimeException(e);
		}
	}
}
