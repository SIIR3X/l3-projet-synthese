#ifndef VISITEUR_DESSINER_TCP_H
#define VISITEUR_DESSINER_TCP_H

#include "client/Client.h"
#include "graphique/Viewport.h"
#include "design_patterns/visiteur/VisiteurForme.h"

/**
 * @brief Classe VisiteurDessinerTCP permettant de dessiner des formes en TCP.
 */
class VisiteurDessinerTCP : public VisiteurForme
{
private:
	Client& _client; /**< Client TCP. */
	Viewport* _viewport; /**< Viewport de dessin. */
	bool _dansGroupe = false; /**< Flag indiquant si on est dans un groupe. */

	/**
	 * @brief Crée l'entête du paquet à envoyer.
	 * @param couleur Couleur de la forme.
	 * @return Entête du paquet.
	 */
	const char* creerEntete(Couleur couleur) const;

	/**
	 * @brief Envoie un paquet.
	 * @param paquet Paquet à envoyer.
	 */
	void envoyerPaquet(const char* paquet) const;

	/**
	 * @brief Envoie une forme simple.
	 * @param f Forme à envoyer.
	 */
	void envoyerFormeSimple(const Forme* forme) const;

public:
	/**
	 * @brief Constructeur de VisiteurDessinerTCP.
	 * @param v Viewport de dessin.
	 */
	VisiteurDessinerTCP(Viewport* v)
		: _client(Client::getInstance()), _viewport(v) {}

	void setViewport(Viewport* v) { _viewport = v; }

	virtual void visiter(Cercle* c) override;
	virtual void visiter(Segment* s) override;
	virtual void visiter(Triangle* t) override;
	virtual void visiter(Polygone* p) override;
	virtual void visiter(Groupe* g) override;
}; // class VisiteurDessinerTCP

inline const char* VisiteurDessinerTCP::creerEntete(Couleur couleur) const
{
	char* entete = new char[100];

	// On construit l'entête (largeur hauteur couleur)
	sprintf(entete, "%d %d %d", _viewport->largeurEcran(), _viewport->hauteurEcran(), (int)couleur);

	return entete;
}

inline void VisiteurDessinerTCP::envoyerPaquet(const char* paquet) const
{
	// On envoie le paquet à l'aide du client TCP
	_client.send_request(paquet);
}

inline void VisiteurDessinerTCP::envoyerFormeSimple(const Forme* forme) const
{
	// Si on n'est pas dans un groupe, on envoie l'entête et la forme
	if (!_dansGroupe)
	{
		// On se connecte au serveur
		_client.connect_to_server();

		// On envoie l'entête et la forme
		envoyerPaquet(creerEntete(forme->couleur()));
		envoyerPaquet(string(*forme).c_str());

		// On se déconnecte du serveur
		_client.shutdown_connection();
	}
	// Sinon, on envoie seulement la forme (visiter groupe se charge déjà d'ouvrir et fermer la connexion et de gérer l'entête)
	else
		envoyerPaquet(string(*forme).c_str());
}

#endif // VISITEUR_DESSINER_TCP_H