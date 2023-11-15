#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "MenuOption.h"

class Menu
{
public:
    const std::vector<std::string> menuOpts = { "Start", "Online", "Exit" };

    Menu();

    std::vector<sf::Text> getMenu()
    {
        return menu;
    }

    void selectOpt(int option, const sf::Color& color);
    MenuOption menuEvents(sf::RenderWindow& window, const sf::Event& event);

private:
    sf::Font font;
    std::vector<sf::Text> menu;
    int selectedOption = 0;

    void createMenu();
};