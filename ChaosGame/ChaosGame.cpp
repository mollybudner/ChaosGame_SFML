//Chaos Game by Molly Budner
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
	RenderWindow window(vm, "Chaos Game", Style::Default);

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
	vector<Vector2f> vertices;
	//vector of all points
	vector<Vector2f> points;

	while(window.isOpen())
	{
		Event event;
		while(window.pollEvent(event))
		{
			//handle window closing
			if(event.type == Event::Closed)
			{
				window.close();
			}
			//handle mouse button clicks
			if(event.type == sf::Event::MouseButtonPressed)
			{
				if(event.mouseButton.button == sf::Mouse::Left)
				{
					std::cout << "the left button was pressed" << std::endl;
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;
					if(vertices.size() < 3)
					{
						//fill vertices vector
						vertices.push_back(Vector2f({(float)event.mouseButton.x, (float)event.mouseButton.y}));
					}
					else
					{
						//fill points vector when vertices vector is full
						points.push_back(Vector2f({(float)event.mouseButton.x, (float)event.mouseButton.y}));
					}
				}
			}
		}

		if(points.size() > 0)
		{
			srand(time(0));
			//randomly select value from 0-2 to pick random vertex
			int randVertex = rand() % 3;
			int randX = vertices.at(randVertex).x;
			int randY = vertices.at(randVertex).y;
			int pointX = points.at(points.size() - 1).x;
			int pointY = points.at(points.size() - 1).y;

			//find midpoint and add to points vector
			Vector2f midpoint = (Vector2f{(randX + pointX) / 2,
					     (randY + pointY) / 2});
			points.push_back(midpoint);

			//Plot midpoints for game (fix me)
			CircleShape m(2);
			m.setPosition(midpoint);
			window.draw(m);
		}

		//close game with ESC key
		if(Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		window.setView(view);
		window.clear();

		//Draw game scene
		CircleShape r(2);
		for(size_t i = 0; i < vertices.size(); i++)
		{
			r.setPosition(Vector2f{vertices.at(i).x, vertices.at(i).y});
			window.draw(r);
		}

		//display stuff
		window.draw(text);
		window.display();
	}

	return 0;
}
