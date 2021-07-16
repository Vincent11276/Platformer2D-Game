#include "Animation.hpp"



bool Animation::loadSpriteSheet(sf::Texture &texture, sf::Vector2i frameSize, int frameCount, bool append, int row)
{    
    for (int column = 0; column < frameCount; column++)
    {
        sf::Vector2i targetPosition(column * frameSize.x, row * frameSize.y);

        frames.push_back(sf::Sprite(texture, sf::IntRect(targetPosition, frameSize)));
    }
    return true;
}
