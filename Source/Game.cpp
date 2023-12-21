#include "../Headers/Game.h"
#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include "../Headers/Menu.h"
#include "../Headers/MenuOption.h"


Game::Game()
{
	font.loadFromFile("./Fonts/PixelifySans-Regular.ttf");
	setScoreText(0, 0);
}

void Game::runGame() {
	sf::RenderWindow window(sf::VideoMode(board.width, board.height), "SFML works!");

	// Initialization of UI, players, and ball
	Menu menu;
	Player player1(sf::Color::Green, sf::Vector2f(0, 100));
	Player player2(sf::Color::White, sf::Vector2f(780, 100));
	Ball ball;
	int selectedItem = 0;
	int prevItem = 0;
	float playerSpeed = 0.05f;
	bool inMenu = true;
	bool swapMove = false;

	menu.selectOpt(0, sf::Color::Red);
	sf::Event event;
	while (window.isOpen())
	{
		window.clear();
		drawGameObjects(window, scoreText, player1.shape, player2.shape, ball.shape, inMenu);
		if (inMenu)
		{
			handleMenu(window, menu, inMenu);
			drawMenu(window, menu);

			unsigned int scoreTo = ballCollision(ball.shape.getGlobalBounds(), player1.shape.getGlobalBounds(), player2.shape.getGlobalBounds());
			if (scoreTo > 0) swapMove = !swapMove;
			ball.move(ballPosX, ballPosY);

			if (!swapMove) player2.autoMove(ball);
			else player1.autoMove(ball);
		}
		else
		{
			handlePlayerMovement(player1, player2, playerSpeed);
			handleGameInput(inMenu);

			unsigned int scoreTo = ballCollision(ball.shape.getGlobalBounds(), player1.shape.getGlobalBounds(), player2.shape.getGlobalBounds());
			scoreHandler(scoreTo);

			ball.move(ballPosX, ballPosY);
		}

		window.display();
	}
}

unsigned int Game::ballCollision(const sf::FloatRect& ball, const sf::FloatRect& player1, const sf::FloatRect& player2)
{
	if (ball.intersects(player1))
	{
		// manage lateral collision
		if (ball.left + ball.width <= player1.left || ball.left >= player1.left + player1.width) {
			ballPosX = -ballPosX;
		}
		else {
			ballPosX = -ballPosX;
		}
	}
	else if (ball.intersects(player2))
	{
		// manage lateral collision
		if (ball.left + ball.width <= player1.left || ball.left >= player2.left + player2.width) {
			ballPosX = -ballPosX;
		}
		else {
			ballPosX = -ballPosX;
		}
	}
	else if (ball.left <= board.left || ball.left + ball.width >= board.left + board.width)
	{
		ballPosX = -ballPosX;
		return ball.left < 0 ? 1 : 2;
	}
	else if (ball.top <= board.top || ball.top + ball.height >= board.top + board.height)
	{
		ballPosY = -ballPosY;
	}

	return 0;
}

MenuOption Game::windowHandler(sf::RenderWindow& window, sf::Event& event) {
	if (event.type == sf::Event::Closed)
	{
		return EXIT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		return PAUSE;
	}
}

void Game::scoreHandler(unsigned int scoreTo) {
	switch (scoreTo)
	{
	case 1:
		setScoreText(score1++, score2);
		break;

	case 2:
		setScoreText(score1, score2++);
		break;
	}
}

void Game::setScoreText(unsigned int score1, unsigned int score2)
{
	std::string txt = std::to_string(score1) + " - " + std::to_string(score2);
	scoreText.setFont(font);
	scoreText.setString(txt);
	scoreText.setCharacterSize(30);  // Tamaño del scoreTxt en puntos
	scoreText.setFillColor(sf::Color::White); // Color del texto
	scoreText.setPosition(400, 0);
}

void Game::drawMenu(sf::RenderWindow& window, Menu& menu)
{
	for (const auto& item : menu.getMenu())
	{
		window.draw(item);
	}
}

void Game::handleMenu(sf::RenderWindow& window, Menu& menu, bool& inMenu)
{
	sf::Event event;
	while (window.pollEvent(event)) {
		MenuOption exitOption = windowHandler(window, event);
		if (exitOption == EXIT) {
			window.close();
		}
		else if (exitOption == PAUSE) {
			inMenu = true;
		}

		MenuOption option = menu.menuEvents(window, event);
		switch (option) {
		case START:
			inMenu = false;
			break;
		case ONLINE:
			break;
		case EXIT:
			window.close();
			break;
		case PAUSE:
			inMenu = true;
			break;
		}
	}
}

void Game::handlePlayerMovement(Player& player1, Player& player2, float playerSpeed) 
{
	// player1 movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		player1.move(-playerSpeed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		player1.move(playerSpeed);
	}

	// player2 movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		player2.move(-playerSpeed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		player2.move(playerSpeed);
	}
}

void Game::handleGameInput(bool& inMenu) 
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		inMenu = true;
	}
}

void Game::drawGameObjects(sf::RenderWindow& window,
	const sf::Text& scoreText,
	const sf::RectangleShape& player1,
	const sf::RectangleShape& player2,
	const sf::CircleShape& ball,
	bool inMenu)
{
	if (!inMenu) window.draw(scoreText);

	window.draw(player1);
	window.draw(player2);
	window.draw(ball);
}