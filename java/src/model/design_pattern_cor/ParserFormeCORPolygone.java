package src.model.design_pattern_cor;

import java.awt.*;
import java.awt.geom.Path2D;
import java.util.Locale;
import java.util.Scanner;

public class ParserFormeCORPolygone extends ParserFormeCOR {

	/**
	 * Un Polygone est identifié par l'id 4 ou supérieur (Nombre de points nécessaires)
	 */
	private int id = 4;

	public ParserFormeCORPolygone(ParserFormeCOR next) {
		super(next);
	}

	/**
	 *
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
