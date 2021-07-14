#pragma once

#include "GameStates/GameState.hpp"
#include "GameStateManager.hpp"

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

class DefaultState final : public zfge::GameState
{
public:
	DefaultState(zfge::GameStateManager& gameStateManager, sf::RenderTarget& mainWindow);

	void handleEvent(sf::Event event) override;
	void update(float deltaTime) override {};
	void draw(sf::RenderTarget& target) const override;

private:
	zfge::GameStateManager& m_gameStateManager;
	sf::RenderTarget& m_mainWindow;

	sf::Font m_font;
	sf::Text m_text;
};
