#include "UIManager.h"
#include <SFML/Graphics.hpp>
#include <string>

UIManager::UIManager()
{
	font.loadFromFile("./Fonts/PixelifySans-Regular.ttf");
	setScore(0, 0);
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
