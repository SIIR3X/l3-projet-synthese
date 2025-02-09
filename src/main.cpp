#include <iostream>

#include "Client.h"

int main(void)
{
	// // TEST tcp/ip
	// Client& client = Client::getInstance();

	// client.connect_to_server();

	// uint8_t continuer = 0;

	// do
	// {
	// 	// Send request
	// 	char request[L];
	// 	std::cout << "Ecrire votre requête ou \"quitter\" : ";
	// 	std::cin.getline(request, L);
	// 	continuer = strcmp(request, "quitter") != 0;

	// 	if (continuer)
	// 	{
	// 		client.send_request(request);

	// 		// Receive request
	// 		client.receive_request();
	// 		std::cout << client.get_buffer() << "\n";
	// 	}
	// } while (continuer);

	// client.shutdown_connection();
	// std::cout << "Shutting down..." << std::endl;

	// return EXIT_SUCCESS;
}