/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** HitboxSystem
*/

#include "HitboxSystem.hpp"
#include "KillEntity.hpp"
#include "Serialization.hpp"
#include "Constant.hpp"

System::HitboxSystem::HitboxSystem()
{
}

void System::HitboxSystem::doCollisionConsequences(Registry &registry, component::cnetwork_queue_t &netQueue, component::chealth_t &health1, component::chealth_t &health2, component::clobby_id_t &lobbyId, int i, int x)
{
    health1.health--;
    health2.health--;
    std::cout << "Hit box system do collision consequences !" << health1.health << std::endl;
    std::cout << "Hit box system do collision consequences !" << health2.health << std::endl;

    if (health1.health == 0) {
        netQueue.toSendNetworkQueue.push({lobbyId.id, serialize_header::serializeHeader<packet_kill_entity>(NETWORK_SERVER_TO_CLIENT::KILL_ENTITY, {static_cast<int>(i)})});
        registry.kill_entity(registry.entity_from_index(i));
    }
    if (health2.health == 0) {
        netQueue.toSendNetworkQueue.push({lobbyId.id, serialize_header::serializeHeader<packet_kill_entity>(NETWORK_SERVER_TO_CLIENT::KILL_ENTITY, {static_cast<int>(x)})});
        registry.kill_entity(registry.entity_from_index(x));
    }
}

bool System::HitboxSystem::CheckCollision(component::crect_t const &rec1, component::crect_t const &rec2, component::cposition_t const &pos1, component::cposition_t const &pos2)
{
    if (pos1.y < (pos2.y + rec2.height) && (pos1.y + rec1.height) > pos2.y)
        if ((pos1.x < (pos2.x + rec2.width) && (pos1.x + rec1.width) > pos2.x))
            return true;
    return false;
}

void System::HitboxSystem::HitboxSystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &network_queues, Sparse_array<component::ctype_t> &types, Sparse_array<component::cposition_t> &positions, Sparse_array<component::crect_t> &rects, Sparse_array<component::chealth_t> &health, Sparse_array<component::clobby_id_t> &lobbyId) {
    (void)health;
    if (network_queues[FORBIDDEN_IDS::NETWORK]) {
        for (std::size_t i = 0; i < types.size() && i < positions.size() && i < rects.size() && i < lobbyId.size(); i++) {
            if (types[i] && positions[i] && rects[i] && lobbyId[i]) {
                auto &firsttype = types[i];
                auto &firstpos = positions[i];
                auto &firstrect = rects[i];

                if (firsttype.value().type != ENEMY)
                    continue;
                for (std::size_t x = 0; x < types.size() && x < positions.size() && x < rects.size() && x < lobbyId.size(); x++) {
                    if (types[x] && positions[x] && rects[x] && lobbyId[x]) {
                        if (x == i)
                            continue;
                        if (lobbyId[i].value().id != lobbyId[x].value().id)
                            continue;
                        auto &secondtype = types[x];
                        auto &secondpos = positions[x];
                        auto &secondrect = rects[x];

                        if (secondtype.value().type == ENEMY)
                            continue;
                        if (CheckCollision(firstrect.value(), secondrect.value(), firstpos.value(), secondpos.value())) {
                            std::cout << "hit box between " << firsttype.value().type << " and " << secondtype.value().type << std::endl;
                            if (secondtype.value().type == PLAYER || secondtype.value().type == BULLET) {
                                // std::cout << "hit box system lobby id entity to kill " << lobbyId[i].value().id << std::endl;
                                // network_queues[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push({lobbyId[i].value().id, serialize_header::serializeHeader<packet_kill_entity>(NETWORK_SERVER_TO_CLIENT::KILL_ENTITY, {static_cast<int>(i)})});
                                // network_queues[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push({lobbyId[i].value().id, serialize_header::serializeHeader<packet_kill_entity>(NETWORK_SERVER_TO_CLIENT::KILL_ENTITY, {static_cast<int>(x)})});
                                // registry.kill_entity(registry.entity_from_index(i));
                                // registry.kill_entity(registry.entity_from_index(x));
                                doCollisionConsequences(registry, network_queues[FORBIDDEN_IDS::NETWORK].value(), health[i].value(), health[x].value(), lobbyId[i].value(), i, x);
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}