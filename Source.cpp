#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Simulation");
	sf::RectangleShape slider(sf::Vector2f(100.0f, 200.0f));
	slider.setFillColor(sf::Color::Green);
	slider.setPosition(100, 100);

	while (window.isOpen())
	{
		sf::Event evnt;

		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed)
				window.close();
		}
	}
	window.clear();
	window.draw(slider);
	window.display();

	return 0;
}