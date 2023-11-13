#include "UIManager.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

UIManager::UIManager()
{
	font.loadFromFile("./Fonts/PixelifySans-Regular.ttf");
	setScore(0, 0);
	createMenu();
}


void UIManager::setScore(int score1, int score2)
{
	std::string txt = std::to_string(score1) + " - " + std::to_string(score2);
	scoreTxt.setFont(font);
	scoreTxt.setString(txt);
	scoreTxt.setCharacterSize(30);  // Tamaño del scoreTxto en puntos
	scoreTxt.setFillColor(sf::Color::White); // Color del texto
	scoreTxt.setPosition(400, 0);
}

void UIManager::createMenu()
{
	for (const auto& option : menuOpts)
	{
		sf::Text menuItem(option, font, 50);
		menuItem.setPosition(350, 170 + 50 * (menu.size()));
		menu.push_back(menuItem);
	}
}

void UIManager::selectOpt(int option, const sf::Color& color)
{
	menu[option].setFillColor(color);
}

void UIManager::menuEvents(sf::RenderWindow& window, const sf::Event& event)
{
    if (event.type == sf::Event::KeyReleased)
    {
        //std::cout << sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
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
            if (selectedOption < getMenu().size()-1) 
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
				std::cout << "START" << std::endl;
                break;

            case 1:
                std::cout << "ONLINE" << std::endl;
                break;

            case 2:
                window.close();
                break;
            }
        }
    }
}

