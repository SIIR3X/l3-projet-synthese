#ifndef CLIENT_H
#define CLIENT_H

#include <winsock2.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdint>


/**
 * @brief Classe permettant d'établir un client TCP/IP
 * 
 * Il est nécessaire d'appeler Client::getInstance pour créer un objet client
 * 
 * Port utilisé : 9119
 */
class Client
{
private:
	WSADATA wsadata;
	SOCKADDR_IN sockaddr;
	const char* server_address;
	uint16_t server_port;
	SOCKET sock;

	/**
	 * @brief Affiche une chaîne de caractère (ou pas) et quitte le programme avec le code 1
	 * 
	 * @param msg chaîne de caractère à afficher
	 */
	void error(const char* msg) const;

	/**
	 * @brief Lance l'utilisation de la DLL Winsock par un processus.
	 */
	void init_WSA();

	/**
	 * @brief Créer un 'socket' avec les valeurs par defaut de `setup_connection`
	 */
	void create_socket();

	/**
	 * @brief Initialise des données membres pour `create_socket`.
	 * 
	 * Initialise une structure sockaddr nécessaire pour l'appel de la fonction winsock socket.
	 * Pour le protocol TCP à l'adresse IP '127.0.0.1' et au port '9119'.
	 */
	inline void setup_connection();

	/**
	 * @brief Constructeur par défaut.
	 */
	Client(const char* address = "127.0.0.1", const uint16_t port = 9119);

	~Client();

	// Suppression du constructeur par copie et de l'assignement par l'opérateur =
	// Afin d'assurer le DP Singleton
	Client(const Client&) = delete;
	Client& operator =(const Client&) = delete;
public:
	// Singleton
	static Client& getInstance();

	void connect_to_server();

	void send_request(const char* src);

	void shutdown_connection();

	const uint16_t& get_port() const;
};

inline void Client::shutdown_connection()
{
	int x;
	if ((x = shutdown(sock, SD_BOTH)) == SOCKET_ERROR)
	{
		error("\nL'arrêt de la connexion a échoué !\n");
	}
}

inline const uint16_t& Client::get_port() const
{
	return server_port;
}

#endif // CLIENT_H