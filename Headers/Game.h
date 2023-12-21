#pragma once

#include "Menu.h"
#include "Player.h"
#include "Ball.h"

class Game
{
public:
    sf::Text scoreText;
    Game();
    void runGame();
    void scoreHandler(unsigned int scoreTo);

private:
    sf::Font font;
    float ballPosX = 0.1f;
    float ballPosY = 0.1f;
    sf::FloatRect board{ 0, 0, 800, 600 };
    unsigned int score1 = 0;
    unsigned int score2 = 0;

    unsigned int ballCollision(const sf::FloatRect& ball, const sf::FloatRect& player, const sf::FloatRect& player2);
    MenuOption windowHandler(sf::RenderWindow& window, sf::Event& event);
    void setScoreText(unsigned int score1, unsigned int score2);
    void drawMenu(sf::RenderWindow& window, Menu& menu);
    void handleMenu(sf::RenderWindow& window, Menu& menu, bool& inMenu);
    void drawGameObjects(sf::RenderWindow& window, const sf::Text& scoreText, const sf::RectangleShape& player1, const sf::RectangleShape& player2, const sf::CircleShape& ball, bool inMenu);
    void handleGameInput(bool& inMenu);
    void handlePlayerMovement(Player& player1, Player& player2, float playerSpeed);
};
