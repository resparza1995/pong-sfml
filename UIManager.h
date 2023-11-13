#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class UIManager
{
public:
    sf::Text scoreTxt;
    const std::vector<std::string> menuOpts = { "Start", "Online", "Exit" };

    UIManager();
    void setScore(int score1, int score2);
    
    std::vector<sf::Text> getMenu()
    {
        return menu;
    }

    void selectOpt(int option, const sf::Color& color);
    void menuEvents(sf::RenderWindow& window, const sf::Event& event);

private:
    sf::Font font;
    std::vector<sf::Text> menu;
    int selectedOption = 0;

    void createMenu();
};