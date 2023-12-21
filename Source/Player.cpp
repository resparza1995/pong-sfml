#include <SFML/Graphics.hpp>
#include "../Headers/Player.h"
#include <iostream>

Player::Player(const sf::Color& color, const sf::Vector2f& pos)
{
	shape.setFillColor(color);
	shape.setSize(sf::Vector2f(20, 100));
	shape.setPosition(pos);
}

void Player::move(float y)
{
	float nextMove = shape.getPosition().y + y;
	if (nextMove < 500 && nextMove > 0)
	{
		shape.move(0, y);
	}
}

void Player::autoMove(const Ball& ball)
{
	sf::Vector2f ballPosition = ball.shape.getPosition();
	float targetY = ballPosition.y - shape.getSize().y / 2; // center the ball with the player

	// calculate position
	targetY = std::max(0.0f, std::min(500.0f - shape.getSize().y, targetY));
	float moveAmount = targetY - shape.getPosition().y;

	shape.move(0, moveAmount);
}

