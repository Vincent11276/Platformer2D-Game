#include "AnimationPack.hpp"


AnimationPack::AnimationPack()
{
    // default..
}


Animation AnimationPack::getCurrentAnimation()
{
    return animations[animationIndex];
}


Animation AnimationPack::getCurrentAnimation() const
{
    return animations[animationIndex];
}


int AnimationPack::getIndexByName(std::string name)
{
    for (int i = 0; i < animations.size(); i++)
    {
        if (animations[i].name == name)
        {
            return i;
        }
    }
    return -1;
}


bool AnimationPack::loadSpriteSheet(std::string &path, sf::Vector2i frameSize, bool append)
{
    sf::Texture texture;
    if (!texture.loadFromFile(path))
        return false;
        
    for (int frameY = 0; frameY < texture.getSize().y / frameSize.y; frameY++)
    {
        Animation newAnimation;

        for (int frameX = 0; frameX < texture.getSize().x / frameSize.x; frameX++)
        {
            sf::Vector2i targetPosition(frameX * frameSize.x, frameY * frameSize.y);

            newAnimation.frames.push_back(sf::Sprite(texture, sf::IntRect(targetPosition, targetPosition + frameSize)));
        }
        animations.push_back(newAnimation);
    }
    return true;
}