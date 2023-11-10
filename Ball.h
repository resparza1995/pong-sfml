#pragma once
#include <SFML/Graphics.hpp>

class Ball
{
public:
	sf::CircleShape ball;

	Ball();
	//~Ball();
	void move(float posx, float posy);

};

