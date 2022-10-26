/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** NewEntitySystem
*/

#include "NewEntitySystem.hpp"

// #include "CRect.hpp"
#include "CPosition.hpp"
#include "CDirection.hpp"
#include "CVelocity.hpp"
#include "CKilled.hpp"
#include "CAssetId.hpp"

NewEntitySystem::NewEntitySystem()
{
    _graphicLib = std::make_unique<rtype::GraphicalLib>();

    _entityType[ENTITY_TYPE::PLAYER] = {"Assets/sprites/r-typesheet42.gif", {0, 0, 17.2, 33, 1, 5}};
    _entityType[ENTITY_TYPE::BULLET] = {"Assets/sprites/bullet.png", {0, 0, 14, 48.5, 1, 2}};
    _entityType[ENTITY_TYPE::ENEMY] = {"Assets/sprites/BasicEnemySpriteSheet.gif", {0, 0, 34, 33.5, 1, 8}};
}

NewEntitySystem::~NewEntitySystem()
{
}

static bool findEntity(Sparse_array<component::cserverid_t> &serverIds, uint16_t idToFind)
{
    for (std::size_t id = 0; id != serverIds.size(); id++) {
        if (serverIds[id]->id == idToFind)
            return true;
    }
    return false;
}

void NewEntitySystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &network, Sparse_array<component::cserverid_t> &serverIds, Sparse_array<component::casset_t> &assets)
{
    // Here check if the new entity queue is not empty and add the entity
    while (!network[FORBIDDEN_IDS::NETWORK].value().newEntityQueue.empty()) {
        packet_new_entity newEntity = network[FORBIDDEN_IDS::NETWORK]->newEntityQueue.front();
        network[FORBIDDEN_IDS::NETWORK]->newEntityQueue.pop();
        if (findEntity(serverIds, newEntity.id))
            continue;
        // std::cout << "[CLIENT] New entity system with type: "<< newEntity.type << std::endl;
        if (newEntity.type == ENTITY_TYPE::BULLET)
            addBullet(registry, newEntity, assets);
        if (newEntity.type == ENTITY_TYPE::ENEMY)
            addEnemy(registry, newEntity, assets);
        if (newEntity.type == ENTITY_TYPE::PLAYER)
            addShip(registry, newEntity, assets);
    }
}

void NewEntitySystem::addBullet(Registry &registry, packet_new_entity &newEntity, Sparse_array<component::casset_t> &assets)
{
    auto &asset = assets[FORBIDDEN_IDS::NETWORK]->assets;
    Entity bullet = registry.spawn_entity();
        std::cout << "[CLIENT]: new bullet" << std::endl;


    component::cdirection_t direction = {1, 0};
    registry.add_component<component::cdirection_t>(registry.entity_from_index(bullet), std::move(direction));

    component::crect_t rect = asset.at(newEntity.type).getRectangle();
    // component::crect_t rect = {_entityType.at(static_cast<ENTITY_TYPE>(newEntity.type)).second};
    registry.add_component<component::crect_t>(registry.entity_from_index(bullet), std::move(rect));

    component::cposition_t position = {.x = (float)newEntity.positionX, .y = (float)newEntity.positionY};
    registry.add_component<component::cposition_t>(registry.entity_from_index(bullet), std::move(position));

    component::cserverid_t serverId = {.id = newEntity.id};
    registry.add_component<component::cserverid_t>(registry.entity_from_index(bullet), std::move(serverId));

    component::cvelocity_t velocity = {.velocity = 14};
    registry.add_component<component::cvelocity_t>(registry.entity_from_index(bullet), std::move(velocity));
    registry.add_component<component::ckilled_t>(registry.entity_from_index(bullet), {false});
    component::cassetid_t assetId = {.assets = newEntity.type};

    registry.add_component<component::cassetid_t>(registry.entity_from_index(bullet), std::move(assetId));

}

void NewEntitySystem::addEnemy(Registry &registry, packet_new_entity &newEntity, Sparse_array<component::casset_t> &assets)
{
    std::cout << "[CLIENT]: new enemy" << std::endl;

    auto &asset = assets[FORBIDDEN_IDS::NETWORK]->assets;
    Entity enemy = registry.spawn_entity();
    component::cdirection_t direction = {-1, 0};
    registry.add_component<component::cdirection_t>(registry.entity_from_index(enemy), std::move(direction));
    component::crect_t rect = asset.at(newEntity.type).getRectangle();

    // component::crect_t rect = {_entityType.at(static_cast<ENTITY_TYPE>(newEntity.type)).second};
    registry.add_component<component::crect_t>(registry.entity_from_index(enemy), std::move(rect));
    component::cposition_t position = {.x = newEntity.positionX, .y = newEntity.positionY};
    registry.add_component<component::cposition_t>(registry.entity_from_index(enemy), std::move(position));
    component::cserverid_t serverId = {.id = newEntity.id};
    registry.add_component<component::cserverid_t>(registry.entity_from_index(enemy), std::move(serverId));
    component::cvelocity_t velocity = {.velocity = 4};
    registry.add_component<component::cvelocity_t>(registry.entity_from_index(enemy), std::move(velocity));
    registry.add_component<component::ckilled_t>(registry.entity_from_index(enemy), {false});
    component::cassetid_t assetId = {.assets = newEntity.type};

    registry.add_component<component::cassetid_t>(registry.entity_from_index(enemy), std::move(assetId));

}

void NewEntitySystem::addShip(Registry &registry, packet_new_entity &newEntity, Sparse_array<component::casset_t> &assets)
{
    auto &asset = assets[FORBIDDEN_IDS::NETWORK]->assets;

    std::cout << "[CLIENT]: new player ship" << std::endl;
    Entity ship = registry.spawn_entity();
    component::cdirection_t direction = {0, 0};
    registry.add_component<component::cdirection_t>(registry.entity_from_index(ship), std::move(direction));
    // component::crect_t rect = {_entityType.at(static_cast<ENTITY_TYPE>(newEntity.type)).second};
    component::crect_t rect = asset.at(newEntity.type).getRectangle();
    registry.add_component<component::crect_t>(registry.entity_from_index(ship), std::move(rect));
    component::cposition_t position = {.x = newEntity.positionX, .y = newEntity.positionY};
    registry.add_component<component::cposition_t>(registry.entity_from_index(ship), std::move(position));
    component::cserverid_t serverId = {.id = newEntity.id};
    registry.add_component<component::cserverid_t>(registry.entity_from_index(ship), std::move(serverId));
    component::cvelocity_t velocity = {.velocity = 8};
    registry.add_component<component::cvelocity_t>(registry.entity_from_index(ship), std::move(velocity));
    registry.add_component<component::ckilled_t>(registry.entity_from_index(ship), {false});
    component::cassetid_t assetId = {.assets = newEntity.type};

    registry.add_component<component::cassetid_t>(registry.entity_from_index(ship), std::move(assetId));

}
