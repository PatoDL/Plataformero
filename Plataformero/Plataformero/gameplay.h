#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "pantalla.h"
#include "personaje.h"
#include "juego.h"
#include "mapa.h"
#include "colisiones.h"
#include "TGUI/TGUI.hpp"

using namespace tgui;


namespace juego
{
	class Gameplay : public Pantalla
	{
		Personaje* main;
		Personaje* enemy;
		View view;
		Mapa* map;
		Button::Ptr pause;
		Colisiones colisiones;
	public:
		Gameplay();
		~Gameplay();
		void init();
		void checkInput();
		void update();
		void draw(Juego* juego);
		void deInit();
		void posicionarCamara();
	};
}
#endif