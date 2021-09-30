#include <cmath>
#include <string>
#include <vector>
#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>

using std::cout, std::endl;

#define WIDTH  800
#define HEIGHT 500

int main(int argc, char* argv[])
{
	sf::Event event;
	sf::View view; view.setSize(WIDTH, HEIGHT);
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Test Window");

	/* ------------ Loading Assets into Vram ------------ */

	sf::Texture img_mic_on, img_mic_off, img_mic_err;
	img_mic_on.loadFromFile("assets/mic_on.png");
	img_mic_off.loadFromFile("assets/mic_off.png");
	img_mic_err. loadFromFile("assets/mic_err.png");

	/* -------------------------------------------------- */

	sf::Sprite mic_button(img_mic_err);

	auto adjustPositions = [&]()
	{
		auto winsize = window.getSize();
		unsigned x = winsize.x;
		unsigned y = winsize.y;

		view.setSize(x, y);
		window.setView(view);
		mic_button.setScale(.5f,.3f);
		mic_button.setPosition(x/2-100, y/2-100);
	};

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
			else if (event.type == sf::Event::Resized)
				adjustPositions();
		}

		window.clear(sf::Color(40,40,60,255));

		window.draw(mic_button);

		window.display();
	}
	return 0;
}
