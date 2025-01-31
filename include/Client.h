#include <winsock2.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdint>
#include <Ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

class Client
{
private:
	SOCKET sock;
	SOCKADDR_IN sockaddr;
	WSADATA wsadata;
	const char* server_address;
	uint16_t server_port;

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
			error("WSAStartup a échoué.\n");
		}
	}

	void create_socket()
	{
		if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
		{
			const int socket_error_code = WSAGetLastError();
			const char* socket_error_msg = "La création du socket a échoué, code d'erreur : ";
			const char socket_error_msg_code[55];
			sprintf(socket_error_msg_code, "%s %d", socket_error_msg, socket_error_code);
			error(socket_error_msg_code);
		}
	}

	void setup_connection()
	{
		sockaddr.sin_family = AF_INET;
	    int buffer_size = MultiByteToWideChar(CP_ACP, 0, server_address, -1, NULL, 0);
	    wchar_t* wide_address = new wchar_t[buffer_size];
	    MultiByteToWideChar(CP_ACP, 0, server_address, -1, wide_address, buffer_size);

	    InetPton(AF_INET, wide_address, &sockaddr.sin_addr.s_addr);
	    sockaddr.sin_port = htons(server_port); // convertie l'octet dans l'ordre réseau
	}

public:
    Client(const char* address = "127.0.0.1", uint16_t port = 9119)
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

    int connect_to_server()
    {
        int x;
        if ((x = connect(sock, (SOCKADDR*)&sockaddr, sizeof(sockaddr))) == SOCKET_ERROR)
        {
            error("Connection failed!\n");
            return 0;
        }
        return 1;
    }

    int send_message(const char* message)
    {
        int x;
        char request[L];
        strncpy_s(request, message.c_str(), L);
        strcat_s(request, "\r\n"); // standard termination

        int l = strlen(request);
        if ((x = send(sock, request, l, 0)) == SOCKET_ERROR)
        {
            error("Failed sending request!\n");
            return 0;
        }
        return 1;
    }

    std::string receive_message()
    {
        int x;
        char response[L];
        int l = L;
        if ((x = recv(sock, response, l, 0)) == SOCKET_ERROR)
        {
            error("Reception failed!\n");
            return "";
        }

        char* p = strchr(response, '\n');
        if (p) *p = '\0';  // Terminate the response at the first newline

        return std::string(response);
    }

    void shutdown_connection()
    {
        int x;
        if ((x = shutdown(sock, SD_BOTH)) == SOCKET_ERROR)
        {
            error("Connection shutdown failed!\n");
        }
    }
};