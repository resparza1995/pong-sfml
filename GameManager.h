#pragma once

#include "UIManager.h"
#include "Player.h"
#include "Ball.h"
class GameManager
{
public:
    void runGame();
    void onScoreChange(UIManager& ui);

private:
    float ballPosX = 0.1f;
    float ballPosY = 0.1f;
    sf::FloatRect board{ 0, 0, 800, 600 };
    unsigned int score1 = 0;
    unsigned int score2 = 0;

    void ballCollision(const sf::FloatRect& ball, const sf::FloatRect& player, const sf::FloatRect& player2);
    void windowHandler(sf::RenderWindow& window, sf::Event& event);

};
