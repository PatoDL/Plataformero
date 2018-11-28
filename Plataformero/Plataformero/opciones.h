#ifndef OPCIONES_H
#define OPCIONES_H

#include "pantalla.h"

#include "TGUI/TGUI.hpp"

using namespace tgui;

namespace juego
{
	class Opciones :public Pantalla
	{
		Button::Ptr setResolucion800x600;
		Button::Ptr atras;
	public:
		Opciones();
		~Opciones();
		void init();
		void checkInput();
		void update();
		void draw(Juego* juego);
		void deInit();
	};
}
#endif