/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Client
*/

#include <fstream>

#include "Client.hpp"
#include "Serialization.hpp"
#include "Constant.hpp"

/* Packet */
#include "Move.hpp"
#include "NewConnection.hpp"
#include "Disconnection.hpp"
#include "StartGame.hpp"

/* Component */
#include "CRef.hpp"
#include "fileConfig.hpp"
#include "CHealth.hpp"
#include "CScore.hpp"

Client::Client(std::string const &ip, std::string const &port, int hostPort, std::map<std::string, std::string> &configurationFiles) :
    _com(std::make_unique<UdpCommunication>(_context, hostPort, port, ip)),
    _connected(true)
{
    _graphicLib = std::make_unique<rtype::GraphicalLib>();
    _graphicLib->initWindow(1920, 1080, "R-Type", 60);

    _configurationFiles = configurationFiles;

    setUpEcs();
    setUpSystems();
    setUpComponents();
    _thread = std::thread(&Client::threadLoop, this);
}

Client::~Client()
{
    _context.stop();
    _connected = false;
    _thread.join();
}

void Client::tryToConnect()
{
    packet_new_connection packet = {.id = 0};
    std::vector<byte> bytes = serialize_header::serializeHeader<packet_new_connection>(NETWORK_CLIENT_TO_SERVER::PACKET_TYPE::NEW_CONNECTION, packet);
    _registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push(bytes);
}

void Client::machineRun()
{
    tryToConnect();
    while (!_graphicLib->windowShouldClose()) {
        _graphicLib->startDrawingWindow();
        _graphicLib->clearScreen();
        _registry.run_systems();
        _graphicLib->endDrawingWindow();
        SendPacket();
    }
    _graphicLib->closeWindow();
    // disconnect();
}

void Client::disconnect()
{
    _connected = false;
    packet_disconnection packet;
    packet.disconnection = _registry.get_components<component::cid_of_ship_t>()[FORBIDDEN_IDS::NETWORK].value().id;
    auto tmp = serialize_header::serializeHeader<packet_disconnection>(NETWORK_CLIENT_TO_SERVER::PACKET_TYPE::DISCONNECTION, packet);
    _registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push(tmp);
    SendPacket();
}

void Client::SendPacket() {
    while (!_registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.empty()) {
        std::vector<byte> tmp = _registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.front();
        _registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.pop();
        _com->send(tmp);
    }
}

void Client::handleReceive() {
    _com->async_receive(_bufferToGet, std::bind(&Client::pushNewPacketsToQueue, this, std::placeholders::_1, std::placeholders::_2));
}

void Client::pushNewPacketsToQueue([[ maybe_unused ]] asio::error_code const &e, [[maybe_unused]] size_t nbBytes)
{
    _registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK].value().receivedNetworkQueue.push(_bufferToGet);
    handleReceive();
}

void Client::threadLoop()
{
    handleReceive();
    _context.run();
}

void Client::setUpEcs()
{
    _registry.register_component<component::ckeyboard_t>();
    _registry.register_component<component::cposition_t>();
    _registry.register_component<component::crect_t>();
    _registry.register_component<component::cvelocity_t>();
    _registry.register_component<component::cserverid_t>();
    _registry.register_component<component::cnetwork_queue_t>();
    _registry.register_component<component::cdirection_t>();
    _registry.register_component<component::cid_of_ship_t>();
    _registry.register_component<component::ctype_t>();
    _registry.register_component<component::ctimer_t>();
    _registry.register_component<component::casset_t>();
    _registry.register_component<component::cassetid_t>();
    _registry.register_component<component::cclient_network_id>();
    _registry.register_component<component::csceneid_t>();
    _registry.register_component<component::cscale_t>();
    _registry.register_component<component::ccallback_t>();
    _registry.register_component<component::ctext_t>();
    _registry.register_component<component::ccolor_t>();
    _registry.register_component<component::cref_t>();
    _registry.register_component<component::chealth_t>();
    _registry.register_component<component::cscore_t>();
}

