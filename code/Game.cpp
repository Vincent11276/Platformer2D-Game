#include "Game.hpp"

#include "Utility/Keyboard.hpp"

#include <imgui.h>
#include <imgui-SFML.h>

namespace astro
{

Game::Game()
	: m_window(sf::VideoMode(600, 600), "SpaceShooter")
{
	m_window.setKeyRepeatEnabled(false);
	m_window.setFramerateLimit(60);

	ImGui::SFML::Init(m_window);

	// m_gameStateManager.push<MainMenu>(m_gameStateManager, m_window);
}

void Game::run()
{
	m_gameStateManager.update();

	const sf::Time fixedUpdateInterval = sf::seconds(1.0f / 60.0f);

	sf::Clock timer;
	sf::Time elapsed = sf::Time::Zero;
	sf::Time lag = sf::Time::Zero;

	while (m_window.isOpen() && !m_gameStateManager.isEmpty())
	{
		zfge::GameState& currentState = m_gameStateManager.peek();

		elapsed = timer.restart();
		lag += elapsed;

		handleEvents();

		ImGui::SFML::Update(m_window, elapsed);

		currentState.update(elapsed.asSeconds());

		while (lag >= fixedUpdateInterval)
		{
			lag -= fixedUpdateInterval;
			currentState.fixedUpdate(fixedUpdateInterval.asSeconds());
		}

		ImGui::Begin("Game Loop Stats");
		ImGui::LabelText("FPS", "%f", 1 / elapsed.asSeconds());
		ImGui::End();

		m_window.clear();
		currentState.draw(m_window);
		ImGui::SFML::Render(m_window);
		m_window.display();

		m_gameStateManager.update();
	}

	if (m_window.isOpen())
		m_window.close();
}

void Game::handleEvents()
{
	zfge::GameState& currentState = m_gameStateManager.peek();

	for (sf::Event event; m_window.pollEvent(event);)
	{
		ImGui::SFML::ProcessEvent(event);

		if (event.type == sf::Event::KeyPressed)
			Keyboard::setKey(event.key.code, true);
		else if (event.type == sf::Event::KeyReleased)
			Keyboard::setKey(event.key.code, false);

		currentState.handleEvent(event);
	}
}

Game::~Game()
{
	ImGui::SFML::Shutdown();
}

}
