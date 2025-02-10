package src.model.design_pattern_cor;

import src.model.Forme;

public abstract class ParserFormeCOR implements ParserForme {
	ParserFormeCOR next;

	public ParserFormeCOR(ParserFormeCOR next) {
		this.next = next;
	}

	@Override
	public Forme toParse (String line) {
		Forme forme = this.toParse1(line);

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

	abstract Forme toParse1(String line);
}