void Client::setUpSystems()
{
    _registry.add_system<component::cnetwork_queue_t, component::cid_of_ship_t>(_networkSystem);
    _registry.add_system<component::cnetwork_queue_t, component::ctype_t>(_killEntityTypeSystem);
    _registry.add_system<component::cnetwork_queue_t, component::cserverid_t>(_killSystem);
    _registry.add_system<component::crect_t, component::ctimer_t, component::casset_t, component::cassetid_t>(_rectSystem);
    _registry.add_system<component::ckeyboard_t, component::cnetwork_queue_t, component::cid_of_ship_t, component::csceneid_t, component::cclient_network_id>(_controlSystem);
	_registry.add_system<component::cposition_t, component::crect_t, component::csceneid_t, component::ctype_t, component::ccallback_t>(_mouseSystem);
    _registry.add_system<component::cnetwork_queue_t, component::cserverid_t, component::casset_t, component::cclient_network_id, component::csceneid_t>(_newEntitySystem);
    _registry.add_system<component::cnetwork_queue_t, component::cref_t, component::ctext_t>(_getLobbiesSystem);
    _registry.add_system<component::cnetwork_queue_t, component::cref_t, component::ctext_t>(_getInfoInLobbySystem);
    _registry.add_system<component::cnetwork_queue_t>(_setNbPlayerInLobbySystem);
    _registry.add_system<component::cnetwork_queue_t, component::cclient_network_id>(_newClientResponseSystem);
    _registry.add_system<component::cnetwork_queue_t, component::cposition_t, component::cserverid_t>(_positionSystem);
    _registry.add_system<component::cdirection_t, component::cposition_t, component::cvelocity_t, component::ctimer_t>(_moveSystem);
	_registry.add_system<component::cposition_t, component::crect_t, component::casset_t, component::cassetid_t, component::csceneid_t, component::cscale_t>(_drawSpriteSystem);
    _registry.add_system<component::cposition_t, component::csceneid_t, component::cscale_t, component::ccolor_t, component::ctext_t>(_drawTextSystem);
    _registry.add_system<component::chealth_t, component::cscore_t, component::cnetwork_queue_t, component::cserverid_t>(_updateEntityInfosSystem);
}

void Client::setUpComponents()
{
    component::casset_t assetMan;
    assetMan.assets = AssetManager(_configurationFiles.at("ASSET"));

    Entity network = _registry.spawn_entity_with(
            component::cnetwork_queue_t{},
            component::ctype_t{ .type = NET },
            component::cid_of_ship_t{ .id = 0 },
            component::ckeyboard_t{ .keyboard = 0 },
            component::ctimer_t{ .deltaTime = std::chrono::steady_clock::now(), .animTimer = std::chrono::steady_clock::now() },
            component::casset_t{ .assets = assetMan.assets },
            component::csceneid_t{ .sceneId = SCENE::CONNECTION }, // Set scene when the program start
            component::cclient_network_id {},
            component::cref_t{}
    );

    loadImages(_configurationFiles.at("IMAGES"), _registry.get_components<component::casset_t>());
    loadButtons(_configurationFiles.at("BUTTONS"), _registry.get_components<component::casset_t>());
    loadTexts(_configurationFiles.at("TEXTS"));
}

void Client::loadTexts(std::string const &filepath)
{
    nlohmann::json jsonData;

    try {
        jsonData = getJsonData(filepath);
    } catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
        return;
    }

    for (auto &oneData: jsonData) {
        int scene = oneData.value("scene", -1);
        std::string ref = oneData.value("ref", "error-txt");
        createText(oneData, std::array<float, 2>({0, 0}), scene, ref);
    }
}

void Client::createText(nlohmann::json const &oneData, std::array<float, 2> pos, int scene, const std::string &ref)
{
    std::array<float, 2> textPos = oneData.value("position", std::array<float, 2>({0, 0}));
    std::string content = oneData.value("text", "error");
    std::string font = oneData.value("font", "Assets/Fonts/Square.ttf");
    float spacing = oneData.value("spacing", 0);
    float fontSize = oneData.value("size", 30);
    std::array<float, 4> color = oneData.value("color", std::array<float, 4>({255, 255, 255, 255}));

    Entity text = _registry.spawn_entity_with(
        component::ctext_t{ .text = content, .font = font, .spacing = spacing },
        component::cposition_t{ .x = pos[0] + textPos[0], .y = pos[1] + textPos[1] },
        component::ctype_t{ .type = TEXT },
        component::csceneid_t{ .sceneId = static_cast<SCENE>(scene) },
        component::cscale_t{ .scale = fontSize },
        component::ccolor_t{ .color = color }
    );

    Sparse_array<component::cref_t> &reference = _registry.get_components<component::cref_t>();

    reference[FORBIDDEN_IDS::NETWORK].value().ref.insert({ref, _registry.entity_from_index(static_cast<std::size_t>(text))});
}

