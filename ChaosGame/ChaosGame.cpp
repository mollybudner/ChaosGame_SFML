#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main()
{
	sf::View view(sf::FloatRect(0.f, 0.f, 1920.f, 1080.f));
	VideoMode vm(1920, 1080);
	RenderWindow window(vm, "Chaos Game", Style::Default);

	bool paused = true;
	bool acceptInput = false;

	Font font;
	font.loadFromFile("fonts/arial.ttf");

	Text text;
	text.setFont(font);

	//Display intro text
	text.setString("Please click 3 times to create your triangle. Then, click anywhere to start the animation.");
	text.setCharacterSize(25);
	text.setFillColor(Color::White);
	FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	text.setPosition(1920 / 2.0f, 1080 / 20.0f);

	vector<double> coordinates;

	while(window.isOpen())
	{
		Event event;
		while(window.pollEvent(event))
		{
			if(event.type == Event::KeyReleased && !paused)
			{
				acceptInput = true;
			}
		}

		if(Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		if(event.type == sf::Event::MouseButtonPressed)
		{
			paused = false;
		}

		window.draw(text);
		window.display();
	}

	return 0;
}
