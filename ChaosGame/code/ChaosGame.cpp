#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main()
{
	VideoMode vm(1920, 1080);

	RenderWindow window(vm, "Chaos Game", Style::Default);

	Texture textureBackground;
	Font font;
	font.loadFromFile("fonts/arial.ttf");
	Text text;
	text.setFont(font);

	while(window.isOpen())
	{
		//Display intro text
		text.setString("Please click 3 times to create your triangle. Then, click anywhere to start the animation.");

	}

	return 0;
}
