#include "AnimatedSprite.hpp"


int AnimatedSprite::getIndexByName(std::string name)
{
    for (int i = 0; i < spriteFrameSets.size(); i++)
    {
        if (spriteFrameSets[i].name == name)
        {
            return i;
        }
    }
    return -1;
}

void AnimatedSprite::play(int index)
{
    frameSetIndex = index;

    playing = true;
}

void AnimatedSprite::play(std::string name)
{
    AnimatedSprite::play(AnimatedSprite::getIndexByName(name));
}

void AnimatedSprite::update(float dt)
{
    if (playing)    
    {
        // if (clock.getElapsedTime().asSeconds() >= (1 / spriteFrameSets[frameSetIndex].fps))
        // {
        //     spriteFrameSets[frameSetIndex].nextFrame();
        // }
    }
}

bool AnimatedSprite::loadSpriteSheet(std::string &path, sf::Vector2i frameSize, bool append)
{
    sf::Texture texture;
    if (!texture.loadFromFile(path))
        return false;
        
    for (int frameY = 0; frameY < texture.getSize().y / frameSize.y; frameY++)
    {
        SpriteFrameSet newSpriteFrameSet;

        for (int frameX = 0; frameX < texture.getSize().x / frameSize.x; frameX++)
        {
            sf::Vector2i targetPosition(frameX * frameSize.x, frameY * frameSize.y);

            newSpriteFrameSet.frames.push_back(sf::Sprite(texture, sf::IntRect(targetPosition, targetPosition + frameSize)));
        }
        spriteFrameSets.push_back(newSpriteFrameSet);
    }
    return true;
}

void AnimatedSprite::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    target.draw(sf::Sprite(spriteFrameSets[frameSetIndex].frames[spriteFrameSets[frameSetIndex].index]), states);
}
