#ifndef PAUSA_H
#define PAUSA_H

#include "pantalla.h"

#include "TGUI/TGUI.hpp"

using namespace tgui;

namespace juego
{
	const int cantBotonesPausa = 3;

	enum BotonesPausa
	{
		despausaB,
		menuB,
		reiniciarB
	};

	class Pausa :public Pantalla
	{
		Button::Ptr botonP[cantBotonesPausa];
	public:
		Pausa();
		~Pausa();
		void init();
		void checkInput();
		void update();
		void draw(Juego* juego);
		void deInit();
	};
}
#endif