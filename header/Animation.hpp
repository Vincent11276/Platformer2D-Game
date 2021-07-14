#pragma once

#include <vector>
#include <string>

#include <SFML/Graphics/Sprite.hpp>



class Animation
{
public:
    std::vector<sf::Sprite> frames;

                std::string name;

                        int frameIndex;

                      float fps;

                       bool loop;


    sf::Sprite &getCurrentFrame();

    void resetFrame();

    void nextFrame();

    void previousFrame();
};