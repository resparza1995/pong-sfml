#include <SFML/Graphics.hpp>
#pragma once

class Player
{

public:
	unsigned int id = 0;
	sf::RectangleShape ping;

	Player(const sf::Color& color, const sf::Vector2f& pos);
	//~Player();
	void move(float y);

private:

};

