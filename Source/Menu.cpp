#include "../Headers/Menu.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "../Headers/MenuOption.h"

Menu::Menu()
{
    font.loadFromFile("./Fonts/PixelifySans-Regular.ttf");
    createMenu();
}

void Menu::createMenu()
{
    for (const auto& option : menuOpts)
    {
        sf::Text menuItem(option, font, 50);
        menuItem.setPosition(350, 170 + 50 * (menu.size()));
        menu.push_back(menuItem);
    }
}

void Menu::selectOpt(int option, const sf::Color& color)
{
    menu[option].setFillColor(color);
}

MenuOption Menu::menuEvents(sf::RenderWindow& window, const sf::Event& event)
{
    if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::Up)
        {
            if (selectedOption > 0)
            {
                selectOpt(selectedOption, sf::Color::White);
                selectedOption--;
                selectOpt(selectedOption, sf::Color::Red);
            }
        }
        else if (event.key.code == sf::Keyboard::Down)
        {
            if (selectedOption < getMenu().size() - 1)
            {
                selectOpt(selectedOption, sf::Color::White);
                selectedOption++;
                selectOpt(selectedOption, sf::Color::Red);
            }
        }
        else if (event.key.code == sf::Keyboard::Enter)
        {
            switch (selectedOption)
            {
            case 0:
                return START;

            case 1:
                return ONLINE; //TODO: implement with sockets

            case 2:
                return EXIT;
            }
        }
    }
    return NONE;
}