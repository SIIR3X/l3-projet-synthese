#include <winsock2.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdint>
#include <Ws2tcpip.h>

#define L 256

class Client
{
private:
	WSADATA wsadata;
	SOCKADDR_IN sockaddr;
	const char* server_address;
	uint16_t server_port;
	SOCKET sock;
	char buffer[L];

	void error(const char* msg)
	{
		if (msg)
		{
			std::cerr << msg << std::endl;
			fflush(NULL);
		}
		exit(EXIT_FAILURE);
	}

	void init_WSA()
	{
		int x;
		if ((x = WSAStartup(MAKEWORD(0x02, 0x00), &wsadata)))
		{
			error("L'initialisation 'WSAStartup' a échoué.\n");
		}
	}

	void create_socket()
	{
		if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
		{
			const int socket_error_code = WSAGetLastError();
			const char* socket_error_msg = "La création du socket a échoué, code d'erreur : ";
			char socket_error_msg_code[55];
			sprintf(socket_error_msg_code, "%s %d", socket_error_msg, socket_error_code);
			error(socket_error_msg_code);
		}
	}

	void setup_connection()
	{
		sockaddr.sin_family = AF_INET;
		sockaddr.sin_addr.s_addr = inet_addr(server_address);
		sockaddr.sin_port = htons(server_port); // convertie l'octet dans l'ordre réseau
	}

	Client(const char* address = "127.0.0.1", const uint16_t port = 9119)
		: server_address(address), server_port(port), sock(INVALID_SOCKET)
	{
		init_WSA();
		create_socket();
		setup_connection();
	}

	~Client()
	{
		if (sock != INVALID_SOCKET)
		{
			closesocket(sock);
		}
		WSACleanup();
	}

	// Suppression du constructeur par copie et de l'assignement par l'opérateur =
	Client(const Client&) = delete;
	Client& operator =(const Client&) = delete;
public:
	// Singleton
	static Client& getInstance()
	{
		// objet 'static' local : créée une seule fois
		static Client instance;
		return instance;
	}

	void connect_to_server()
	{
		int x;
		if ((x = connect(sock, (SOCKADDR*)&sockaddr, sizeof(sockaddr))) == SOCKET_ERROR)
		{
			error("\nLa connexion a échoué !\n");
		}
	}

	void send_message(const char* m)
	{
		int request;
		char message[L];
		strncpy_s(message, m, L);
		strcat_s(message, "\r\n"); // terminaison standard pour serveur

		int l = strlen(message);
		if ((request = send(sock, message, l, 0)) == SOCKET_ERROR)
		{
			error("\nL'envoi de la requête a échoué !\n");
		}
	}

	void receive_message()
	{
		int request;
		if ((request = recv(sock, buffer, L - 1, 0)) == SOCKET_ERROR)
		{
			error("\nLa récéption de la requête a échoué !\n");
		}

		char* ptr = strchr(buffer, '\n'); // Renvoie un pointeur sur '\n'
		if (ptr) {*ptr = '\0';}  // Remplace par fin de chaine '\0'
	}

	void shutdown_connection()
	{
		int x;
		if ((x = shutdown(sock, SD_BOTH)) == SOCKET_ERROR)
		{
			error("\nL'arrêt de la connexion a échoué !\n");
		}
	}

	const char* get_buffer()
	{
		return buffer;
	}
};