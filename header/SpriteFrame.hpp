#pragma once

#include <vector>
#include <string>

#include <SFML/Graphics/Sprite.hpp>

#define DEFAULT_FPS 5.0f


class SpriteFrame
{
    std::string name;

    std::vector<sf::Sprite> frames;

    float fps = DEFAULT_FPS;
};