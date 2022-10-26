/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** RectSystem
*/

#include "RectSystem.hpp"
#include "Constant.hpp"

RectSystem::RectSystem()
{
    _graphicLib = std::make_unique<rtype::GraphicalLib>();
}

void RectSystem::operator()(Registry &registry, Sparse_array<component::crect_t> &rectangles, Sparse_array<component::ctimer_t> &timer, Sparse_array<component::ctype_t> &types, Sparse_array<component::casset_t> &assets, Sparse_array<component::cassetid_t> &assetId)
{
    if ((std::chrono::steady_clock::now() - timer[FORBIDDEN_IDS::NETWORK]->animTimer) > (std::chrono::nanoseconds)100000000) {
        timer[FORBIDDEN_IDS::NETWORK]->animTimer = std::chrono::steady_clock::now();
        // std::cout << "Chorno > 5000"  << std::endl;
    }
    else
        return;
    for (std::size_t i = 0; i < rectangles.size(); i++) {
        // auto &sp = sprites[i];
        auto &rect = rectangles[i];
        auto &type = types[i];
        auto &id = assetId[i];

        if (id) {
        if (rect->current_frame == rect->nb_frames)
            rect->current_frame = 0;
        rect->x = assets[FORBIDDEN_IDS::NETWORK]->assets.at(assetId[i]->assets).getTexture().getWidth() / rect->nb_frames * rect->current_frame;
        // rect->x = sp->sprite->getWidth() / rect->nb_frames * rect->current_frame;
        rect->current_frame++;
        }
    }
}