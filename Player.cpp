#include <SFML/Graphics.hpp>
#include "Player.h"
#include <iostream>

Player::Player(const sf::Color& color, const sf::Vector2f& pos)
{
	ping.setFillColor(color);
	ping.setSize(sf::Vector2f(20, 100));
	ping.setPosition(pos);
}

void Player::move(float y)
{
	float nextMove = ping.getPosition().y + y;
	if (nextMove < 500 && nextMove > 0)
	{
		ping.move(0, y);
	}
}

