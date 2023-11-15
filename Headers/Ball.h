#pragma once
#include <SFML/Graphics.hpp>

class Ball
{
public:
	sf::CircleShape shape;

	Ball();
	//~Ball();
	void move(float posx, float posy);

};

