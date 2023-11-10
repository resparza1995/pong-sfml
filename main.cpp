#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Ball.h"

// game manager TODO: Hacer objeto GameManager
float ballPosX = 0.5f;
float ballPosY = 0.5f;
sf::FloatRect board(0, 0, 800, 600);

void ballCollision(sf::FloatRect ball, sf::FloatRect ping, sf::FloatRect pong);

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    sf::Vector2f posPlayer1(20, 100);
    sf::Vector2f posPlayer2(760, 100);
    Player player(sf::Color::Green, posPlayer1);
    Player player2(sf::Color::White, posPlayer2);
    Ball ball;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
        }

        window.clear();
        window.draw(player.ping);
        window.draw(player2.ping);
        window.draw(ball.ball);

        // Actualizar la posición de la bola
        ballCollision(ball.ball.getGlobalBounds(), player.ping.getGlobalBounds(), player2.ping.getGlobalBounds());
        ball.move(ballPosX, ballPosY);

        window.display();
    }

    return 0;
}

void ballCollision(sf::FloatRect ball, sf::FloatRect ping, sf::FloatRect pong)
{
    if (ball.intersects(ping) || ball.intersects(pong))
    {
        ballPosX = -ballPosX;
    }
    else if (ball.left <= board.left || ball.left + ball.width >= board.left + board.width) 
    {
        ballPosX = -ballPosX;
    }
    else if (ball.top <= board.top || ball.top + ball.height >= board.top + board.height) 
    {
        ballPosY = -ballPosY;
    }
}