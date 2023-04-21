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
			if(event.type == Event::Closed)
			{
				window.close();
			}
			if(event.type == sf::Event::MouseButtonPressed)
			{
				if(event.mouseButton.button == sf::Mouse::Left)
				{
					std::cout << "the left button was pressed" << std::endl;
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;
					if(vertices.size() <= 3)
					{
						vertices.push_back(Vector2f({(float)event.mouseButton.x, (float)event.mouseButton.y}));
					}
					else
					{
						points.push_back(Vector2f({(float)event.mouseButton.x, (float)event.mouseButton.y}));
					}
				}
			}
		}

		if(points.size() > 0)
		{
			srand(time(0));
			int randVertex = rand() % 3;
			Vector2f midpoint = ((vertices.at(randVertex).x + points.at(points.size() - 1).x / 2),
						(vertices.at(randVertex).y + points.at(points.size() - 1).y / 2));
			points.push_back(midpoint);
		}

		//close game with ESC key
		if(Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		window.setView(view);
		window.clear();

		//Draw game scene
		//RectangleShape r{Vector2f{4, 4}}; //width, height. Center unintialized.
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


//starting game need vertextVector and pointsVector
//3 clicks push back coordinates to vertex vector
//on 4th click, start game
//pick midpoint (100 at a time?) using 4th click, then push back to points vector
//draw vertices and points Rectangle r({1,1}); r.setPosition(pointsVect[i].x, pointsVect[i].y);
