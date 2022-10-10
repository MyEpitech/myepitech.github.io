/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** IGraphicalLib
*/

#ifndef IGRAPHICALLIB_HPP_
#define IGRAPHICALLIB_HPP_

#include "GraphicalLib/Sprite/Sprite.hpp"
#include "GraphicalLib/Text/Text.hpp"
#include "GraphicalLib/Sound/MySound.hpp"
#include "GraphicalLib/Music/MyMusic.hpp"
#include "Datas/Position/Position.hpp"
#include <iostream>

namespace rtype {
    class IGraphicalLib {
        public:
            // IGraphicalLib();
            virtual ~IGraphicalLib() = default;

            //Useful functions
            virtual auto clearScreen() -> void = 0; // Clear the screen
            virtual auto startDrawingWindow() -> void = 0; // Start drawing on the window
            virtual auto endDrawingWindow() -> void = 0; // End drawing on the window
            virtual auto windowShouldClose() -> bool = 0; // Window should close

            // Sprites
            virtual auto createSprite(std::size_t id, std::string const &imagePath, Position const &position, float const &size) -> void = 0;
            virtual auto drawSprite(std::size_t id) -> void = 0;
            virtual auto destroySprite(std::size_t id) -> void = 0;

        virtual auto setSpritePosition(std::size_t id, Position const &position) -> void = 0;
            virtual auto setSpriteScale(std::size_t id, float scale) -> void = 0;
            virtual auto getSpritePosition(std::size_t id) -> Position = 0;
            virtual auto setSpriteRotation(std::size_t id, float rotation) -> void = 0;
            virtual auto getSpriteRotation(std::size_t id) -> float = 0;

            // Texts
            virtual auto createText(std::size_t id, std::string const &filename, std::string const &text, int fontSize, Color const &color, Position const &position) -> void = 0;
            virtual auto drawText(std::size_t id) -> void = 0;

            virtual auto setTextPosition(std::size_t id, Position const &position) -> void = 0;
            virtual auto getTextPosition(std::size_t id) -> Position = 0;

            virtual auto getText(std::size_t id) -> std::string = 0;
            virtual auto setText(std::size_t id, std::string const &text) -> void = 0;

            virtual auto setTextColor(std::size_t id, Color const &color) -> void = 0;
            virtual auto setTextFontSize(std::size_t id, int fontSize) -> void = 0;

            //Musics
            virtual auto createMusic(std::size_t id, std::string const &filename) -> void = 0;
            virtual auto playMusic(std::size_t id) -> void = 0;
            virtual auto stopMusic(std::size_t id) -> void = 0;
            virtual auto pauseMusic(std::size_t id) -> void = 0;
            virtual auto resumeMusic(std::size_t id) -> void = 0;

            virtual auto isMusicPlaying(std::size_t id) -> bool = 0;
            virtual auto setMusicVolume(std::size_t id, float volume) -> void = 0;
            virtual auto updateMusicStream(std::size_t id) -> void = 0;

            //Sounds
            virtual auto createSound(std::size_t id, std::string const &filename) -> void = 0;
            virtual auto playSound(std::size_t id) -> void = 0;
            virtual auto stopSound(std::size_t id) -> void = 0;
            virtual auto pauseSound(std::size_t id) -> void = 0;
            virtual auto resumeSound(std::size_t id) -> void = 0;
            virtual auto isSoundPlaying(std::size_t id) -> bool = 0;
            virtual auto setSoundVolume(std::size_t id, float volume) -> void = 0;

        protected:
        private:

    };
}

#endif /* !IGRAPHICALLIB_HPP_ */
