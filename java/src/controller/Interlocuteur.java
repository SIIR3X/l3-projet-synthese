package src.controller;

import javax.swing.*;
import java.awt.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;
import java.io.IOException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Classe qui va "écouter" et traiter ce que le client lui envoie
 */
public class Interlocuteur extends Thread {
	BufferedReader fluxEntrant;
	int noClient;
	Controleur controleur = new Controleur();

	/**
	 * Constructeur de Interlocuteur : récupère à partir du socket les informations envoyées par le client
	 * @param client Socket
	 * @param noClient int
	 * @throws IOException Exception
	 */
	public Interlocuteur(Socket client, int noClient) throws IOException {
		this.fluxEntrant = new BufferedReader(new InputStreamReader(client.getInputStream()));
		this.noClient = noClient;
	}

	/**
	 * Thread permettant de recevoir et instancier les formes pour les dessiner
	 */
	@Override
	public void run() {
		System.out.println("Interlocuteur prêt pour le client n°"+ this.noClient);
		boolean premiere_ligne = true;

		// regex permettant de collecter les informations de base nécessaires à la vue (largeur et hauteur de la fenêtre + couleur des formes)
		Pattern pattern = Pattern.compile("^(\\d+) (\\d+) ([0-5])$");


		while(!this.isInterrupted()) {
			String requete = null;
			try {
				requete = this.fluxEntrant.readLine();
			}
			catch (IOException e) {
				e.printStackTrace();
			}
			
			if (requete == null) { // Il n'y a plus rien à lire
				System.out.println("Le client n°" + noClient + " s'est déconnecté.");
				break;
			}

			System.out.println("le client n°"+ noClient + " a envoyé " + requete);

			if (premiere_ligne) { // On lit la ligne contenant les informations nécessaires à la création de la fenêtre
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
		// Utilisation de SwingWorker pour exécuter `controleur.run()` de manière asynchrone
		SwingWorker<Void, Void> worker = new SwingWorker<Void, Void>() {
			@Override
			protected Void doInBackground() throws Exception {
				controleur.run();
				return null;
			}
		};
		worker.execute();  // Exécuter l'action longue en arrière-plan
	}
}
