#include "SpriteFrameSet.hpp"


void SpriteFrameSet::nextFrame()
{
    if (index > frames.size())
    {
        index = 0;
    }
    else index++;
    
}

void SpriteFrameSet::previousFrame()
{
    if (index == 0)
    {
        index = frames.size() - 1;
    }
    else index--;
}

