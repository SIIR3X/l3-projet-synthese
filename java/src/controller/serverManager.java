package src.controller;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class serverManager {
	private static final int portServeur = 9119;
	private static int noClient = -1;

	public static void main(String[] args) {
		try (ServerSocket serveur = new ServerSocket(portServeur)) {
			while(true) {
				Socket client = serveur.accept();
				++noClient;
				Interlocuteur interlocuteur = new Interlocuteur(client, noClient);
				interlocuteur.start();
			}
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}
}