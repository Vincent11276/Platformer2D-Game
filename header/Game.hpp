#pragma once

#include "GameStateManager.hpp"

namespace zfge
{

class Game
{
public:
	Game();

	void run();

	~Game();

private:
	void handleEvents();

	zfge::GameStateManager m_gameStateManager;
	sf::RenderWindow m_window;
};

}
