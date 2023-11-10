#include <SFML/Graphics.hpp>
#include "Player.h"


Player::Player(sf::Color color, sf::Vector2f& pos)
{
    ping.setFillColor(color);
    ping.setSize(sf::Vector2f(20, 100));
    ping.setPosition(pos);
}