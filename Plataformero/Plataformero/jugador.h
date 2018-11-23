#ifndef JUGADOR_H
#define JUGADOR_H

#include "personaje.h"

namespace juego
{
	class Jugador : public Personaje
	{
	public:
		Jugador(float x, float y);
		~Jugador();
		void mover();
	};
}

#endif