#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "pantalla.h"
#include "personaje.h"
#include "juego.h"
#include "mapa.h"
#include "colisiones.h"

namespace juego
{
	class Gameplay : public Pantalla
	{
		Personaje* main;
		Personaje* enemy;
		View view;
		Mapa* map;
		Colisiones colisiones;
	public:
		Gameplay();
		~Gameplay();
		void init();
		void checkInput();
		void update();
		void draw(Juego* juego);
		void posicionarCamara();
	};
}
#endif