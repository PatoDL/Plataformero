#include "menu.h"

#include <iostream>
#include "TGUI/TGUI.hpp"

namespace juego
{
	enum EstadoBoton
	{
		apretado,
		suelto
	};

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

	static void signalHandler()
	{
		std::cout << "Button pressed" << std::endl;
	}


	void Menu::init()
	{
		for (int i = 0; i < cantBotones; i++)
		{
			button[i]=tgui::Button::create();
		}

		Font font;
		static tgui::Theme theme{ "res/assets/themes/BabyBlue.txt" };
		if (!font.loadFromFile("res/assets/fuentes/ANTQUAB.ttf"))
		{
			//error
		}
		String* texto[cantBotones];
		texto[0] = new String("Jugar");
		texto[1] = new String("Creditos");
		texto[2] = new String("Salir");
		Juego::getGui()->setFont(font);
		tgui::Layout2d* size = new tgui::Layout2d(Vector2f{ 120,60 });

		int distanciaBotones = 60;

		for (int i = 0; i < cantBotones; i++)
		{
			if (button[i] != NULL)
			{
				button[i]->setText(*texto[i]);

				button[i]->setRenderer(theme.getRenderer("Button"));
				//tgui::ButtonRenderer(theme.getRenderer("Button")).setBackgroundColor(sf::Color::Red);

				button[i]->setTextSize(40);
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

		button[0]->connect("pressed", [&]() { Juego::setEstadoActual(gameplay); });
		button[2]->connect("pressed", [&]() {Juego::setInGame(false); });
	}

	void Menu::checkInput()
	{
		if (Keyboard::isKeyPressed(Keyboard::N))
		{
			Juego::setEstadoActual(gameplay);
		}
	}

	void Menu::update()
	{
		
	}

	void Menu::draw(Juego* juego)
	{
		
	}

	void Menu::deInit()
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