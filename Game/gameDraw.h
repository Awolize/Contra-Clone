#ifndef GAMEDRAW_H
#define GAMEDRAW_H
#include <SFML/Graphics.hpp>
#include "Lava.h"
#include "startScreen.h"

void drawOnScreen(sf::RenderWindow window, sf::Time elapsed, sf::Clock textTime)    
{
    Lava lava;
    startscreen strscreen;
    //sf::Sprite level = lava.;
    window.draw(lava.getLevel1());

    elapsed = textTime.getElapsedTime();
    // cout << elapsed.asSeconds() << std::endl;

    if (elapsed.asSeconds() < 3.0)
	window.draw(strscreen.getText());

    for (Enemy& enemy : lava.getEnemyArray())
	enemy.Draw(window);

    for(Platform& platform : lava.getLavaArray())
	platform.Draw(window);

    //lava.getPlayer().Draw(window);

    for (Platform& platform : lava.getPlatformArray())
	platform.Draw(window);
    /*
    float currentPos{ player.getPosition().x };
    if (player.getPosition().x < 15)
	currentPos = 15;
    int tempHealthPos = currentPos - 512;
    for (int i{ 0 }; i < player.lives; i++)
    {
	health.setPosition(tempHealthPos + (i * 70), -300);
	drawposhp.push_back(health);
    }

    for (sf::Sprite& health : drawposhp)
    {
	window.draw(health);

    }
    drawposhp.erase(drawposhp.begin(), drawposhp.end());
    */

}


#endif
