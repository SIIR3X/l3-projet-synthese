package src.controller;

import src.model.Forme;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;
import java.io.IOException;

public class Interlocuteur extends Thread {
	PrintStream fluxSortant;
	BufferedReader fluxEntrant;
	int noClient;

	public Interlocuteur(Socket client, int noClient) throws IOException {
		this.fluxSortant = new PrintStream(client.getOutputStream());
		this.fluxEntrant = new BufferedReader(new InputStreamReader(client.getInputStream()));
		this.noClient = noClient;
	}

	@Override
	public void run() {
		System.out.println("interlocuteur pret pour le n"+ this.noClient);

		while(!this.isInterrupted()) {
			String requete = null;
			try {
				requete = this.fluxEntrant.readLine();
			}
			catch (IOException e) {

			}
			System.out.println("le client n°"+ noClient + "a envoye " + requete);

			String input = requete;

			//Gestion de la lecture et du COR

			String id;
			ParserFormeCOR Parser = null;
			Parser = new ParserFormeCORTriangle(Parser, id);

			Forme f = Parser.toParse(texte);
			if (f != null) {
				//ajouter la forme à la liste des formes
			}

		}
	}
}
