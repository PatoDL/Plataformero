#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "pantalla.h"
#include "personaje.h"
#include "juego.h"
#include "mapa.h"

namespace juego
{
	class Gameplay : public Pantalla
	{
		Personaje* main;
		Personaje* enemy;
		View view;
		Mapa mapa;
	public:
		Gameplay();
		~Gameplay();
		void checkInput();
		void update();
		void draw(Juego* juego);
	};
}
#endif