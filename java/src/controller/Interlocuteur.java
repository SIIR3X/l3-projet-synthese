package src.controller;

import java.awt.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;
import java.io.IOException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Interlocuteur extends Thread {
	PrintStream fluxSortant;
	BufferedReader fluxEntrant;
	int noClient;
	Controleur controleur = new Controleur();

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

	/**
	 *
	 */
	@Override
	public void run() {
		System.out.println("Interlocuteur prêt pour le client n°"+ this.noClient);
		Boolean premiere_ligne = true;

		Pattern pattern = Pattern.compile("^(\\d+) (\\d+) ([0-5])$");


		while(!this.isInterrupted()) {
			String requete = null;
			try {
				requete = this.fluxEntrant.readLine();
			}
			catch (IOException e) {
				e.printStackTrace();
			}
			
			if (requete == null) {
				controleur.run();
				System.out.println("Le client n°" + noClient + " s'est déconnecté.");
				while (!controleur.getFenetre().getDessinFini()) {

				}
				break;
			}

			System.out.println("le client n°"+ noClient + " a envoyé " + requete);

			// Gestion de la lecture et du COR

			if (premiere_ligne) { // La première ligne correspond aux paramètres utiles pour le dessin
				Matcher matcher = pattern.matcher(requete);
				if (!matcher.matches()) {
					System.out.println("Format invalide pour la première ligne : " + requete);
					break;
				}
				int width = Integer.parseInt(matcher.group(1)); // On récupère la largeur de la fenêtre
				int height = Integer.parseInt(matcher.group(2)); // On récupère la hauteur de la fenêtre
				int color = Integer.parseInt(matcher.group(3)); // On récupère la couleur du dessin
				controleur.setFenetre(width, height, color); // On initialise la fenêtre
				premiere_ligne = false;
			}
			else { //On traite toutes les formes envoyées avec le DP COR
				Shape forme = controleur.ParsingProcess(requete);
				if (forme == null) {
					System.out.println("La forme n'a pas pu être reconnue");
				}
				controleur.ajouterForme(forme); // On ajoute la forme à dessiner
				System.out.println("Forme ajoutée");
			}
		}
	}
}
