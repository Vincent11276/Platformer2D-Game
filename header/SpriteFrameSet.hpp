#pragma once

#include <vector>
#include <string>

#include <SFML/Graphics/Sprite.hpp>


class SpriteFrameSet
{
public:
    std::string name;

    std::vector<sf::Sprite> frames;
    std::size_t index;

    float fps = 5.0f;
    bool loop = true;

    void nextFrame();
    void previousFrame();
};