void Client::loadImages(std::string const &filepath, Sparse_array<component::casset_t> &assets)
{
    nlohmann::json jsonData;

    try {
        jsonData = getJsonData(filepath);
    } catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
        return;
    }

    for (auto &oneData: jsonData) {
        std::string assetId = oneData.value("textureId", "button");
        std::array<float, 2> pos = oneData.value("position", std::array<float, 2>({0, 0}));
        int scene = oneData.value("scene", 1);
        component::crect_t rectangle = assets[FORBIDDEN_IDS::NETWORK].value().assets.at(assetId).getRectangle();
        int nb_frames = assets[FORBIDDEN_IDS::NETWORK].value().assets.at(assetId).getNbFrames();
        int velocity = oneData.value("velocity", 0);
        std::array<int, 2> direction = oneData.value("direction", std::array<int, 2>({0, 0}));
        std::string ref = oneData.value("ref", "error-img");

        Entity image = _registry.spawn_entity_with(
            component::crect_t{ .x = rectangle.x, .y = rectangle.y, .width = rectangle.width, .height = rectangle.height / nb_frames, .current_frame = rectangle.current_frame, .nb_frames = rectangle.nb_frames },
            component::cposition_t{ .x = pos[0], .y = pos[1] },
            component::ctype_t{ .type = IMAGE },
            component::cassetid_t{ .assets = assetId },
            component::csceneid_t{ .sceneId = static_cast<SCENE>(scene) },
            component::cscale_t{ .scale = assets[FORBIDDEN_IDS::NETWORK].value().assets.at(assetId).getScale() },
            component::cvelocity_t{ .velocity = velocity },
            component::cdirection_t{ .x = direction[0], .y = direction[1] }
        );

        Sparse_array<component::cref_t> &reference = _registry.get_components<component::cref_t>();

        reference[FORBIDDEN_IDS::NETWORK].value().ref.insert({ref, _registry.entity_from_index(static_cast<std::size_t>(image))});
    }
}

void Client::loadButtons(std::string const &filepath, Sparse_array<component::casset_t> &assets)
{
    nlohmann::json jsonData;

    try {
        jsonData = getJsonData(filepath);
    } catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
        return;
    }

    _callbackMap = {
        {"connect", std::bind(&Client::connectToServer, this)},
        {"name-input", std::bind(&Client::nameInput, this)},
        {"ip-input", std::bind(&Client::ipInput, this)},
        {"port-input", std::bind(&Client::portInput, this)},
        {"see-rooms", std::bind(&Client::seeRooms, this)},
        {"back-to-connexion", std::bind(&Client::backToConnection, this)},
        {"start-game", std::bind(&Client::startGame, this)},
        {"back-to-main-menu", std::bind(&Client::backToMainMenu, this)},
        {"join-room-one", std::bind(&Client::joinRoomOne, this)},
        {"join-room-two", std::bind(&Client::joinRoomtwo, this)},
        {"join-room-three", std::bind(&Client::joinRoomThree, this)},
        {"see-lobby", std::bind(&Client::joinLobby, this)}
    };

    for (auto &oneData: jsonData) {
        std::string assetId = oneData.value("textureId", "button");
        std::array<float, 2> pos = oneData.value("position", std::array<float, 2>({0, 0}));
        std::string callbackType = oneData.value("callback-type", "back-to-main-menu");
        int scene = oneData.value("scene", -1);
        component::crect_t rectangle = assets[FORBIDDEN_IDS::NETWORK].value().assets.at(assetId).getRectangle();
        int nb_frames = oneData.value("nbFrame", 1);
        std::string ref = oneData.value("ref", "error-btn");

        Entity button = _registry.spawn_entity_with(
            component::crect_t{ .x = rectangle.x, .y = rectangle.y, .width = rectangle.width, .height = rectangle.height / nb_frames, .current_frame = rectangle.current_frame, .nb_frames = rectangle.nb_frames },
            component::cposition_t{ .x = pos[0], .y = pos[1] },
            component::ctype_t{ .type = BUTTON },
            component::cassetid_t{ .assets = assetId },
            component::csceneid_t{ .sceneId = static_cast<SCENE>(scene) },
            component::ccallback_t{ .callback = _callbackMap.at(callbackType) },
            component::cscale_t{ .scale = assets[FORBIDDEN_IDS::NETWORK].value().assets.at(assetId).getScale() }
        );
        if (oneData.contains("text"))
            createText(oneData.at("text"), pos, scene, ("text-" + ref));

        Sparse_array<component::cref_t> &reference = _registry.get_components<component::cref_t>();

        reference[FORBIDDEN_IDS::NETWORK].value().ref.insert({ref, _registry.entity_from_index(static_cast<std::size_t>(button))});
    }
}

