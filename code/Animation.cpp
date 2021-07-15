#include "Animation.hpp"



sf::Sprite &Animation::getCurrentFrame()
{
    return frames[frameIndex];
}

void Animation::resetFrame()
{
    frameIndex = 0;
}

void Animation::nextFrame()
{
    frameIndex = (frameIndex + 1) % frames.size();
}

void Animation::previousFrame()
{
    if (frameIndex == 0)
    {
        frameIndex = frames.size() - 1;
    }
    else frameIndex--;
}

bool Animation::loadSpriteSheet(std::string name, sf::Texture &texture, sf::Vector2i frameSize, bool append, int row)
{    
    for (int column = 0; column < texture.getSize().x / frameSize.x; column++)
    {
        sf::Vector2i targetPosition(column * frameSize.x, row * frameSize.y);

        frames.push_back(sf::Sprite(texture, sf::IntRect(targetPosition, frameSize)));
    }
    return true;
}
