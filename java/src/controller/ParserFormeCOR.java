package src.controller;

import src.model.Forme;

public abstract class ParserFormeCOR implements ParserForme {
	ParserFormeCOR next;

	public ParserFormeCOR(ParserFormeCOR next) {
		this.next = next;
	}

	@Override
	public Forme toParse (String texte) {
		Forme forme = this.toParse(texte);

		if (forme != null) {
			return forme;
		}
		else {
			return null;
		}
	}

	abstract Forme toParse1(String texte);
}
