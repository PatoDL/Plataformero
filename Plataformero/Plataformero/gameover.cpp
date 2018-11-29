#include "gameover.h"

#include "TGUI/TGUI.hpp"
#include "juego.h"

namespace juego
{
	Gameover::Gameover()
	{
		for (int i = 0; i < cantBotonesMenu; i++)
		{
			botonGO[i] = NULL;
		}
	}


	Gameover::~Gameover()
	{
	}

	void Gameover::init()
	{
		for (int i = 0; i < cantBotonesMenu; i++)
		{
			botonGO[i] = tgui::Button::create();
		}

		String* texto[cantBotonesMenu];
		texto[0] = new String("Volver a Jugar");
		texto[1] = new String("Volver al Menu");
		tgui::Layout2d* size = new tgui::Layout2d(sf::Vector2f{ 120,60 });

		int distanciaBotones = 60;

		for (int i = 0; i < cantBotonesMenu; i++)
		{
			if (botonGO[i] != NULL)
			{
				botonGO[i]->setText(*texto[i]);
				botonGO[i]->setRenderer(Juego::getTheme().getRenderer("Button"));
				//tgui::ButtonRenderer(theme.getRenderer("Button")).setBackgroundColor(sf::Color::Red);

				botonGO[i]->setTextSize(40);
				if (texto[i]->getSize() > 5)
				{
					botonGO[i]->setSize(texto[i]->getSize() * 120 / 5, size->y);

					//logica de tama�o de botones basada en la cantidad de letras
					//5 letras - 120 ancho - regla de 3
				}
				else
				{
					botonGO[i]->setSize(*size);
				}
			}
		}
		for (int i = 0; i < cantBotonesMenu; i++)
		{
			if (botonGO[i] != NULL)
			{
				if (i > 0)
				{
					botonGO[i]->setPosition(Juego::getAnchoPantalla() / 2 - botonGO[i]->getSize().x / 2,
						botonGO[i - 1]->getPosition().y + botonGO[i]->getSize().y + distanciaBotones);
				}
				else
				{
					int y = 0;
					for (int i = 0; i < cantBotonesMenu; i++)
					{
						y += botonGO[i]->getSize().y;  //suma el tama�o de los botones y los espacios intermedios 
						if (i < cantBotonesMenu - 1)	  //para centrar la posicion de los botones
						{
							y += distanciaBotones;
						}
					}

					botonGO[i]->setPosition(Juego::getAnchoPantalla() / 2 - botonGO[i]->getSize().x / 2, Juego::getAltoPantalla() / 2 - y / 2);
				}
			}

			botonGO[jugarGO]->connect("pressed", [&]() {Juego::setEstadoActual(gameplay, false); });
			botonGO[menuGO]->connect("pressed", [&]() {Juego::setEstadoActual(menu, false); });

		}

		for (int i = 0; i < cantBotonesMenu; i++)
		{
			if (botonGO[i] != NULL)
			{
				Juego::getGui()->add(botonGO[i]);
			}
		}
	}

	void Gameover::checkInput()
	{

	}

	void Gameover::update()
	{

	}

	void Gameover::draw(Juego* juego)
	{

	}

	void Gameover::deInit()
	{
		for (int i = 0; i < cantBotonesMenu; i++)
		{
			if (botonGO[i] != NULL)
			{
				botonGO[i]->setVisible(false);
			}
		}
	}
}