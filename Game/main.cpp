#include <SFML/Graphics.hpp>
// #include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include "Characters.h"
#include "Enemy.h"
#include "Entity.h"
#include "Player.h"
#include "Platform.h"
#include "Bullet.h"
#include "Lava.h"
#include "startScreen.h"
#include "gameDraw.h"
#include "gameUpdate.h"
#include <fstream>


using namespace std;

int main()
{
    // Init
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Contra", sf::Style::Close | sf::Style::Resize);
    sf::View menuView(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1024.0f, 768.0f));
    sf::View gameView(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1024.0f, 768.0f));

    window.setKeyRepeatEnabled(false);
    window.setVerticalSyncEnabled(true);
    int healthPoints{ 3 };
    vector<sf::Sprite> drawposhp;
    
    //    sf::Music music;
    //    music.openFromFile("music/level1.ogg");
    //    music.play();

    // Define Textures

    sf::Texture heart;
    heart.loadFromFile("images/inSovietRussia.png");

    sf::Sprite health;
    health.setTexture(heart);
    health.setScale(0.5f, 0.5f);
    
    entitySpawn();
    //playerSpawn();
    levelLavaSpawn();
    defineText();

    sf::Clock textTime;
    sf::Time elapsed;
    sf::Vector2f distance; //Distance between player and Enemy
    // Define Objects	
    float setview;
    float deltaTime = 0.0f;
    sf::Clock clock;
    bool menuScreen{ true };
    bool scoreScreen{ false };
    bool mainGameScreen{ false };
    bool viewHighscore{ false };

    // Main Game
    while (window.isOpen())
    {
	sf::Event event;
	while (window.pollEvent(event))
	{
	    switch (event.type)
	    {
	    case sf::Event::Closed:
		window.close();
		break;
	    case sf::Event::KeyPressed:
		if (scoreScreen)
		{
		    if (event.key.code == sf::Keyboard::Num1)
		    {
			scoreScreen = false;
			mainGameScreen = false;
			menuScreen = true;
			viewHighscore = false;
		    }
		    break;
		}
		if (menuScreen)
		{
		    window.setView(menuView);
		   
		    if (event.key.code == sf::Keyboard::Num1)
		    {
			scoreScreen = false;
			mainGameScreen = true;
			menuScreen = false;
			break;
		    }
		    if (event.key.code == sf::Keyboard::Num2)
		    {
			scoreScreen = true;
			mainGameScreen = false;
			menuScreen = false;
			break;
		    }
		    if (event.key.code == sf::Keyboard::Num3)
		    {
			window.close();
			break;
		    }
		}
		if (mainGameScreen)
		{
		    if (event.key.code == sf::Keyboard::Escape)
		    {
			scoreScreen = false;
			mainGameScreen = false;
			menuScreen = true;
			break;
		    }
		}
		break;
	    case sf::Event::Resized:
		cout << "New width:  " << event.size.width << endl;
		cout << "New height: " << event.size.height << endl;
		break;
	    case sf::Event::TextEntered:
		if (event.text.unicode < 128)
		    cout << "ASCII chaaracter typed: " << static_cast<char>(event.text.unicode) << endl;
	    }
	    break;
	}
	if (menuScreen)
	{
	    window.clear(sf::Color(0, 0, 0));
	    window.draw(startGameText);
	    window.draw(viewHighscoreText);
	    window.draw(exitGameText);
	    window.setView(menuView);
	    window.display();
	}
	if (scoreScreen)
	{
	    if (!viewHighscore)
	    {
		ifstream fin("Highscore.txt");
		string highscoreStr((istreambuf_iterator<char>(fin)),
				    (istreambuf_iterator<char>()));
		fin.close();
		highscoreText.setString(highscoreStr);
		highscoreText.setOrigin(highscoreText.getLocalBounds().left + highscoreText.getLocalBounds().width / 2.0f, 0);
		viewHighscore = true;
	    }
	    window.clear(sf::Color(0, 0, 0));
	    window.draw(backToMenuText);
	    window.draw(highscoreText);
	    window.setView(menuView);
	    window.display();
	}

	if (mainGameScreen)
	{

	    deltaTime = clock.restart().asSeconds();
	    if (deltaTime > 1.0f / 60.0f)
		deltaTime = 1.0f / 60.0f;

	    //-------------Update---------------
	    updateWholeGame();
	    //-------------View-----------------
	    setview = player.getPosition().x;
	    if (player.getPosition().x < 15)
		setview = 15;
	    gameView.setCenter(setview, 85);
	    window.setView(gameView);
	    //-------------Clear----------------
	    window.clear(sf::Color(200, 0, 0));
	    //-------------Draw-----------------
	    drawOnScreen(window, elapsed, textTime);

	    window.display();

/*
    sf::Clock textTime;
    sf::Time elapsed;
    sf::Vector2f distance; //Distance between player and Enemy
    // Define Objects	
    float setview;
    float deltaTime = 0.0f;
    sf::Clock clock;
    bool menuScreen{ true };
    bool scoreScreen{ false };
    bool mainGameScreen{ false };
    bool viewHighscore{ false };
*/
	}
    }
    window.close();
    // music.stop();
    return 0;
}
