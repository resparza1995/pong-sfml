#include "Ball.h"
#include <SFML/Graphics.hpp>

Ball::Ball()
{
    ball.setRadius(10);
    ball.setFillColor(sf::Color::White);
    ball.setPosition(400, 100);
}

void Ball::move(float posx, float posy)
{
    ball.move(posx, posy);
}