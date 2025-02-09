package src.controller;

import src.model.Forme;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;
import java.io.IOException;
import java.util.ArrayList;

public class Interlocuteur extends Thread {
	PrintStream fluxSortant;
	BufferedReader fluxEntrant;
	int noClient;

	/**
	 *
	 * @param client
	 * @param noClient
	 * @throws IOException
	 */
	public Interlocuteur(Socket client, int noClient) throws IOException {
		this.fluxSortant = new PrintStream(client.getOutputStream());
		this.fluxEntrant = new BufferedReader(new InputStreamReader(client.getInputStream()));
		this.noClient = noClient;
	}

	@Override
	public void run() {
		System.out.println("Interlocuteur prêt pour le client n°"+ this.noClient);
		ArrayList<Forme> formes = new ArrayList<>();
		while(!this.isInterrupted()) {
			String requete = null;
			try {
				requete = this.fluxEntrant.readLine();
			}
			catch (IOException e) {
				e.printStackTrace();
			}
			System.out.println("le client n°"+ noClient + " a envoyé " + requete);

			String input = requete;

			//Gestion de la lecture et du COR

			//Si groupe -> création d'un groupe et ajout des formes dedans
			//Sinon rien

			String id;
			ParserFormeCOR Parser = null;
			Parser = new ParserFormeCORPolygone(Parser);
			Parser = new ParserFormeCORTriangle(Parser);
			Parser = new ParserFormeCORCercle(Parser);

			Forme f = Parser.toParse(requete);
			if (f != null) {
				formes.add(f);
			}

			Controleur controleur = new Controleur(1024, 768, f);

		}
	}
}
