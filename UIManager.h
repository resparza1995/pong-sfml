#pragma once
#include <SFML/Graphics.hpp>

class UIManager
{
public:
    sf::Text scoreTxt;
    UIManager();
    void setScore(int score1, int score2);

private:
    sf::Font font;
};