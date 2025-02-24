package src.model.design_pattern_cor;

import java.awt.*;
import java.awt.geom.Line2D;
import java.util.Locale;
import java.util.Scanner;

public class ParserFormeCORSegment extends ParserFormeCOR {

	/**
	 * Un Segment est identifié par l'id 2 (Nombre de points nécessaires)
	 */
	private int id = 2;

	public ParserFormeCORSegment(ParserFormeCOR next) {
		super(next);
	}

	/**
	 *
	 * @param line String : la ligne à analyser
	 * @return un composant Shape repr"sentant un Segment si l'id correspond à l'id Segment (2), sinon renvoie null
	 */
	@Override
	Shape toParse1(String line) {
		try (Scanner scanner = new Scanner(line)) {
			scanner.useLocale(Locale.US);
			int type = scanner.nextInt();
			if (type != id) return null;

			double x1 = scanner.nextDouble();
			double y1 = scanner.nextDouble();
			double x2 = scanner.nextDouble();
			double y2 = scanner.nextDouble();

			return new Line2D.Double(x1, y1, x2, y2);
		} catch (Exception e) {
			throw new RuntimeException(e);
		}
	}
}
