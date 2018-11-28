#include "pausa.h"

#include <iostream>
#include "SFML/Graphics.hpp"
#include "TGUI/TGUI.hpp"
#include "juego.h"

namespace juego
{
	sf::String texto[cantBotonesPausa];
	RectangleShape fondo;

	Pausa::Pausa()
	{
		for (int i = 0; i < cantBotonesPausa; i++)
		{
			botonP[i] = NULL;
		}
	}


	Pausa::~Pausa()
	{
	}
	
	void Pausa::init()
	{
		
		fondo.setPosition({ 0,0 });
		fondo.setSize({ static_cast<float>( Juego::getAnchoPantalla()),static_cast<float>(Juego::getAltoPantalla()) });
		fondo.setFillColor(sf::Color(0, 0, 0, 170));

		for (int i = 0; i < cantBotonesPausa; i++)
		{
			botonP[i] = tgui::Button::create();
		}


		String* texto[cantBotonesPausa];
		texto[0] = new String("Continuar");
		texto[1] = new String("Menu");
		texto[2] = new String("Reiniciar");
		tgui::Layout2d* size = new tgui::Layout2d(sf::Vector2f{ 120,60 });

		int distanciaBotones = 60;

		for (int i = 0; i < cantBotonesPausa; i++)
		{
			if (botonP[i] != NULL)
			{
				botonP[i]->setText(*texto[i]);
				botonP[i]->setRenderer(Juego::getTheme().getRenderer("Button"));
				//tgui::ButtonRenderer(theme.getRenderer("Button")).setBackgroundColor(sf::Color::Red);

				botonP[i]->setTextSize(40);
				if (texto[i]->getSize() > 5)
				{
					botonP[i]->setSize(texto[i]->getSize() * 120 / 5, size->y);

					//logica de tamaño de botones basada en la cantidad de letras
					//5 letras - 120 ancho - regla de 3
				}
				else
				{
					botonP[i]->setSize(*size);
				}
			}
		}

		for (int i = 0; i < cantBotonesPausa; i++)
		{
			if (botonP[i] != NULL)
			{
				if (i > 0)
				{
					botonP[i]->setPosition(Juego::getAnchoPantalla() / 2 - botonP[i]->getSize().x / 2,
						botonP[i - 1]->getPosition().y + botonP[i]->getSize().y + distanciaBotones);
				}
				else
				{
					int y = 0;
					for (int i = 0; i < cantBotonesPausa; i++)
					{
						y += botonP[i]->getSize().y;  //suma el tamaño de los botones y los espacios intermedios 
						if (i < cantBotonesPausa - 1)	  //para centrar la posicion de los botones
						{
							y += distanciaBotones;
						}
					}

					botonP[i]->setPosition(Juego::getAnchoPantalla() / 2 - botonP[i]->getSize().x / 2, Juego::getAltoPantalla() / 2 -y/2);
				}
			}
		}

		for (int i = 0; i < cantBotonesPausa; i++)
		{
			if (botonP[i] != NULL)
			{
				Juego::getGui()->add(botonP[i]);
			}
		}
	}

	void Pausa::checkInput()
	{

	}

	void Pausa::update()
	{

	}

	void Pausa::draw(Juego* juego)
	{
		Juego::getWindow()->draw(fondo);
	}

	void Pausa::deInit()
	{
		for (int i = 0; i < cantBotonesPausa; i++)
		{
			if (botonP[i] != NULL)
			{
				botonP[i]->setVisible(false);
			}
		}
	}
}