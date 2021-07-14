#pragma once

#include "Node.hpp"
#include "AnimatedSprite.hpp"

class Player : public Node
{
private:
    AnimatedSprite animatedSprite;

public:
    Player();
};
