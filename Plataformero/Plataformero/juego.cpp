#include "juego.h"

#include <iostream>
#include "gameplay.h"
#include "menu.h"

namespace juego
{
	bool Juego::_inGame = true;

	Time Juego::_dt;
	Clock Juego::_dClock;

	unsigned int Juego::_anchoPantalla = 1200;
	unsigned int Juego::_altoPantalla = 800;

	RenderWindow *Juego::window = new RenderWindow(VideoMode(_anchoPantalla, _altoPantalla), "Plataformero");

	Estados Juego::estadoActual = menu;
	Estados Juego::estadoAnterior = gameplay;

	Juego::Juego()
	{
		for (int i = 0; i < cantPantallas; i++)
		{
			pantalla[i] = NULL;
		}

		pantalla[gameplay] = new Gameplay();
		pantalla[menu] = new Menu();
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
		pantalla[menu]->init();
		pantalla[menu]->draw(juego);
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

			pantalla[menu]->update();
			for (int i = 0; i < cantPantallas; i++)
			{
				if (i == estadoActual)
				{
					pantalla[i]->checkInput();
					pantalla[i]->update();
					pantalla[i]->draw(juego);
				}
			}
			
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

	Estados Juego::getEstadoActual()
	{
		return estadoActual;
	}

	void Juego::setEstadoActual(Estados e)
	{
		estadoAnterior = estadoActual;
		estadoActual = e;
	}
}