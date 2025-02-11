package src.model.design_pattern_cor;

import java.awt.*;

public abstract class ParserFormeCOR implements ParserForme {
	ParserFormeCOR next;

	public ParserFormeCOR(ParserFormeCOR next) {
		this.next = next;
	}

	@Override
	public Shape toParse (String line) {
		Shape forme = this.toParse1(line);

		if (forme != null) {
			return forme;
		}
		else if (this.next != null) {
			return this.next.toParse(line);
		}
		else {
			return null;
		}
	}

	abstract Shape toParse1(String line);
}