void Client::connectToServer()
{
    // tryToConnect();

    Sparse_array<component::csceneid_t> &sceneId = _registry.get_components<component::csceneid_t>();

    sceneId[FORBIDDEN_IDS::NETWORK].value().sceneId = SCENE::MAIN_MENU;
}

void Client::nameInput()
{
    // Sparse_array<component::cref_t> &ref = _registry.get_components<component::cref_t>();
    // Sparse_array<component::ctext_t> &content = _registry.get_components<component::ctext_t>();

    // Entity test = _registry.entity_from_index(static_cast<std::size_t>(ref[FORBIDDEN_IDS::NETWORK].value().ref.at("text-name-input")));

    // content[test].value().text = "Prout";
}

void Client::ipInput()
{
}

void Client::portInput()
{
}

void Client::seeRooms()
{
    Sparse_array<component::csceneid_t> &sceneId = _registry.get_components<component::csceneid_t>();

    sceneId[FORBIDDEN_IDS::NETWORK].value().sceneId = SCENE::ROOMS;
}

void Client::backToConnection()
{
    Sparse_array<component::csceneid_t> &sceneId = _registry.get_components<component::csceneid_t>();

    sceneId[FORBIDDEN_IDS::NETWORK].value().sceneId = SCENE::CONNECTION;
}

void Client::startGame()
{
    Sparse_array<component::csceneid_t> &sceneId = _registry.get_components<component::csceneid_t>();
    sceneId[FORBIDDEN_IDS::NETWORK].value().sceneId = SCENE::GAME;

    Sparse_array<component::cnetwork_queue_t> &network = _registry.get_components<component::cnetwork_queue_t>();
    std::vector<byte> tmp = serialize_header::serializeHeader<packet_start_game>(NETWORK_CLIENT_TO_SERVER::PACKET_TYPE::START_GAME, {1});

    network[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push(tmp);
}

void Client::backToMainMenu()
{
    Sparse_array<component::csceneid_t> &sceneId = _registry.get_components<component::csceneid_t>();

    sceneId[FORBIDDEN_IDS::NETWORK].value().sceneId = SCENE::MAIN_MENU;
}

void Client::joinRoomOne()
{
    Sparse_array<component::cnetwork_queue_t> &network = _registry.get_components<component::cnetwork_queue_t>();
    std::vector<byte> tmp = serialize_header::serializeHeader<packet_join_lobby>(NETWORK_CLIENT_TO_SERVER::PACKET_TYPE::JOIN_LOBBY, {1});

    network[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push(tmp);
}

void Client::joinRoomtwo()
{
    Sparse_array<component::cnetwork_queue_t> &network = _registry.get_components<component::cnetwork_queue_t>();
    std::vector<byte> tmp = serialize_header::serializeHeader<packet_join_lobby>(NETWORK_CLIENT_TO_SERVER::PACKET_TYPE::JOIN_LOBBY, {2});

    network[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push(tmp);
}

void Client::joinRoomThree()
{
    Sparse_array<component::cnetwork_queue_t> &network = _registry.get_components<component::cnetwork_queue_t>();
    std::vector<byte> tmp = serialize_header::serializeHeader<packet_join_lobby>(NETWORK_CLIENT_TO_SERVER::PACKET_TYPE::JOIN_LOBBY, {3});

    network[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push(tmp);
}

void Client::joinLobby()
{
    Sparse_array<component::csceneid_t> &sceneId = _registry.get_components<component::csceneid_t>();
    sceneId[FORBIDDEN_IDS::NETWORK].value().sceneId = SCENE::LOBBY;
}
