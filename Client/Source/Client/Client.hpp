/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Client
*/

#ifndef CLIENT_HPP_
    #define CLIENT_HPP_

    #include <asio/ip/udp.hpp>
    #include <asio/error_code.hpp>
    #include <asio/io_context.hpp>
    #include <asio/io_service.hpp>
    #include <asio/placeholders.hpp>

	#include "UdpCommunication.hpp"
	#include "LoadScene.hpp"
	#include "Registry.hpp"

class Client
{
	public:
		Client(std::string const &ip, std::string const &port, int hostPort);
		~Client();

		void setUpEcs(void);
		void setUpComponents(void);
		void machineRun(void);

	private:
		void handleReceive();
		asio::io_context _context;
		std::vector<byte> _bufferToGet;

		std::unique_ptr<UdpCommunication> _com;
        Registry _registry;
		bool _working;
		LoadScene _loadScene; // Scene loader
};

#endif /* !CLIENT_HPP_ */
