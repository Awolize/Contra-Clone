#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

int main()
{
  sf::View Box;
  Box.reset(sf::FloatRect(200, 200, 300, 200));
  Box.setCenter(sf::Vector2f(350, 300));

  sf::Texture texture;
  texture.loadFromFile("background2.png");
  sf::RectangleShape rectangle(sf::Vector2f(150, 80));
  sf::RenderWindow window(sf::VideoMode(1024, 768), "My window", 
			  sf::Style::Close | sf::Style::Resize);
  
  window.setVerticalSyncEnabled(true);

  // run the program as long as the window is open
  while (window.isOpen())
  {

    sf::Event event;
    while (window.pollEvent(event))
    {
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed)
	window.close();
    }

    window.clear(sf::Color::Blue);
    sf::Sprite background(texture);
    //background.setScale(3.0f, 1.0f);
    window.draw(rectangle);
    window.draw(background);
    window.display();
  }


  return 0;
}
