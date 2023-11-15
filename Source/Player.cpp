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

