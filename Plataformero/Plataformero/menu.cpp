#include "menu.h"

#include <iostream>

#include "TGUI/TGUI.hpp"

namespace juego
{
	Menu::Menu()
	{
		for (int i = 0; i < cantBotones; i++)
		{
			button[i] = NULL;
		}

		
	}


	Menu::~Menu()
	{
	}

	void Menu::inicializar()
	{
		for (int i = 0; i < cantBotones; i++)
		{
			button[i]=tgui::Button::create();
		}

		version.setString("v0.1");
		version.setCharacterSize(40);
		version.setFillColor(Color::White);
		version.setFont(*Juego::getGui()->getFont());
		version.setPosition((Juego::getAnchoPantalla()-version.getString().getSize()*120/5) - 20, 20);
		//version.setStyle(sf::Text::Bold | sf::Text::Underlined);

		String* texto[cantBotones];
		texto[0] = new String("Jugar");
		texto[1] = new String("Opciones");
		texto[2] = new String("Salir");
		tgui::Layout2d* size = new tgui::Layout2d(Vector2f{ 120,60 }); //tamaño estandar

		int distanciaBotones = 60;

		for (int i = 0; i < cantBotones; i++)
		{
			if (button[i] != NULL)
			{
				button[i]->setText(*texto[i]);

				button[i]->setRenderer(Juego::getTheme().getRenderer("Button"));
				//tgui::ButtonRenderer(theme.getRenderer("Button")).setBackgroundColor(sf::Color::Red);

				button[i]->setTextSize(40); //tamaño estandar
				if (texto[i]->getSize() > 5)
				{
					button[i]->setSize(texto[i]->getSize() * 120 / 5, size->y);

					//logica de tamaño de botones basada en la cantidad de letras
					//5 letras - 120 ancho - regla de 3
				}
				else
				{
					button[i]->setSize(*size);
				}
			}
		}

		for (int i = 0; i < cantBotones; i++)
		{
			if (button[i] != NULL)
			{
				if (i > 0)
				{
					button[i]->setPosition(button[i - 1]->getPosition().x + button[i - 1]->getSize().x + distanciaBotones, button[i - 1]->getPosition().y);
				}
				else
				{
					int x = 0;
					for (int i = 0; i < cantBotones; i++)
					{
						x += button[i]->getSize().x;  //suma el tamaño de los botones y los espacios intermedios 
						if (i < cantBotones - 1)	  //para centrar la posicion de los botones
						{
							x += distanciaBotones;
						}
					}
					
					button[i]->setPosition(Juego::getAnchoPantalla()/2-x/2, Juego::getAltoPantalla() / 3*2 - size->y / 2);
				}
			}
		}

		for (int i = 0; i < cantBotones; i++)
		{
			if (button[i] != NULL)
			{
				Juego::getGui()->add(button[i]);
			}
		}

		button[0]->connect("pressed", [&]() { Juego::setEstadoActual(gameplay,false); });
		button[1]->connect("pressed", [&]() { Juego::setEstadoActual(opciones,false); });
		button[2]->connect("pressed", [&]() {Juego::setInGame(false); });
	}

	void Menu::chequearInput()
	{
		
	}

	void Menu::actualizar()
	{
		
	}

	void Menu::dibujar(Juego* juego)
	{
		Juego::getWindow()->draw(version);
	}

	void Menu::desinicializar()
	{
		for (int i = 0; i < cantBotones; i++)
		{
			if (button[i] != NULL)
			{
				button[i]->setVisible(false);
			}
		}
	}
}