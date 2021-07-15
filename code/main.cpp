#include <iostream>
#include <string>
#include <vector>

using namespace std;


#include <SFML/Graphics.hpp>

#include "AnimatedSprite.hpp"



int main()
{
    std::string spriteSheetPath = "C:\\Users\\Vincent\\Documents\\GitHub\\Platformer2D-Game\\assets\\Arts\\Intellect Devourer Sprites.png";

    sf::Texture texture;
    if (!texture.loadFromFile(spriteSheetPath))
        return EXIT_FAILURE;

    Animation animation;
    if (!animation.loadSpriteSheet("idle", texture, sf::Vector2i(32, 32), 4))
        return EXIT_FAILURE;

    AnimationPack animationPack;
    animationPack.animations.push_back(animation);

    AnimatedSprite animatedSprite(animationPack);
    animatedSprite.scale(sf::Vector2f(5, 5));
    animatedSprite.play(0);

    sf::RenderWindow window(sf::VideoMode(800, 600), "Animated Sprite Demo.");
    window.setVerticalSyncEnabled(true);


    sf::Font bigSpaceFont;
    if (!bigSpaceFont.loadFromFile("C:\\Users\\Vincent\\Documents\\GitHub\\Platformer2D-Game\\assets\\Fonts\\big-space-font\\BigSpace-rPKx.ttf"))
        return EXIT_FAILURE;

    sf::Text fpsText;
    fpsText.setFont(bigSpaceFont);
    fpsText.setFillColor(sf::Color::White);

    sf::Clock clock;

    while (window.isOpen())
    {
        float delta = clock.restart().asMicroseconds();

        sf::Event event;
        while(window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();

                default:
                    break;
            }
        }
        fpsText.setString(std::to_string(1000000.0f / delta));
        animatedSprite.update();

        window.clear();
        window.draw(animatedSprite);
        window.draw(fpsText);   
        window.display();
    }



    return EXIT_SUCCESS;
}