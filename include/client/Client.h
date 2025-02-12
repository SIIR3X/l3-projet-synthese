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
	/*inline*/ void error(const char* msg)
	{
		if (msg)
		{
			puts(msg);
			// fflush(NULL);
		}
		exit(EXIT_FAILURE);
	}

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
	void setup_connection();

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

	const uint16_t& get_port();
};

/*****
	METHODES PRIVÉES
*****/

void Client::init_WSA()
{
	int x;
	if ((x = WSAStartup(MAKEWORD(0x02, 0x00), &wsadata)))
	{
		error("L'initialisation 'WSAStartup' a échoué.\n");
	}
}

void Client::create_socket()
{
	if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
	{
		const int socket_error_code = WSAGetLastError();
		const char* socket_error_msg = "La création du socket a échoué, code d'erreur : ";
		char socket_error_msg_code[50];
		sprintf(socket_error_msg_code, "%s %d", socket_error_msg, socket_error_code);
		error(socket_error_msg_code);
	}
}

inline void Client::setup_connection()
{
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_addr.s_addr = inet_addr(server_address);
	sockaddr.sin_port = htons(server_port); // convertie l'octet dans l'ordre réseau
}

Client::Client(const char* address = "127.0.0.1", const uint16_t port = 9119)
	: server_address(address), server_port(port), sock(INVALID_SOCKET)
{
	init_WSA();
	create_socket();
	setup_connection();
}

Client::~Client()
{
	if (sock != INVALID_SOCKET)
	{
		closesocket(sock);
	}
	WSACleanup();
}

/*****
	METHODES PUBLIQUES
*****/

// Singleton (static)
Client& Client::getInstance()
{
	// objet 'static' local : créée une seule fois
	static Client instance;
	return instance;
}

void Client::connect_to_server()
{
	int x;
	if ((x = connect(sock, (SOCKADDR*)&sockaddr, sizeof(sockaddr))) == SOCKET_ERROR)
	{
		error("\nLa connexion a échoué !\n");
	}
}

void Client::send_request(const char* src)
{
	if (!src)
	{
		error("\nLa requête a envoyé est vide !\n");
	}

	size_t src_len = strlen(src);
	char* request = new char[src_len + 3]; // +2 pour '\r\n' , +1 pour '\0'
	
	if (strncpy_s(request, src_len + 3, src, src_len))
	{
		delete[] request;
		error("\nLa copie de la requête dans le buffer local a échoué !\n");
	}

	// // assurer la terminaison null (pas necessaire car sizeof(dest) > sizeof(src))
	// request[src_len] = '\0';

	if (strcat_s(request, src_len + 3, "\r\n")) // terminaison standard pour serveur
	{
		delete[] request;
		error("\nL'ajout de la terminaison null à la requête à échoué !\n");
	}

	int x;
	size_t l = strlen(request);
	if ((x = send(sock, request, l, 0)) == SOCKET_ERROR)
	{
		error("\nL'envoi de la requête a échoué !\n");
	}

	delete[] request;
}

inline void Client::shutdown_connection()
{
	int x;
	if ((x = shutdown(sock, SD_BOTH)) == SOCKET_ERROR)
	{
		error("\nL'arrêt de la connexion a échoué !\n");
	}
}

inline const uint16_t& Client::get_port()
{
	return server_port;
}