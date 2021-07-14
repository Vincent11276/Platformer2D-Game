#include "AnimatedSprite.hpp"
               

AnimatedSprite::AnimatedSprite()
{
    // Default..
}


AnimatedSprite::AnimatedSprite(AnimationPack &animPack)
    : animationPack(animPack) { }


void AnimatedSprite::play(int animIndex)
{
    animationPack.animationIndex = animIndex;

    animationPack.animations[animIndex].resetFrame();

    playing = true;
}


void AnimatedSprite::play(std::string name)
{
    AnimatedSprite::play(animationPack.getIndexByName(name));
}


void AnimatedSprite::stop()
{
    playing = false;
}


void AnimatedSprite::update(float dt)
{
    if (playing)    
    {
        // if (clock.getElapsedTime().asSeconds() >= (1 / (spriteFrameSets[frameSetIndex].fps * speedScale)))
        // {
        //     spriteFrameSets[frameSetIndex].nextFrame();
        // }
    }
}


void AnimatedSprite::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    target.draw(animationPack.getCurrentAnimation().getCurrentFrame(), states);
}
