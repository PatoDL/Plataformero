#include "juego.h"

#include <iostream>
#include "gameplay.h"

namespace juego
{
	Juego::Juego()
	{
		_inGame = true;

		window = new RenderWindow(VideoMode(800, 600), "Plataformero");

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

	RenderWindow* Juego::getWindow()
	{
		return window;
	}

	void Juego::setInGame(bool inGame)
	{
		_inGame = inGame;
	}

	bool Juego::getInGame()
	{
		return _inGame;
	}

	void Juego::ejecutar(Juego* juego)
	{
		while (getInGame())
		{
			sf::Event event;
			while (window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window->close();
			}

			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				setInGame(false);
			}
			
			window->clear();
			pantalla[0]->checkInput();
			pantalla[0]->update();
			pantalla[0]->draw(juego);
			window->display();
		}
	}

	float Juego::getFrameTime() 
	{
		static Clock dClock;
		float dt;
		dt=dClock.getElapsedTime().asSeconds();
		dClock.restart();
		return dt;
	}
}