#include "GameManager.h"
#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include <iostream>

void GameManager::runGame() {
	sf::RenderWindow window(sf::VideoMode(board.width, board.height), "SFML works!");

	// Initialization of UI, players, and ball
	UIManager ui;
	Player player1(sf::Color::Green, sf::Vector2f(0, 100));
	Player player2(sf::Color::White, sf::Vector2f(780, 100));
	Ball ball;
	int selectedItem = 0;
	int prevItem = 0;
	float playerSpeed = 0.05f;
	bool inMenu = true;

	std::thread scoreThread(&GameManager::onScoreChange, this, std::ref(ui)); // thread to manager score update

	ui.selectOpt(0, sf::Color::Red);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			windowHandler(window, event);
			ui.menuEvents(window, event);
		}

		// player movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			player1.move(-playerSpeed);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			player1.move(playerSpeed);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			player2.move(-playerSpeed);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			player2.move(playerSpeed);
		}
		// 

		window.clear();
		if (inMenu)
		{
			// TODO: Find other solution to show menu
			for (const auto& item : ui.getMenu())
			{
				window.draw(item);
			}
			//
		}
		else
		{
			window.draw(ui.scoreTxt);
			window.draw(player1.ping);
			window.draw(player2.ping);
			window.draw(ball.ball);

			ballCollision(ball.ball.getGlobalBounds(), player1.ping.getGlobalBounds(), player2.ping.getGlobalBounds());
			ball.move(ballPosX, ballPosY);
		}

		window.display();
	}

	scoreThread.join();
}

void GameManager::ballCollision(const sf::FloatRect& ball, const sf::FloatRect& player1, const sf::FloatRect& player2)
{
	if (ball.intersects(player1))
	{
		// manage lateral collision
		if (ball.left + ball.width <= player1.left || ball.left >= player1.left + player1.width) {
			ballPosX = -ballPosX;
		}
		else {
			ballPosX = -ballPosX;
			score1++;
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
			score2++;
		}
	}
	else if (ball.left <= board.left || ball.left + ball.width >= board.left + board.width)
	{
		ballPosX = -ballPosX;
	}
	else if (ball.top <= board.top || ball.top + ball.height >= board.top + board.height)
	{
		ballPosY = -ballPosY;
	}
}

void GameManager::windowHandler(sf::RenderWindow& window, sf::Event& event) {
	if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		window.close();
	}
}

void GameManager::onScoreChange(UIManager& ui) {
	int prevScore1 = score1;
	int prevScore2 = score2;
	while (true) {
		if (score1 != prevScore1 || score2 != prevScore2) {
			ui.setScore(score1, score2);
			prevScore1 = score1;
			prevScore2 = score2;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Espera un tiempo para verificar de nuevo
	}
}