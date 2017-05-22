#ifndef STARTSCREEN_H
#define STARTSCREEN_H
#include <SFML/Graphics.hpp>
class startscreen
{
public:
    void defineText()
    {

	font.loadFromFile("images/Arial.ttf");

	text.setFont(font);
	text.setString("Level Lava");
	text.setCharacterSize(100);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);


	startGameText.setFont(font);
	startGameText.setString("(1) Start Game");
	startGameText.setCharacterSize(25);
	startGameText.setPosition(0, -300);
	startGameText.setFillColor(sf::Color::Red);


	viewHighscoreText.setFont(font);
	viewHighscoreText.setString("(2) View Highscore");
	viewHighscoreText.setCharacterSize(25);
	viewHighscoreText.setPosition(0, -250);
	viewHighscoreText.setFillColor(sf::Color::Red);


	exitGameText.setFont(font);
	exitGameText.setString("(3) Exit Game");
	exitGameText.setCharacterSize(25);
	exitGameText.setPosition(0, -200);
	exitGameText.setFillColor(sf::Color::Red);


	backToMenuText.setFont(font);
	backToMenuText.setString("(1) Menu");
	backToMenuText.setCharacterSize(25);
	backToMenuText.setPosition(0, -300);
	backToMenuText.setFillColor(sf::Color::Red);


	highscoreText.setFont(font);
	highscoreText.setCharacterSize(20);
	highscoreText.setPosition(0, -250);
	highscoreText.setFillColor(sf::Color::White);

	startGameText.setOrigin(startGameText.getLocalBounds().left + startGameText.getLocalBounds().width / 2.0f, 0);
	viewHighscoreText.setOrigin(viewHighscoreText.getLocalBounds().left + viewHighscoreText.getLocalBounds().width / 2.0f, 0);
	exitGameText.setOrigin(exitGameText.getLocalBounds().left + exitGameText.getLocalBounds().width / 2.0f, 0);
	backToMenuText.setOrigin(backToMenuText.getLocalBounds().left + backToMenuText.getLocalBounds().width / 2.0f, 0);
    }
    sf::Text getText() { return text; }

private:
    sf::Text text;
    sf::Font font;
    sf::Text startGameText;
    sf::Text viewHighscoreText;
    sf::Text exitGameText;
    sf::Text backToMenuText;
    sf::Text highscoreText;
};


#endif
