package src.controller;

import src.model.Forme;

public abstract class ParserFormeCOR implements ParserForme {
	ParserFormeCOR next;

	public ParserFormeCOR(ParserFormeCOR next) {
		this.next = next;
	}

	@Override
	public Forme toParse (String texte) {
		Forme forme = this.toParse1(texte);

		if (forme != null) {
			return forme;
		}
		else if (this.next != null) {
			return this.next.toParse(texte);
		}
		else {
			return null;
		}
	}

	abstract Forme toParse1(String texte);
}
