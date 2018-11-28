#ifndef MENU_H
#define MENU_H

#include "pantalla.h"
#include "juego.h"
#include "TGUI/TGUI.hpp"
#include "SFML/Graphics.hpp"

using namespace sf;

namespace juego
{
	class Menu:public Pantalla
	{
		Font font;
		tgui::Gui* gui;
		tgui::Button::Ptr button = tgui::Button::create();
		tgui::EditBox::Ptr editBox = tgui::EditBox::create();
	public:
		Menu();
		~Menu();
		void checkInput();
		void update();
		void draw(Juego* juego);
	};
}
#endif