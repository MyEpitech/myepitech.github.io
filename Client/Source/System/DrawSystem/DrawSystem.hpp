/*
** EPITECH PROJECT, 2020
** DrawSystem.h
** File description:
** header for DrawSystem.c
*/

#ifndef R_TYPE_DRAWSYSTEM_H
    #define R_TYPE_DRAWSYSTEM_H

    #include "Registry.hpp"
    #include "GraphicalLib.hpp"
    #include "CPosition.hpp"
    #include "CRect.hpp"
    #include "CAsset.hpp"
    #include "CAssetId.hpp"
    #include "CSceneId.hpp"
    #include "CScale.hpp"
    #include "CText.hpp"
    #include "Constant.hpp"

/**
 * @brief DrawSystem class that handles the drawing of all the entities
 *
 */
class DrawSystem {
    public:
        /**
        * @brief Construct a new Event System object
         *
         */
        DrawSystem();
        /**
         * @brief Destroy the Event System object
         *
         */
        ~DrawSystem() = default;

        /**
         * @brief Update the DrawSystem
         * 
         * @param registry the registry of the server
         * @param positions the sparse array of position entities
         * @param rectangles the sparse array of rectangle entities
         * @param assets the sparse array of asset entities
         * @param assetsId the sparse array of assetId entities
         * @param scenesId the sparse array of sceneId entities
         * @param scales the sparse array of scale entities
         * @param texts the sparse array of text entities
         */
        void operator()(Registry &registry,
                        Sparse_array<component::cposition_t> &positions,
                        Sparse_array<component::crect_t> &rectangles,
                        Sparse_array<component::casset_t> &assets,
                        Sparse_array<component::cassetid_t> &assetsId,
                        Sparse_array<component::csceneid_t> &scenesId,
                        Sparse_array<component::cscale_t> &scales,
                        Sparse_array<component::ctext_t> &texts);


    protected:
    private:
        std::shared_ptr<rtype::GraphicalLib> _graphicLib; ///< Graphical library
};


#endif //R_TYPE_DRAWSYSTEM_H
