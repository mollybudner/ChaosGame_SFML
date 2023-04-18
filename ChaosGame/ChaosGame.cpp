#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main()
{
	VideoMode vm(1920, 1080);
	RenderWindow window(vm, "Chaos Game", Style::Default);

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
		textRect.top);
	text.setPosition(1920 / 2.0f, 1080 / 2.0f);


	while(window.isOpen())
	{
		window.draw(text);
		window.display();
	}

	return 0;
}
