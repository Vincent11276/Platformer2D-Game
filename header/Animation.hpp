#pragma once

#include <vector>
#include <string>
#include <iostream> // fuck
using namespace std;

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>



class Animation
{
public:
    std::vector<sf::Sprite> frames;

    std::string name;

    int frameIndex=0;

    float fps = 5;

    bool loop;


    sf::Sprite &getCurrentFrame();

    void resetFrame();

    void nextFrame();

    void previousFrame();

    bool loadSpriteSheet(std::string name, sf::Texture &texture, sf::Vector2i frameSize, int frameCount, bool append=0, int row=0);
};