#ifndef MENU_H
#define MENU_H

#include "pantalla.h"

namespace juego
{
	class Menu:public Pantalla
	{
	public:
		Menu();
		~Menu();
		void checkInput();
		void update();
		void draw();
	};
}
#endif