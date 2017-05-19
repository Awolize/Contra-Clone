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


using namespace std;

int main()
{
    // Init
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Contra", sf::Style::Close | sf::Style::Resize);
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1024.0f, 768.0f));

    window.setKeyRepeatEnabled(false);
    window.setVerticalSyncEnabled(true);
    int healthPoints{3};
    vector<sf::Sprite> drawposhp;


    //    sf::Music music;
    //    music.openFromFile("music/level1.ogg");
    //    music.play();


    // Define Textures
    sf::Texture bullet;
    bullet.loadFromFile("images/bullet.png");

    sf::Texture playerTexture;
    playerTexture.loadFromFile("images/playerTexture.png");

    sf::Texture enemyTexture;
    enemyTexture.loadFromFile("images/Enemy.png");

    sf::Texture background;
    background.loadFromFile("images/1.png");

    sf::Texture heart;
    heart.loadFromFile("images/inSovietRussia.png");

    sf::Texture lava;
    lava.loadFromFile("images/lava.png");

    sf::Texture ground1;
    ground1.loadFromFile("images/level1ground.jpg");

    sf::Sprite level1;
    level1.setTexture(background);
    level1.setOrigin(500.0f, 300.0f);

    sf::Sprite health;
    health.setTexture(heart);
    health.setScale(0.5f, 0.5f);

    sf::Text text;
    sf::Font font;
    font.loadFromFile("images/SMLFATMARKER.ttf");
    text.setFont(font);
    text.setString("Level 1");
    text.setCharacterSize(100);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    sf::Text startGameText;
    font.loadFromFile("images/SMLFATMARKER.ttf");
    startGameText.setFont(font);
    startGameText.setString("(1) Start Game");
    startGameText.setCharacterSize(25);
    startGameText.setPosition(-95, -50);
    startGameText.setFillColor(sf::Color::Red);

    sf::Text viewHighscoreText;
    font.loadFromFile("images/SMLFATMARKER.ttf");
    viewHighscoreText.setFont(font);
    viewHighscoreText.setString("(2) View Highscore");
    viewHighscoreText.setCharacterSize(25);
    viewHighscoreText.setPosition(-95, 0);
    viewHighscoreText.setFillColor(sf::Color::Red);

    sf::Text exitGameText;
    font.loadFromFile("images/SMLFATMARKER.ttf");
    exitGameText.setFont(font);
    exitGameText.setString("(3) Exit Game");
    exitGameText.setCharacterSize(25);
    exitGameText.setPosition(-95, +50);
    exitGameText.setFillColor(sf::Color::Red);


    sf::Clock textTime;
    sf::Time elapsed;

    sf::Vector2f distance; //Distance between player and Enemy

    // Define Objects	
    float setview;
    std::vector<Enemy> enemyArray;
    enemyArray.push_back(Enemy(sf::Vector2f(700, 0), 100, 100, 10, 10, &enemyTexture, sf::Vector2i(3, 4), 0.2f, &bullet));
    enemyArray.push_back(Enemy(sf::Vector2f(1200, 0), 100, 100, 10, 10, &enemyTexture, sf::Vector2i(3, 4), 0.2f, &bullet));
    enemyArray.push_back(Enemy(sf::Vector2f(1500, 0), 100, 100, 10, 10, &enemyTexture, sf::Vector2i(3, 4), 0.2f, &bullet));
    enemyArray.push_back(Enemy(sf::Vector2f(2500, 0), 100, 100, 10, 10, &enemyTexture, sf::Vector2i(3, 4), 0.2f, &bullet));
    enemyArray.push_back(Enemy(sf::Vector2f(2900, 0), 100, 100, 10, 10, &enemyTexture, sf::Vector2i(3, 4), 0.2f, &bullet));
    enemyArray.push_back(Enemy(sf::Vector2f(3500, 0), 100, 100, 10, 10, &enemyTexture, sf::Vector2i(3, 4), 0.2f, &bullet));
    enemyArray.push_back(Enemy(sf::Vector2f(3900, 0), 100, 100, 10, 10, &enemyTexture, sf::Vector2i(3, 4), 0.2f, &bullet));
    enemyArray.push_back(Enemy(sf::Vector2f(4500, 0), 100, 100, 10, 10, &enemyTexture, sf::Vector2i(3, 4), 0.2f, &bullet));

    Player player(sf::Vector2f(200, -500), 100, 100, 400, 200, &playerTexture, sf::Vector2i(3, 4), 0.2f, &bullet);
    std::vector<Bullet> bulletVector;

    // Platform Vector Array
    std::vector<Platform> platformArray;
    //	Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
    platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(100, 400)));
    platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(200, 400)));
    platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(300, 400)));
    platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(400, 400)));
    platformArray.push_back(Platform(&lava, sf::Vector2f(100.0f, 250.0f), sf::Vector2f(500, 400)));
    platformArray.push_back(Platform(&lava, sf::Vector2f(100.0f, 250.0f), sf::Vector2f(600, 400)));
    platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(700, 400)));
    platformArray.push_back(Platform(&lava, sf::Vector2f(100.0f, 250.0f), sf::Vector2f(800, 400)));
    platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(900, 400)));
    platformArray.push_back(Platform(&lava, sf::Vector2f(100.0f, 250.0f), sf::Vector2f(1000, 400)));
    platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(1100, 400)));
    platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(1200, 400)));
    platformArray.push_back(Platform(&lava, sf::Vector2f(100.0f, 250.0f), sf::Vector2f(1300, 400)));
    platformArray.push_back(Platform(&lava, sf::Vector2f(100.0f, 250.0f), sf::Vector2f(1400, 400)));
    platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(1500, 400)));
    platformArray.push_back(Platform(&lava, sf::Vector2f(100.0f, 250.0f), sf::Vector2f(1600, 400)));
    platformArray.push_back(Platform(&lava, sf::Vector2f(100.0f, 250.0f), sf::Vector2f(1700, 400)));
    platformArray.push_back(Platform(&lava, sf::Vector2f(100.0f, 250.0f), sf::Vector2f(1800, 400)));
    platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(1900, 400)));
    platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(2000, 400)));
    platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(2500, 400)));
    platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(2600, 400)));
    platformArray.push_back(Platform(&lava, sf::Vector2f(100.0f, 250.0f), sf::Vector2f(2700, 400)));
    platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(2800, 400)));
    platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(2900, 400)));
    platformArray.push_back(Platform(&lava, sf::Vector2f(100.0f, 250.0f), sf::Vector2f(3000, 400)));
    platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(3100, 400)));
    platformArray.push_back(Platform(&lava, sf::Vector2f(100.0f, 250.0f), sf::Vector2f(3200, 400)));
    platformArray.push_back(Platform(&lava, sf::Vector2f(100.0f, 250.0f), sf::Vector2f(3300, 400)));
    platformArray.push_back(Platform(&lava, sf::Vector2f(100.0f, 250.0f), sf::Vector2f(3400, 400)));
    platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(3500, 400)));
    platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(3600, 400)));
    platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(3700, 400)));
    platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(3800, 400)));
    platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(3900, 400)));
    platformArray.push_back(Platform(&lava, sf::Vector2f(100.0f, 250.0f), sf::Vector2f(4000, 400)));
    platformArray.push_back(Platform(&lava, sf::Vector2f(100.0f, 250.0f), sf::Vector2f(4100, 400)));
    platformArray.push_back(Platform(&lava, sf::Vector2f(100.0f, 250.0f), sf::Vector2f(4200, 400)));
    platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(4300, 400)));
    platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(4400, 400)));
    platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(4500, 400)));

    float deltaTime = 0.0f;
    sf::Clock clock;

    bool menuScreen{ true };
    bool scoreScreen{ false };
    bool mainGameScreen{ false };
    // Main Game
    while (window.isOpen())
    {

	deltaTime = clock.restart().asSeconds();
	if (deltaTime > 1.0f / 60.0f)
	    deltaTime = 1.0f / 60.0f;

	sf::Event event;
	while (window.pollEvent(event))
	{
	    switch (event.type)
	    {
	    case sf::Event::Closed:
		window.close();
		break;
	    case sf::Event::KeyPressed:
		if (event.key.code == sf::Keyboard::Escape)
		    window.close();
		if (event.key.code == sf::Keyboard::Num1)
		{
		    scoreScreen = false;
		    mainGameScreen = true;
		    menuScreen = false;
		}
		if (event.key.code == sf::Keyboard::Num2)
		{
		    scoreScreen = true;
		    mainGameScreen = false;
		    menuScreen = false;
		}
		if (event.key.code == sf::Keyboard::Num3)
		    window.close();
		break;

	    case sf::Event::Resized:
		cout << "New width:  " << event.size.width << endl;
		cout << "New height: " << event.size.height << endl;
		break;
	    case sf::Event::TextEntered:
		if (event.text.unicode < 128)
		    cout << "ASCII chaaracter typed: " << static_cast<char>(event.text.unicode) << endl;
	    }
	}

	if (menuScreen == true)
	{
	    window.clear(sf::Color(0, 0, 0));
	    window.draw(startGameText);
	    window.draw(viewHighscoreText);
	    window.draw(exitGameText);
	    window.setView(view);
	    window.display();
	}

	if (scoreScreen == true)
	{
	    window.clear(sf::Color(0, 0, 0));
	    window.display();
	}

	if (mainGameScreen == true)
	{
	    //-------------Update---------------
	    player.Update(deltaTime);
	    sf::Vector2f direction;
	    for (Enemy & enemy : enemyArray)
	    {
		enemy.Update(deltaTime);
		for (Bullet & bullet : player.bulletArray)
		{
		    enemy.CheckIfHit(bullet);
		}

		for (Bullet & bullet : enemy.bulletArray)
		{
		    player.CheckIfHit(bullet);
		}

		for (Platform & platform : platformArray)
		{
		    Collider temp = enemy.GetCollider();
		    if (platform.GetCollider().CheckCollision(temp, direction))
		    {
			enemy.OnCollision(direction);
		    }
		}

		distance.x = abs(enemy.getPosition().x - player.getPosition().x);
		distance.y = abs(enemy.getPosition().y - player.getPosition().y);
		enemy.Intelligence(distance);

	    }
	    for (Platform & platform : platformArray)
	    {
		Collider temp = player.GetCollider();
		if (platform.GetCollider().CheckCollision(temp, direction))
		{
		    player.OnCollision(direction);
		}
	    }

	    if (player.getPosition().y > 1000) // Game Over
	    {

		if (player.end)
		{
		    textTime.restart();
		    player.end = false;
		}
		elapsed = textTime.getElapsedTime();
		text.setString("Game Over");
		text.setCharacterSize(200);
		window.draw(text);

		if (elapsed.asSeconds() >= 3.0)
		{
		    window.close();
		}
	    }

	    //-------------View-----------------
	    setview = player.getPosition().x;
	    if (player.getPosition().x < 15)
		setview = 15;
	    view.setCenter(setview, 85);
	    window.setView(view);
	    //-------------Clear----------------
	    window.clear(sf::Color(200, 0, 0));
	    //-------------Draw-----------------
	    window.draw(level1);

	    elapsed = textTime.getElapsedTime();
	    // cout << elapsed.asSeconds() << std::endl;

	    if (elapsed.asSeconds() < 3.0)
		window.draw(text);

	    for (Enemy& enemy : enemyArray)
		enemy.Draw(window);

	    player.Draw(window);

	    for (Platform& platform : platformArray)
		platform.Draw(window);

	    float currentPos {player.getPosition().x};
	    if (player.getPosition().x < 15)
		currentPos = 15;
	    int tempHealthPos = currentPos-512;
	    for(int i{0}; i < player.lives; i++)
	    {
		health.setPosition(tempHealthPos + (i*70), -300);
		drawposhp.push_back(health);
	    }

	    for( sf::Sprite& health :  drawposhp)
	    {
		window.draw(health);
		
	    }
	    drawposhp.erase(drawposhp.begin(),drawposhp.end());
       
	    window.display();
	}
    }

    

    window.close();
    // music.stop();

    return 0;
}

