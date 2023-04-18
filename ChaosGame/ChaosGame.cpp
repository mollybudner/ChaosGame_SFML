#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>

using namespace sf;
using namespace std;

int main()
{
	sf::View view(sf::FloatRect(0.f, 0.f, 1920.f, 1080.f));
	VideoMode vm(1920, 1080);
	RenderWindow window(vm, "Chaos Game", Style::Fullscreen);

	Font font;
	font.loadFromFile("fonts/arial.ttf");

	Text text;
	text.setFont(font);

	//format intro text
	text.setString("Please click 3 times to create your triangle. Then, click anywhere to start the animation.");
	text.setCharacterSize(25);
	text.setFillColor(Color::White);
	FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	text.setPosition(1920 / 2.0f, 1080 / 20.0f);

	//vector for first 3 clicks
	vector<Vector2f> verticesVect;
	//vector of all points
	vector<Vector2f> pointsVect;

	while(window.isOpen())
	{
		Event event;
		while(window.pollEvent(event))
		{
			/*if(event.type == Event::KeyReleased)
			{
				acceptInput = true;
			}*/
		}

		window.setView(view);
		window.clear();
		//display stuff
		window.draw(text);
		window.display();
	}

	return 0;
}


//starting game need vertextVector and pointsVector
//3 clicks push back coordinates to vertex vector
//on 4th click, start game
//pick midpoint (100 at a time?) using 4th click, then push back to points vector
//draw vertices and points Rectangle r({1,1}); r.setPosition(pointsVect[i].x, pointsVect[i].y);
