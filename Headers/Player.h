#include <SFML/Graphics.hpp>
#include "Ball.h"
#pragma once

class Player
{

public:
	const float speed = 0.5f;
	sf::RectangleShape shape;

	Player(const sf::Color& color, const sf::Vector2f& pos);
	//~Player();
	void move(float y);
	void autoMove(const Ball& ball);
};

