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

    float fps   = 5;

    bool loop   = true;


    sf::Sprite &getCurrentFrame();


    bool loadSpriteSheet(sf::Texture &texture, sf::Vector2i frameSize, int frameCount, bool append=0, int row=0);
};