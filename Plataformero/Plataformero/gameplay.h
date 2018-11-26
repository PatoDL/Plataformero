#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "pantalla.h"
#include "personaje.h"
#include "juego.h"

namespace juego
{
	class Gameplay : public Pantalla
	{
		Personaje* main;
		Personaje* enemy;
		View view;
	public:
		Gameplay();
		~Gameplay();
		void checkInput();
		void update();
		void draw(Juego* juego);
	};
}
#endif