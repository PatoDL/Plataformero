#include "juego.h"

#include <iostream>
#include "SFML/Graphics.hpp"
#include "gameplay.h"
#include "menu.h"
#include "opciones.h"
#include "pausa.h"

namespace juego
{
	bool Juego::_inGame = true;

	tgui::Gui* Juego::gui = new tgui::Gui();

	tgui::Theme Juego::theme;

	sf::Font Juego::mainFont;

	Pantalla* Juego::pantalla[cantPantallas];

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
		pantalla[opciones] = new Opciones();
		pantalla[pausa] = new Pausa();
		
		gui->setTarget(*window);
		theme.load("res/assets/themes/BabyBlue.txt");
		if (!mainFont.loadFromFile("res/assets/fuentes/ANTQUAB.ttf"))
		{
			//error
		}
		gui->setFont(mainFont);
	}

	Juego::~Juego()
	{
		for (int i = 0; i < cantPantallas; i++)
		{
			if (pantalla[i] != NULL)
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

				gui->handleEvent(event);
			}

			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				setInGame(false);
			}
			
			window->clear();

			for (int i = 0; i < cantPantallas; i++)
			{
				if (i == estadoActual)
				{
					pantalla[i]->checkInput();
					pantalla[i]->update();
					if (estadoActual == pausa)
					{
						pantalla[gameplay]->draw(juego);
					}
					pantalla[i]->draw(juego);
				}
			}
			
			gui->draw();

			window->display();

			resetClock();
		}
	}

	float Juego::getFrameTime() 
	{
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
		window->setSize({ _anchoPantalla, _altoPantalla });
	}
	void Juego::setAltoPantalla(unsigned int alto)
	{
		_altoPantalla=alto;
		window->setSize({ _anchoPantalla, _altoPantalla });
	}

	Estados Juego::getEstadoActual()
	{
		return estadoActual;
	}

	void Juego::setEstadoActual(Estados e, bool reinicio)
	{
		estadoAnterior = estadoActual;
		estadoActual = e;
		if (estadoActual != estadoAnterior)
		{
			if (e != pausa)
			{
				pantalla[estadoAnterior]->deInit();
			}
			if (estadoActual == gameplay)
			{
				if (estadoAnterior != pausa || reinicio)
				{
					pantalla[estadoActual]->init();
				}
			}
			else
			{
				pantalla[estadoActual]->init();
			}
			//estadoAnterior = estadoActual;
		}
	}

	tgui::Gui* Juego::getGui()
	{
		return gui;
	}

	tgui::Theme Juego::getTheme()
	{
		return theme;
	}

	sf::Font Juego::getFont()
	{
		return mainFont;
	}
}