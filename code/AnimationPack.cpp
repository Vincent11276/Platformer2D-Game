#include "AnimationPack.hpp"


AnimationPack::AnimationPack()
{
    // default..
}


Animation &AnimationPack::getCurrentAnimation()
{
    return animations[animationIndex];
}


const Animation &AnimationPack::getCurrentAnimation() const
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