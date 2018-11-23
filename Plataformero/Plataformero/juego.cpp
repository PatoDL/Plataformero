#include "juego.h"

#include <iostream>
#include "gameplay.h"

namespace Juego
{
	Juego::Juego()
	{
		_inGame = true;

		window = new RenderWindow(VideoMode(200, 200), "Plataformero");

		for (int i = 0; i < cantPantallas; i++)
		{
			pantalla[i] = NULL;
		}

		pantalla[0] = new Gameplay();
	}

	Juego::~Juego()
	{
		for (int i = 0; i < cantPantallas; i++)
		{
			delete pantalla[i];
		}
		delete window;
	}

	void Juego::setInGame(bool inGame)
	{
		_inGame = inGame;
	}

	bool Juego::getInGame()
	{
		return _inGame;
	}

	void Juego::ejecutar()
	{
		while (getInGame())
		{
			sf::Event event;
			while (window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window->close();
			}

			if (Keyboard::isKeyPressed(Keyboard::Enter))
			{
				setInGame(false);
			}

			window->clear();
			//window->draw();
			window->display();
		}
	}
}