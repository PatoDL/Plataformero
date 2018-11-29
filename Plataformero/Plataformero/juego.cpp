#include "juego.h"

#include <iostream>

#include "gameplay.h"
#include "menu.h"
#include "opciones.h"
#include "pausa.h"
#include "gameover.h"
#include "creditos.h"

#include "SFML/Graphics.hpp"

namespace juego
{
	bool Juego::_inGame = true;

	tgui::Gui* Juego::gui = new tgui::Gui();

	tgui::Theme Juego::theme;

	sf::Font Juego::_fuente;

	sf::Text Juego::version;

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
		pantalla[gameover] = new Gameover();
		pantalla[creditos] = new Creditos();
		
		gui->setTarget(*window);
		theme.load("res/assets/themes/BabyBlue.txt");
		if (!_fuente.loadFromFile("res/assets/fuentes/ANTQUAB.ttf"))
		{
			//error
		}
		gui->setFont(_fuente);

		version.setString("v0.1");
		version.setCharacterSize(40);
		version.setFillColor(sf::Color::White);
		version.setFont(*Juego::getGui()->getFont());
		version.setPosition(static_cast<float> ((Juego::getAnchoPantalla() - version.getString().getSize() * 120 / 5)) - 20, 20.0f);
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
		pantalla[menu]->inicializar();
		pantalla[menu]->dibujar(juego);
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
				if (i == estadoActual && pantalla[i]!=NULL)
				{
					pantalla[i]->chequearInput();
					pantalla[i]->actualizar();
					if (estadoActual == pausa)
					{
						pantalla[gameplay]->dibujar(juego);
					}
					pantalla[i]->dibujar(juego);
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
				pantalla[estadoAnterior]->desinicializar();
			}
			if (estadoActual == gameplay)
			{
				if (estadoAnterior != pausa || reinicio)
				{
					pantalla[estadoActual]->inicializar();
				}
			}
			else
			{
				pantalla[estadoActual]->inicializar();
			}

			if ((estadoActual == menu&&estadoAnterior==gameover && reinicio))
			{
				pantalla[gameplay]->inicializar();
			}
			else if (estadoActual == menu && estadoAnterior == pausa)
			{
				pantalla[gameplay]->desinicializar();
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

	sf::Font Juego::getFuente()
	{
		return _fuente;
	}

	void Juego::dibujarVersion()
	{
		getWindow()->draw(version);
	}
}