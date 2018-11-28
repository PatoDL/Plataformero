#include "menu.h"

#include "TGUI/TGUI.hpp"

namespace juego
{
	Menu::Menu()
	{
		gui = new tgui::Gui();
		gui->setTarget(*Juego::getWindow());
		gui->add(button);
		gui->add(editBox, "Jugar");
		
		Font font;
		if(!font.loadFromFile("res/assets/fuentes/ANTQUAB.ttf"))
		{
			//error
		}

		gui->setFont(font);
		button->setPosition(Juego::getAnchoPantalla() / 2, Juego::getAnchoPantalla() / 2);
	}


	Menu::~Menu()
	{
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
		gui->draw();
	}
}