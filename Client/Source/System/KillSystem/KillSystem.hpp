/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** KillSystem
*/

#ifndef KILLSYSTEM_HPP_
    #define KILLSYSTEM_HPP_

    #include "Registry.hpp"
    #include "CNetworkQueue.hpp"
    #include "CServerId.hpp"
    #include <iostream>

class KillSystem {
    public:
        KillSystem();
        ~KillSystem() = default;

        void operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &network, Sparse_array<component::cserverid_t> &serverId);
        void killEntity(Registry &registry, std::size_t id, Sparse_array<component::cserverid_t> &serverId);

    protected:
    private:
};

#endif /* !KILLSYSTEM_HPP_ */
