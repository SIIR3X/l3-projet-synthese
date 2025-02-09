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
	// 	// Send message
	// 	char request[L];
	// 	std::cout << "Ecrire votre message ou \"quitter\" : ";
	// 	std::cin.getline(request, L);
	// 	continuer = strcmp(request, "quitter") != 0;

	// 	if (continuer)
	// 	{
	// 		client.send_message(request);

	// 		// Receive message
	// 		client.receive_message();
	// 		std::cout << client.get_buffer() << "\n";
	// 	}
	// } while (continuer);

	// client.shutdown_connection();
	// std::cout << "Shutting down..." << std::endl;

	// return EXIT_SUCCESS;
}