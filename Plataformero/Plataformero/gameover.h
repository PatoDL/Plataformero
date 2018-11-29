#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "pantalla.h"

#include "TGUI/TGUI.hpp"

namespace juego
{
	const int cantBotonesMenu = 2;

	enum BotonesGO
	{
		jugarGO,
		menuGO
	};

	class Gameover:public Pantalla
	{
		tgui::Button::Ptr botonGO[cantBotonesMenu];
	public:
		Gameover();
		~Gameover();
		void init();
		void checkInput();
		void update();
		void draw(Juego* juego);
		void deInit();
	};
}
#endif