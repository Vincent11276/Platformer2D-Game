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
    if (frameIndex > frames.size())
    {
        frameIndex = 0;
    }
    else frameIndex++;
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
        sf::Vector2i targetPosition(row * frameSize.x, column * frameSize.y);

        frames.push_back(sf::Sprite(texture, sf::IntRect(targetPosition, targetPosition + frameSize)));
    }
    return true;
}
