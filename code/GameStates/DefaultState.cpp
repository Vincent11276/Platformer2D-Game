#include "GameStates/DefaultState.hpp"

#include <stdexcept>

DefaultState::DefaultState(zfge::GameStateManager& gameStateManager, sf::RenderTarget& mainWindow)
	: m_gameStateManager(gameStateManager)
	, m_mainWindow(mainWindow)
{
	if (!m_font.loadFromFile("assets/munro.ttf"))
	{
		throw std::runtime_error("Can't load assets/munro.ttf");
	}

	m_text.setFont(m_font);
	m_text.setCharacterSize(24);
	m_text.setFillColor(sf::Color::White);
	m_text.setString("This is a placeholder game state. Please add another state on top of this.");

	const sf::Vector2f textSize {m_text.getLocalBounds().width, m_text.getLocalBounds().height};
	const sf::Vector2f textPosition {m_text.getGlobalBounds().left, m_text.getGlobalBounds().top};

	const sf::Vector2f viewSize = m_mainWindow.getDefaultView().getSize();

	m_text.setPosition({(viewSize.x - textSize.x) / 2, (viewSize.y - textSize.y) / 2});
}

void DefaultState::handleEvent(sf::Event event)
{
	if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::Escape)
		{
			m_gameStateManager.pop();
		}
	}
}

void DefaultState::draw(sf::RenderTarget &target) const
{
	target.draw(m_text);
}
