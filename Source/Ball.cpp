#include "../Headers/Ball.h"
#include <SFML/Graphics.hpp>

Ball::Ball()
{
    shape.setRadius(10);
    shape.setFillColor(sf::Color::White);
    shape.setPosition(400, 100);
    //shape.setPosition(0, 0);
}

void Ball::move(float posx, float posy)
{
    shape.move(posx, posy);
}