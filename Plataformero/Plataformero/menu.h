#ifndef MENU_H
#define MENU_H

#include "pantalla.h"
#include "juego.h"
#include "TGUI/TGUI.hpp"
#include "SFML/Graphics.hpp"

using namespace sf;

namespace juego
{
	const int cantBotones = 3;

	class Menu:public Pantalla
	{
		tgui::Button::Ptr button[cantBotones];
		tgui::EditBox::Ptr editBox[cantBotones];
	public:
		Menu();
		~Menu();
		void inicializar();
		void chequearInput();
		void actualizar();
		void dibujar(Juego* juego);
		void desinicializar();
	};
}
#endif