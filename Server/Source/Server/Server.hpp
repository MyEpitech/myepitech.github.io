/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Server
*/

#ifndef SERVER_HPP_
    #define SERVER_HPP_

    #include <boost/asio.hpp>
    
    #include "Communication.hpp"

using boost::asio::ip::udp;

class Server {
    public:
        Server(boost::asio::io_service &service, short const port);
        ~Server();

    protected:
    private:
        void startReceive();
        void handleReceive(const boost::system::error_code &e, std::size_t nbBytes);
        void handleSend(std::shared_ptr<std::string> message, const boost::system::error_code& ec, std::size_t bytes);

        std::shared_ptr<udp::socket> _socket;
        udp::endpoint _destination;

        Communication _communicationModule;
};

#endif /* !SERVER_HPP_ */
