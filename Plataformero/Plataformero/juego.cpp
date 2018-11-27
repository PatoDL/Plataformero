#include "juego.h"

#include <iostream>
#include "gameplay.h"

namespace juego
{
	Time Juego::_dt;
	Clock Juego::_dClock;

	unsigned int Juego::_anchoPantalla = 800;
	unsigned int Juego::_altoPantalla = 600;

	Juego::Juego()
	{
		_inGame = true;

		window = new RenderWindow(VideoMode(_anchoPantalla,_altoPantalla), "Plataformero");

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

			resetClock();
		}
	}

	float Juego::getFrameTime() 
	{
		//_dt=_dClock.getElapsedTime();
		return _dt.asSeconds();
	}

	void Juego::resetClock()
	{
		_dt=_dClock.restart();
	}

	int Juego::getAnchoPantalla()
	{
		return _anchoPantalla;
	}
	int Juego::getAltoPantalla()
	{
		return _altoPantalla;
	}

	void Juego::setAnchoPantalla(unsigned int ancho)
	{
		_anchoPantalla=ancho;
	}
	void Juego::setAltoPantalla(unsigned int alto)
	{
		_altoPantalla=alto;
	}
}