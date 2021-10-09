#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/View.hpp>
#include <string>
#include <vector>
#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>

using std::cout, std::endl, std::string;

#define WIDTH  800
#define HEIGHT 500

int main(int argc, char* argv[])
{
	sf::Event event;
	sf::View view; view.setSize(WIDTH, HEIGHT);
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "TheLastResort-Client");

	/* ------------ Loading Assets into Vram ------------ */

	sf::Texture img_mic_on, img_mic_off, img_mic_err;
	img_mic_on.loadFromFile("assets/mic_on.png");
	img_mic_off.loadFromFile("assets/mic_off.png");
	img_mic_err.loadFromFile("assets/mic_err.png");

	/* -------------------------------------------------- */

	sf::Sprite mic_b(img_mic_err);
	mic_b.scale(0.5, 0.5);

	bool muted = true;
	bool HasMic = sf::SoundRecorder::isAvailable();
	if (HasMic)
	{
		mic_b.setTexture(img_mic_off);
		string MicName = sf::SoundRecorder::getDefaultDevice();
	}
	else
	{
		mic_b.setTexture(img_mic_err);
		string MicName = "No Microphone Detected";
	}

	auto adjustPositions = [&]()
	{
		auto win_size = window.getSize();
		view.reset(sf::FloatRect(0, 0, win_size.x, win_size.y));
		window.setView(view);

		auto mic_b_size = mic_b.getTexture()->getSize();
		mic_b.setPosition((win_size.x-mic_b_size.x)*1.f/4.f, (win_size.y-mic_b_size.y)*5.f/5.f);
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

		window.draw(mic_b);

		window.display();
	}
	return 0;
}
